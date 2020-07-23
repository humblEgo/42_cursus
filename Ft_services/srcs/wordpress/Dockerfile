FROM alpine
RUN apk update

RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli \
	php7-zlib php7-curl php7-mbstring php7-json php7-session
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz
RUN rm -f latest.tar.gz
RUN mv wordpress /etc/
COPY files/wp-config.php /etc/wordpress/

RUN apk add mysql-client
COPY files/wordpress.sql /tmp/
COPY scripts/init-wordpress.sh /tmp/

EXPOSE 5050

RUN rm -rf /var/cache/apk/*
COPY scripts/run.sh /tmp/
ENTRYPOINT ["sh", "/tmp/run.sh"]