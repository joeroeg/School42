FROM debian:buster

RUN apt-get update && apt-get install -y nginx
RUN apt-get update && apt-get install -y openssl && openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/nginx.key -out /etc/nginx/nginx.crt -subj "/C=CA/ST=QC/L=Quebec/O=42 School/OU=inception/CN=inception"

COPY  ./conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
