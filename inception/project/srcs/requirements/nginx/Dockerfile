FROM debian:bullseye
RUN apt-get update && apt-get install -y nginx openssl
COPY conf/nginx.conf /etc/nginx/sites-available/default
RUN touch /var/www/html/index.html && echo "<h1>Nginx is working!</h1>" > /var/www/html/index.html
EXPOSE 443
CMD  ["nginx", "-g", "daemon off;"]

#COPY tools/davigome.42.fr.crt /etc/nginx/ssl/davigome.42.fr.crt
#COPY tools/davigome.42.fr.key /etc/nginx/ssl/davigome.42.fr.key