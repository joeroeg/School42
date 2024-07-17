FROM nginx:1.25-alpine

ENV NGINX_PORT=80

RUN adduser -D -u 1000 appuser && \
    chown -R appuser:appuser /usr/share/nginx/html && \
    chmod -R 755 /usr/share/nginx/html && \
    chown -R appuser:appuser /var/cache/nginx && \
    chown -R appuser:appuser /var/log/nginx && \
    chown -R appuser:appuser /etc/nginx/conf.d && \
    chown -R appuser:appuser /etc/nginx && \
    chmod -R 755 /etc/nginx && \
    touch /var/run/nginx.pid && \
    chown -R appuser:appuser /var/run/nginx.pid && \
    rm -rf /var/cache/apk/*

COPY configuration/nginx.conf /etc/nginx/nginx.conf.template
COPY html /usr/share/nginx/html

EXPOSE ${NGINX_PORT}

USER appuser

HEALTHCHECK --interval=30s --timeout=3s CMD wget --quiet --tries=1 --spider http://localhost:${NGINX_PORT}/ || exit 1

CMD ["sh", "-c", "envsubst '$NGINX_PORT' < /etc/nginx/nginx.conf.template > /etc/nginx/nginx.conf && nginx -g 'daemon off;'"]
