BLUE_GREEN="\033[36m"
echo -n "${BLUE_GREEN}"

echo "%s" "
  ______ _______ _____ ______ _______      _______ _____ ______  _____ 
 |  ____|__   __/ ____|  ____|  __ \ \    / /_   _/ ____|  ____|/ ____|
 | |__     | | | (___ | |__  | |__) \ \  / /  | || |    | |__  | (___  
 |  __|    | |  \___ \|  __| |  _  / \ \/ /   | || |    |  __|  \___ \ 
 | |       | |  ____) | |____| | \ \  \  /   _| || |____| |____ ____) |
 |_|       |_| |_____/|______|_|  \_\  \/   |_____\_____|______|_____/ 
"
echo "Setup start!"

#===============================================>	Setting for 42seoul

if [ -d "/goinfre" ]; then
	[ -z "${USER}" ] && export USER='whoami'
	mkdir -p /goinfre/$USER
	export MINIKUBE_HOME="/goinfre/$USER"
fi

#===============================================>	if argv is 'clean', delete all without PV

if [ $1 = 'clean' ]
then
	./srcs/clean.sh
	exit
fi

#===============================================>	if argv is 'test_restore', kill apps to test restore

if [ $1 = 'test_restore' ]
then
	./srcs/app_restore_test.sh
	exit
fi

#===============================================>	Set minikube, log_path, and dashboard
echo "Minikube start..."
minikube start --vm-driver virtualbox
eval $(minikube docker-env)

echo "Set log_path..."
export LOG_PATH="$PWD/log.txt"
echo "Log start~" > $LOG_PATH

echo "exec minikube dashboard"
minikube dashboard&

#==========-====================================>	Setup services
cd srcs

SERVICE_LIST="metalLB nginx ftps mysql phpmyadmin influxDB telegraf grafana wordpress"

for SERVICE in $SERVICE_LIST
do
	./setup_$SERVICE.sh
done

echo "Setup finished. Check log.txt if you need :)"
