#!/bin/sh

/etc/init.d/mysql start

sleep 5

MYSQL_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
MYSQL_PASSWORD_FILE=$(cat /run/secrets/db_password)

if ! [ -d "/var/lib/mysql/$MYSQL_DATABASE" ];
then
    echo "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;" | mysql -u root
    echo "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';" | mysql -uroot -p"$MYSQL_ROOT_PASSWORD"
    echo "GRANT ALL ON *.* TO 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; FLUSH PRIVILEGES;" | mysql -uroot
    echo "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'; " | mysql -u root
    echo "FLUSH PRIVILEGES;" | mysql -u root
fi
    mysqladmin -u root -p$MYSQL_ROOT_PASSWORD shutdown
exec mysqld_safe
