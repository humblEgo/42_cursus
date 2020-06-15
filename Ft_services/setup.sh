#!/bin/sh

# Ensure docker and minikube are installed
if ! which docker >/dev/null 2>&1 ||
	! which minikube >/dev/null 2>&1
then
	echo Please install Docker and Minikube
	exit 1
fi

if [ "$1" = "delete" ]
then
	kubectl delte -k srcs
elif [ "$1" = "apply" ]
then
	kubectl apply -k srcs #k option means directoryman bonda
else
	#only for 42
	export MINIKUBE_HOME="/sgoinfre/goinfre/ft_service/minikube/" #where is it used?

	# minikube apiserver setup
	minikube start --vm-driver=virtualbox \
		--cpus 3 --disk-size=30000mb --memory=3000mb \  #if cpu era changed, error. why?
		--extra-config=apiserver.service-node-port-range=1-31000 #check needed.

	#enable nginx ingress controller
	minikube addons enable ingress  #ingress check
	minikube addons enable metrics-server #metris-server is monitoring tool

	export MINIKUBE_IP=$(minikube ip) #<== minikube ip
