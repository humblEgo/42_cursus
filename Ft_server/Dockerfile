# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwoo <iwoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/16 00:29:41 by iwoo              #+#    #+#              #
#    Updated: 2020/04/17 01:12:47 by iwoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM		debian:buster
MAINTAINER	iwoo@student.42seoul.kr

# Update all 
RUN	apt-get update

# Install nginx && mysql
RUN	apt-get install -y nginx && \
		apt-get install -y mariadb-server && \
		apt-get install -y php-fpm php-mysql

COPY srcs/nginx_setting /etc/nginx/sites-available/localhost

RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost

# Set SSL
RUN apt-get install -y libssl-dev openssl && \
		openssl req -x509 -nodes -days 365 -subj "/C=CA/ST=QC/O=Company, Inc./CN=localhost" \
		 -addext "subjectAltName=DNS:localhost" -newkey rsa:2048 \
		 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt

COPY srcs/self-signed.conf /etc/nginx/snippets/
COPY srcs/ssl-params.conf /etc/nginx/snippets/

# Set phpmyadmin
RUN apt-get install -y php-mbstring php-zip php-gd && \
		apt-get install -y wget

RUN wget -P / https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz && \
		tar xvf /phpMyAdmin-4.9.0.1-all-languages.tar.gz && \
		mv /phpMyAdmin-4.9.0.1-all-languages /usr/share/phpmyadmin && \
		mkdir -p /var/lib/phpmyadmin/tmp && \
		chown -R www-data:www-data /var/lib/phpmyadmin

COPY srcs/config.inc.php /usr/share/phpmyadmin/
COPY srcs/create_pma_database /

RUN service mysql restart && \
		mariadb < /usr/share/phpmyadmin/sql/create_tables.sql && \
		mariadb < "/create_pma_database" && \
		ln -s /usr/share/phpmyadmin /var/www/html/phpmyadmin

# Set wordpress
RUN apt-get install -y php-cgi php-common php-pear php-net-socket php-xml-util php-gettext php-bcmath unzip

COPY srcs/configure_wp_database /

RUN service mysql restart && \
		mariadb < "/configure_wp_database"
RUN wget https://wordpress.org/latest.tar.gz && \
		tar -xvzf latest.tar.gz -C /var/www/html/

COPY srcs/wp-config.php /var/www/html/wordpress/

EXPOSE 80
EXPOSE 443

<<<<<<< HEAD
#CMD service nginx start && \
CMD	service mysql start && \
	service php7.3-fpm start && \
	nginx -g 'daemon off;'
=======
CMD service mysql start; \
		service php7.3-fpm start; \
		nginx -g 'daemon off;'
>>>>>>> 54bd4be898d4299136a13a7f3361a6e36c1f6423
