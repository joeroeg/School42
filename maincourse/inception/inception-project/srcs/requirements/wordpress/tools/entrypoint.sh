#!/bin/bash

service php7.3-fpm start

WP_PASSWORD=$(cat /run/secrets/wp_root_password)
WP_USER_PASSWORD=$(cat /run/secrets/wp_password)
MYSQL_PASSWORD=$(cat /run/secrets/db_password)

# Wait for MariaDB to be ready
until mysqladmin ping -h mariadb -u"${MYSQL_USER}" -p"${MYSQL_PASSWORD}" --silent; do
    echo "Waiting for MariaDB to be ready..."
    sleep 5
done

if [ -f /var/www/html/wp-config.php ]; then
    echo "wp-config.php already exists. Skipping creation."
else
    wp core download --path=/var/www/html/ --allow-root
    sleep 10
    wp config create --dbname="${MYSQL_DATABASE}" --dbuser="${MYSQL_USER}" --dbpass="${MYSQL_PASSWORD}" --dbhost=mariadb:3306 --allow-root
    wp core install --url="${DOMAIN_NAME}" --title="${WP_TITLE}" --admin_user="${WP_ADMIN}" --admin_password="${WP_PASSWORD}" --admin_email="${WP_EMAIL}" --skip-email --allow-root
    wp user create "${WP_USER}" "${WP_USER_EMAIL}" --user_pass="${WP_USER_PASSWORD}" --role=author --allow-root
fi

service php7.3-fpm stop

exec /usr/sbin/php-fpm7.3 -F
