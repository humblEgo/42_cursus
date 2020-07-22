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
echo "nginx deployment delete"
kubectl delete -f nginx.yaml
sleep 5
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