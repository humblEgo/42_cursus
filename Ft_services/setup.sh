BLUE_GREEN="\033[36m"
echo -n "${BLUE_GREEN}"
echo "Setup start!"

#==============================================> Setting for 42seoul

if [ -d "/goinfre" ]; then
	[ -z "${USER}" ] && export USER='whoami'
	mkdir -p /goinfre/$USER
	export MINIKUBE_HOME="/goinfre/$USER"
fi

#==============================================> Set minikube, log_path, and dashboard
echo "Minikube start..."
minikube start --vm-driver virtualbox
eval $(minikube docker-env)

echo "Set log_path..."
export LOG_PATH="$PWD/log.txt"

echo "exec minikube dashboard"
minikube dashboard&

#==============================================> Setup services
cd srcs

./setup_metalLB.sh
./setup_nginx.sh
./setup_ftps.sh
./setup_mysql.sh
./setup_phpmyadmin.sh
./setup_influxDB.sh
./setup_telegraf.sh
./setup_grafana.sh
./setup_wordpress.sh

echo "Setup finished. Check log.txt if you need :)"