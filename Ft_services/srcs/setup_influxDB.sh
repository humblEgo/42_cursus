echo "Setup influxDB.."

cd influxdb
docker build -t ft_influxdb . >> $LOG_PATH
kubectl create -f ./yaml/ >> $LOG_PATH

echo "Finish influxDB setup"