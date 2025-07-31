FROM debian:bullseye

RUN apt-get update && apt-get install -y nginx openssl
COPY conf/nginx.conf /etc/nginx/sites-available/default

RUN mkdir -p /etc/nginx/ssl
RUN openssl req -subj "/C=SP/ST=Malaga/L=Malaga/O=42 Malaga/OU=davigome/CN=davigome" \
    -new -newkey rsa:2048 -days 365 -nodes -x509 \
    -keyout /etc/nginx/ssl/davigome.42.fr.key -out /etc/nginx/ssl/davigome.42.fr.crt


COPY index.html /var/www/html/index.html
COPY style.css /var/www/html/style.css

EXPOSE 443
CMD ["nginx", "-g", "daemon off;"]

#COPY tools/davigome.42.fr.crt /etc/nginx/ssl/davigome.42.fr.crt
#COPY tools/davigome.42.fr.key /etc/nginx/ssl/davigome.42.fr.key