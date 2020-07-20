
echo "kubernetes setup start!"

echo "metalLB.."
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
# On first install only
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
cd srcs/metallb
kubectl apply -f config.yaml

echo "fieldPath: status.hostIP"
echo "cd to nginx directory"
cd ../nginx
echo "ssl create"
make keys
echo "nginx ssl secret create"
kubectl create secret tls nginxsecret --key /Users/iwoo/Desktop/nginx.key --cert /Users/iwoo/Desktop/nginx.crt
echo "nginx configmap create"
kubectl create configmap nginxconfigmap --from-file=default.conf
echo "nginx image build"
docker build -t iwoo_nginx:1.0 .
echo "nginx deployment"
kubectl apply -f nginx.yaml





# echo "dashboard activate"
# https://minikube.sigs.k8s.io/docs/handbook/dashboard/