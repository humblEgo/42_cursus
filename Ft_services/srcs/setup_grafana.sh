echo "Setup grafana.."

cd grafana
docker build -t ft_grafana . >> $LOG_PATH
kubectl create -f ./yaml/ >> $LOG_PATH

echo "Finish grafana setup"