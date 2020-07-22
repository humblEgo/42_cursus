echo "kubernetes setup start!"

# Get docker image from local to minikube
eval $(minikube docker-env)

# Setup in /goinfre for 42
if [ -d "/goinfre" ]; then
	[ -z "${USER}" ] && export USER='whoami'

	mkdir -p /goinfre/$USER

	export MINIKUBE_HOME="/goinfre/$USER"
fi

echo "Minikube start ..."
minikube start --vm-driver virtualbox --extra-config=apiserver.service-node-port-range=21-32767 > /dev/null

echo "Get minikube ip"
MINIKUBE_IP=$(minikube ip)

# MINIKUBE_IP EDIT
# cp srcs/wordpress/files/wordpress.sql srcs/wordpress/files/wordpress-tmp.sql
# sed -i '' "s/MINIKUBE_IP/$MINIKUBE_IP/g" srcs/wordpress/files/wordpress-tmp.sql
# cp srcs/ftps/scripts/start.sh srcs/ftps/scripts/start-tmp.sh
# sed -i '' "s/MINIKUBE_IP/$MINIKUBE_IP/g" srcs/ftps/scripts/start-tmp.sh


# =============  metalLB setup  ================
echo "metalLB.."
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
# On first install only
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
cd srcs/metallb
kubectl apply -f config.yaml

# =============  nginx setup  ================
echo "fieldPath: status.hostIP"
cd ../nginx
# "ssl create"
make keys
# "nginx ssl secret create"
kubectl create secret tls nginxsecret --key /Users/iwoo/Desktop/nginx.key --cert /Users/iwoo/Desktop/nginx.crt > /dev/null
# "nginx configmap create"
kubectl create configmap nginxconfigmap --from-file=default.conf > /dev/null

# =============  docker build  ================
echo "docker image build start"
echo "nginx..."
docker build -t ft_nginx:1.0 . > /dev/null
echo "mysql..."
docker build -t ft_mysql ./srcs/mysql > /dev/null
echo "phpmyadmin..."
docker build -t ft_phpmyadin ./srcs/phpmyadmin > /dev/null

# echo "wordpress..."
# docker build -t ft_wordpress ./srcs/wordpress > /dev/null

echo "create deployment and service objects"
kubectl apply -f nginx.yaml > /dev/null
kubectl create -f ./srcs/yaml/mysql > /dev/null
kubectl create -f ./srcs/yaml/phpmyadmin > /dev/null


# echo "dashboard activate"
# https://minikube.sigs.k8s.io/docs/handbook/dashboard/
