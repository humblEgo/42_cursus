echo "Setup nginx.."

cd nginx
# "ssl create"
make keys
# make secret and configmap object
kubectl create secret tls nginxsecret --key ./nginx.key --cert ./nginx.crt >> $LOG_PATH
kubectl create configmap nginxconfigmap --from-file=default.conf >> $LOG_PATH

docker build -t ft_nginx:1.0 . >> $LOG_PATH
kubectl create -f ./yaml/ >> $LOG_PATH

echo "Finish nginx setup"