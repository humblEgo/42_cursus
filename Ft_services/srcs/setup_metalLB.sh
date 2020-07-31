echo "Setup metalLB..."

cd metallb
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml >> $LOG_PATH
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml >> $LOG_PATH
# On first install only
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)" >> $LOG_PATH
export MINIKUBE_IP=$(minikube ip)
sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" yaml/metallb-config_format.yaml > ./yaml/metallb-config.yaml
kubectl apply -f yaml/metallb-config.yaml >> $LOG_PATH

echo "Finish metalLB setup"