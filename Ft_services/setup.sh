echo "kubernetes setup start!"

# Setup in /goinfre for 42
if [ -d "/goinfre" ]; then
	[ -z "${USER}" ] && export USER='whoami'

	mkdir -p /goinfre/$USER
	
#	brew install minikube
	export MINIKUBE_HOME="/goinfre/$USER"
fi

# Get docker image from minikube
echo "Minikube start ..."
minikube start --vm-driver virtualbox --extra-config=apiserver.service-node-port-range=20-32767 > /dev/null
eval $(minikube docker-env)

echo "Get minikube ip"
MINIKUBE_IP=$(minikube ip)

# =============  metalLB setup  ================
echo "metalLB.."
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml > /dev/null
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml > /dev/null
# On first install only
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
cd srcs/metallb
kubectl apply -f config.yaml > /dev/null

# =============  nginx setup  ================
echo "fieldPath: status.hostIP"
cd ../nginx
# "ssl create"
make keys
# "nginx ssl secret create"
kubectl create secret tls nginxsecret --key ./nginx.key --cert ./nginx.crt > /dev/null
# "nginx configmap create"
kubectl create configmap nginxconfigmap --from-file=default.conf > /dev/null
# nginx docker build
cd ..
cd ..
echo $(PWD)
docker build -t ft_nginx:1.0 srcs/nginx > /dev/null
kubectl create -f srcs/yaml/nginx > /dev/null

echo "after nginx setup"
echo "exec minikube dashboard"
minikube dashboard&

# =============  docker build ================
echo "docker image build start"
# echo "ftps..."
# docker build -t ft_ftps srcs/ftps
echo "mysql..."
docker build -t ft_mysql srcs/mysql
echo "phpmyadmin..."
docker build -t ft_phpmyadmin srcs/phpmyadmin
echo "wordpress..."
docker build -t ft_wordpress srcs/wordpress
# echo "influxDB..."
# docker build -t ft_influxdb srcs/influxdb
# echo "telegraf..."
# docker build -t ft_telegraf srcs/telegraf
# echo "grafana..."
# docker build -t ft_grafana srcs/grafana


echo "create deployment and service objects"
# kubectl create -f srcs/yaml/ftps
kubectl create -f srcs/yaml/mysql
kubectl create -f srcs/yaml/phpmyadmin
kubectl create -f srcs/yaml/wordpress
# kubectl create -f srcs/yaml/influxdb
# kubectl create -f srcs/yaml/telegraf
# kubectl create -f srcs/yaml/grafana


# =============  wordpress setup  ================

cd ./srcs/wordpress/files

echo "-------------------------------Set wordpress--------------------------------------"
# IP 처리하는 부분
# external ip가 아직 할당안되서 <pending> 이면 할당 될 때 까지 반복
kubectl get services | grep wordpress | awk '{print $4}' > WORDPRESS_IP
export WORDPRESS_IP=$(cat < WORDPRESS_IP)
export PENDING=\<pending\>
until [ $WORDPRESS_IP != $PENDING ]
do
	kubectl get services | grep wordpress | awk '{print $4}' > WORDPRESS_IP
	export WORDPRESS_IP=$(cat < WORDPRESS_IP)
done

# 파드 부분
kubectl get pods | grep wordpress | awk '{print $1}' > WORDPRESS_POD
export WORDPRESS_POD=$(cat < WORDPRESS_POD)
sed "s/WORDPRESS_IP/$WORDPRESS_IP/g" ./data/wordpress.sql > ./wordpress.sql
sed "s/WORDPRESS_IP/$WORDPRESS_IP/g" ./data/wp-config.php > ./wp-config.php
kubectl cp wordpress.sql $WORDPRESS_POD:/tmp/
kubectl cp wp-config.php $WORDPRESS_POD:/etc/wordpress/
echo "init-wordpress"
echo "wordpress pod : $WORDPRESS_POD"
kubectl exec $WORDPRESS_POD -- sh /tmp/init-wordpress.sh
rm WORDPRESS_IP
rm WORDPRESS_POD
cd ..
docker build -t ft_wordpress . > /dev/null

cd ../../

echo "Setting finished"
