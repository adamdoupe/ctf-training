FROM ubuntu:trusty
MAINTAINER Adam Doupe <adamdoupe@gmail.com>

ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && \
  apt-get -y install supervisor git apache2 libapache2-mod-php5 mysql-server php5-mysql pwgen php-apc php5-mcrypt && \
  echo "ServerName localhost" >> /etc/apache2/apache2.conf

ADD start-apache2.sh /start-apache2.sh
ADD run.sh /run.sh
RUN chmod 755 /*.sh
ADD my.cnf /etc/mysql/conf.d/my.cnf
ADD supervisord-apache2.conf /etc/supervisor/conf.d/supervisord-apache2.conf
ADD supervisord-mysqld.conf /etc/supervisor/conf.d/supervisord-mysqld.conf

# Remove pre-installed database
RUN rm -rf /var/lib/mysql/*

# Add MySQL utils
ADD create_mysql_admin_user.sh /create_mysql_admin_user.sh
RUN chmod 755 /*.sh

# config to enable .htaccess
ADD apache_default /etc/apache2/sites-available/000-default.conf
RUN a2enmod rewrite

#Environment variables to configure php
ENV PHP_UPLOAD_MAX_FILESIZE 10M
ENV PHP_POST_MAX_SIZE 10M

RUN dpkg --add-architecture i386
RUN apt-get update && apt-get -y upgrade
RUN apt-get install -y libgd-dev php5-gd
RUN apt-get -y install libc6:i386 libstdc++6:i386
RUN apt-get -y install byobu
RUN apt-get -y install man-db
RUN apt-get -y install git
RUN apt-get -y install python
RUN apt-get -y install build-essential libssl-dev libffi-dev python-dev
RUN apt-get -y install gdb
RUN apt-get -y install python2.7 python2.7-dev python-pip
RUN apt-get -y install vim



RUN mkdir -p /app && rm -fr /var/www/html && ln -s /app /var/www/html
COPY website /app

EXPOSE 80

CMD ["/run.sh"]
