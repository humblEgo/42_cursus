echo "Setup phpmyadmin.."

cd phpmyadmin
docker build -t ft_phpmyadmin . >> $LOG_PATH
kubectl create -f ./yaml/ >> $LOG_PATH

echo "Finish phpmyadmin setup"