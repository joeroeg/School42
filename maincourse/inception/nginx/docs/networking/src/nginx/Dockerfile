# nginx Dockerfile

FROM nginx:latest

COPY configuration/nginx.conf /etc/nginx/nginx.conf
COPY html /usr/share/nginx/html
LABEL com.docker.compose.config='{"ContainerConfig":{}}'
