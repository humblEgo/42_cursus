echo "clean kubenetes!"

echo "metalLB manifest delete"
# As clean namespace, other parts are deleted automatically.
kubectl delete -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml

echo "nginx ssl delete"
cd nginx
make clean
cd ..
sleep 2

SERVICE_LIST="nginx ftps grafana influxdb mysql nginx phpmyadmin telegraf wordpress"

for SERVICE in $SERVICE_LIST
do
    echo "Clean $SERVICE"
    kubectl delete -f ./$SERVICE/yaml > /dev/null 2>&1
done
