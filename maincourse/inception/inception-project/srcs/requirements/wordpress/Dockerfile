FROM debian:buster

RUN apt-get update && \
apt-get install -y php-fpm php-mysql wget mariadb-client 

RUN wget -O wp-cli.phar https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

COPY conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

COPY tools/auto_config.sh /auto_config.sh
RUN chmod +x /auto_config.sh

# Set the working directory to the WordPress installation directory
WORKDIR /var/www/html

EXPOSE 9000



ENTRYPOINT ["/auto_config.sh"]