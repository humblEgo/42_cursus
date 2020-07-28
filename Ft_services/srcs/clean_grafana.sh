echo "grafana service delete"
kubectl delete services grafana
echo "grafana deployment delete"
kubectl delete deployment grafana
sleep 2
echo "grafana image delete"
docker rmi ft_grafana