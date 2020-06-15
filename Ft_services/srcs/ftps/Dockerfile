FROM alpine:3.9

RUN apk add --no-cache vsftpd openssl

COPY vsftpd.conf  /etc/vsftpd/vsftpd.conf
COPY entrypoint /

EXPOSE 20 21 30020 30021

ENTRYPOINT sh /entrypoint
