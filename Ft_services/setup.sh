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
kubectl apply -f srcs/yaml/nginx > /dev/null

echo "after nginx setup"

# =============  docker build ================
echo "docker image build start"
echo "ftps..."
docker build -t ft_ftps srcs/ftps
echo "mysql..."
docker build -t ft_mysql srcs/mysql
echo "phpmyadmin..."
docker build -t ft_phpmyadmin srcs/phpmyadmin
echo "wordpress..."
docker build -t ft_wordpress srcs/wordpress
echo "influxDB..."
docker build -t ft_influxdb srcs/influxdb
echo "telegraf..."
docker build -t ft_telegraf srcs/telegraf
echo "grafana..."
docker build -t ft_grafana srcs/grafana


echo "create deployment and service objects"
kubectl create -f srcs/yaml/ftps
#kubectl apply -f srcs/ftps/ftps.yaml
kubectl create -f srcs/yaml/mysql
kubectl create -f srcs/yaml/phpmyadmin
kubectl create -f srcs/yaml/wordpress
kubectl create -f srcs/yaml/influxdb
kubectl create -f srcs/yaml/telegraf
kubectl create -f srcs/yaml/grafana


echo "Wordpress setup"
sh wordpress_setup.sh

echo "dashboard activate"
minikube dashboard&
# https://minikube.sigs.k8s.io/docs/handbook/dashboard/
