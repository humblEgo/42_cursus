echo "kubernetes setup start!"

# Setup in /goinfre for 42
if [ -d "/goinfre" ]; then
	[ -z "${USER}" ] && export USER='whoami'

	mkdir -p /goinfre/$USER

	export MINIKUBE_HOME="/goinfre/$USER"
fi

# Get docker image from minikube
echo "Minikube start ..."
minikube start --vm-driver virtualbox
eval $(minikube docker-env)

echo "Get minikube ip"
MINIKUBE_IP=$(minikube ip)

# MINIKUBE_IP EDIT
# cp srcs/wordpress/files/wordpress.sql srcs/wordpress/files/wordpress-tmp.sql
# sed -i '' "s/MINIKUBE_IP/$MINIKUBE_IP/g" srcs/wordpress/files/wordpress-tmp.sql
# cp srcs/ftps/scripts/start.sh srcs/ftps/scripts/start-tmp.sh
# sed -i '' "s/MINIKUBE_IP/$MINIKUBE_IP/g" srcs/ftps/scripts/start-tmp.sh

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
echo "mysql..."
docker build -t ft_mysql srcs/mysql > /dev/null
echo "phpmyadmin..."
docker build -t ft_phpmyadmin srcs/phpmyadmin  > /dev/null

# echo "wordpress..."
# docker build -t ft_wordpress ./srcs/wordpress > /dev/null

echo "create deployment and service objects"
kubectl create -f srcs/yaml/mysql > /dev/null
kubectl create -f srcs/yaml/phpmyadmin > /dev/null

# echo "dashboard activate"
# https://minikube.sigs.k8s.io/docs/handbook/dashboard/
