#!/bin/bash

echo "let's go!"

#set minikube_home when execute in cluster
export MINIKUBE_HOME=~/goinfre

minikube start --driver=virtualbox

minikube dashboard
echo "Excute dashboard"

#metric server는 물어보자.

echo "build Nginx"
sh nginx_setup.sh

echo "Install Success"
