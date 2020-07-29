echo "Setup mySQL.."

cd mysql
docker build -t ft_mysql . >> $LOG_PATH
kubectl create -f ./yaml/ >> $LOG_PATH

echo "Finish mySQL setup"