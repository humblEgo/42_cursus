echo "ftps service delete"
kubectl delete services ftps
echo "ftps deployment delete"
kubectl delete deployment ftps
sleep 2
echo "ftps image delete"
docker rmi ft_ftps