FROM debian:buster

RUN apt-get update && apt-get install -y mariadb-server
RUN mkdir -p /run/mysql
RUN chown -R mysql:mysql /run/mysql

COPY tools/entryscript.sh /
RUN chmod +x /entryscript.sh
COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/

EXPOSE 3306
ENTRYPOINT ["/entryscript.sh"]
