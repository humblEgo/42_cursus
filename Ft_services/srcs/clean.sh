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
sleep 2
echo "nginx image delete"
docker rmi ft_nginx:1.0

echo "phpmyadmin service delete"
kubectl delete services phpmyadmin
echo "phpmyadmin deployment delete"
kubectl delete deployment phpmyadmin
sleep 2
echo "phpmyadmin image delete"
docker rmi ft_phpmyadmin:latest


echo "mysql service delete"
kubectl delete services mysql
echo "mysql deployment delete"
kubectl delete deployment mysql
sleep 2
echo "mysql image delete"
docker rmi ft_mysql:latest

echo "wordpress service delete"
kubectl delete services wordpress
echo "wordpress deployment delete"
kubectl delete deployment wordpress
sleep 2
echo "wordpress image delete"
docker rmi wordpress:latest

echo "influxdb service delete"
kubectl delete services influxdb
echo "influxdb deployment delete"
kubectl delete deployment influxdb
sleep 2
echo "influxdb image delete"
docker rmi wordpress:latest