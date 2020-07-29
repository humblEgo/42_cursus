echo "Setup telegraf.."

cd telegraf
docker build -t ft_telegraf . >> $LOG_PATH
kubectl create -f ./yaml/ >> $LOG_PATH

echo "Finish telegraf setup"