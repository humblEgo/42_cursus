#!/bin/sh

mkdir -p /var/run/nginx

ssh-keygen -A
adduser --disabled-password iwoo
echo "iwoo:iwoo123" | chpasswd
/usr/sbin/sshd

nginx -g "daemon off;"