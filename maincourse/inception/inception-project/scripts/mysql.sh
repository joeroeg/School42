#!/bin/bash

read -sp 'Enter MySQL root password: ' MYSQL_ROOT_PASSWORD
echo
docker exec -i mariadb mysql -u root -p"$MYSQL_ROOT_PASSWORD" << EOF
SHOW DATABASES;
USE db;
SHOW TABLES;
SELECT * FROM wp_comments;
EOF

# SELECT * FROM mysql.user WHERE User = 'username' AND Password = PASSWORD('password');
