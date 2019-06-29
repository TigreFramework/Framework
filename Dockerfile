FROM httpd:2.4

RUN apt-get update && apt-get install -y valgrind

COPY ./httpd.conf /usr/local/apache2/conf/httpd.conf
COPY httpd-foreground /usr/local/bin/