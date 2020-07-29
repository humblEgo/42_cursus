echo "clean kubenetes!"

echo "metalLB manifest delete"
# As clean namespace, other parts are deleted automatically.
kubectl delete -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml

echo "cd to nginx directory"
cd ./nginx
echo "ssl delete"
make clean
echo "nginx ssl secret delete"
kubectl delete secret nginxsecret
echo "nginx configmap create"
kubectl delete configmap nginxconfigmap
echo "nginx service delete"
kubectl delete services nginx
echo "nginx deployment delete"
kubectl delete deployment nginx


echo "Delete kubernetes objects: ftps"
kubectl delete services ftps
kubectl delete deployment ftps
kubectl delete configmap ftps-config


echo "Delete kubernetes objects: phpmyadmin"
kubectl delete services phpmyadmin
kubectl delete deployment phpmyadmin
kubectl delete configmap phpmyadmin


echo "Delete kubernetes objects: mysql"
kubectl delete services mysql
kubectl delete deployment mysql


echo "Delete kubernetes objects: wordpress"
kubectl delete services wordpress
kubectl delete deployment wordpress
# kubectl delete configmap wordpress


echo "Delete kubernetes objects: influxdb"
kubectl delete services influxdb
kubectl delete deployment influxdb
kubectl delete configmap influxdb


echo "Delete kubernetes objects: telegraf"
kubectl delete deployment telegraf
kubectl delete configmap telegraf


echo "Delete kubernetes objects: grafana"
kubectl delete services grafana
kubectl delete deployment grafana
kubectl delete configmap grafana
