BLUE_GREEN="\033[36m"
echo -n "${BLUE_GREEN}"
echo "Setup start!"

# Setup in /goinfre for 42
if [ -d "/goinfre" ]; then
	[ -z "${USER}" ] && export USER='whoami'
	mkdir -p /goinfre/$USER
	export MINIKUBE_HOME="/goinfre/$USER"
fi

echo "Set log_path..."
export LOG_PATH="$PWD/log.txt"

echo "Minikube start..."
minikube start --vm-driver virtualbox
eval $(minikube docker-env)

cd srcs
# =============  metalLB setup ================
echo "metalLB.."
./setup_metalLB.sh

# kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml > $LOG_PATH
# kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml >> $LOG_PATH
# # On first install only
# kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)" >> $LOG_PATH
# cd srcs/yaml/metallb
# export MINIKUBE_IP=$(minikube ip)
# sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./metallb-config_format.yaml > ./metallb-config.yaml
# kubectl apply -f ./metallb-config.yaml >> $LOG_PATH
# cd ../../..
# echo "finish metalLB setup"

# =============  nginx setup   ================
./setup_nginx.sh
# echo "nginx.."
# cd srcs/nginx
# # "ssl create"
# make keys
# # make secret and configmap object
# kubectl create secret tls nginxsecret --key ./nginx.key --cert ./nginx.crt >> $LOG_PATH
# kubectl create configmap nginxconfigmap --from-file=default.conf >> $LOG_PATH

# cd ../..

# docker build -t ft_nginx:1.0 srcs/nginx >> $LOG_PATH
# kubectl create -f srcs/yaml/nginx >> $LOG_PATH
# echo "finish nginx setup"

echo "exec minikube dashboard"
minikube dashboard&

# echo "docker image build start(without wordpress)"
# echo "ftps..."
# docker build -t ft_ftps srcs/ftps >> $LOG_PATH
# echo "mysql..."
# docker build -t ft_mysql srcs/mysql >> $LOG_PATH
# echo "phpmyadmin..."
# docker build -t ft_phpmyadmin srcs/phpmyadmin >> $LOG_PATH
# echo "influxDB..."
# docker build -t ft_influxdb srcs/influxdb >> $LOG_PATH
# echo "telegraf..."
# docker build -t ft_telegraf srcs/telegraf >> $LOG_PATH
# echo "grafana..."
# docker build -t ft_grafana srcs/grafana >> $LOG_PATH

# echo "create deployment and service objects(without wordpress)"
# kubectl create -f srcs/yaml/ftps >> $LOG_PATH
# kubectl create -f srcs/yaml/mysql >> $LOG_PATH
# kubectl create -f srcs/yaml/phpmyadmin >> $LOG_PATH
# kubectl create -f srcs/yaml/influxdb >> $LOG_PATH
# kubectl create -f srcs/yaml/telegraf >> $LOG_PATH
# kubectl create -f srcs/yaml/grafana >> $LOG_PATH

# # =============  wordpress setup  ================
# echo "-------------------------------Set wordpress--------------------------------------"

# kubectl create -f srcs/yaml/wordpress/wordpress-service.yaml >> $LOG_PATH
# cd ./srcs/wordpress/files
# # external ip가 아직 할당 안되어서 <pending> 이면 할당 될 때 까지 반복
# kubectl get services | grep wordpress | awk '{print $4}' > WORDPRESS_IP
# export WORDPRESS_IP=$(cat < WORDPRESS_IP)
# export PENDING=\<pending\>
# until [ $WORDPRESS_IP != $PENDING ]
# do
# 	echo "try to get WORDPRESS_IP"
# 	kubectl get services | grep wordpress | awk '{print $4}' > WORDPRESS_IP
# 	export WORDPRESS_IP=$(cat < WORDPRESS_IP)
# 	sleep 1
# done
# rm WORDPRESS_IP

# sed "s/WORDPRESS_IP/$WORDPRESS_IP/g" ./data/wordpress.sql > ./wordpress.sql
# sed "s/WORDPRESS_IP/$WORDPRESS_IP/g" ./data/wp-config.php > ./wp-config.php

# cd ..
# docker build -t ft_wordpress . >> $LOG_PATH
# kubectl create -f ../yaml/wordpress/wordpress-deployment.yaml >> $LOG_PATH
# sleep 5

# kubectl get pods | grep wordpress | awk '{print $1}' > WORDPRESS_POD
# export WORDPRESS_POD=$(cat < WORDPRESS_POD)
# kubectl cp wordpress.sql $WORDPRESS_POD:/tmp/
# kubectl cp wp-config.php $WORDPRESS_POD:/etc/wordpress/
# rm WORDPRESS_POD
# echo "init-wordpress"
# echo "wordpress pod : $WORDPRESS_POD"
# kubectl exec $WORDPRESS_POD -- tmp/init-wordpress.sh

# cd ../../

# echo "Setting finished"
