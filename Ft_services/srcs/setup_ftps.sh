echo "Setup FTPS..."
cd ftps
docker build -t ft_ftps . >> $LOG_PATH
kubectl create -f ./yaml/ >> $LOG_PATH
echo "Finish FTPS setup"