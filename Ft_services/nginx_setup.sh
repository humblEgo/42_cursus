#!/bin/sh

#build nginx
docker build -t ft_nginx .

#create deployment of nginx
kubectl create -f srcs/yaml/nginx
