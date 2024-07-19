FROM debian:buster

RUN apt-get update && apt-get install -y mariadb-server
RUN mkdir -p /run/mysql
RUN chown -R mysql:mysql /run/mysql

COPY tools/entrypoint.sh /
RUN chmod +x /entrypoint.sh
COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/

EXPOSE 3306
ENTRYPOINT ["/entrypoint.sh"]
