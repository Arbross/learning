FROM ubuntu:latest

MAINTAINER Viktor Pavlovskyi <s101746@pollub.edu.pl>

RUN apt-get update
RUN apt-get upgrade -y

RUN apt-get install -y apache2

COPY index.html /var/www/html/

# Uruchomienie serwera Apache w tle
CMD ["apache2ctl", "-D", "FOREGROUND"]
