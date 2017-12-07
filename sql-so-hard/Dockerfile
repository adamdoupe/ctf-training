FROM adamdoupe/vuln-web-base:latest

RUN apt-get update
RUN apt-get install -y curl

RUN apt-get install -y postgresql postgresql-contrib

RUN curl -sL https://deb.nodesource.com/setup_8.x | sudo -E bash -

RUN apt-get install -y nodejs

RUN npm install pg@7.1.0
RUN npm install mysql
RUN npm install express

RUN apt-get install -y byobu
RUN apt-get -y install vim

ADD supervisord-postgres.conf /etc/supervisor/conf.d/
ADD supervisord-nodejs-app.conf /etc/supervisor/conf.d/
ADD supervisord-update-blacklist.conf /etc/supervisor/conf.d/

RUN rm /etc/supervisor/conf.d/supervisord-apache2.conf

RUN rm -rf /app/*

COPY app.js /app

COPY mysql.sql .
COPY postgres.sql .
ADD mysql-setup.sh /mysql-setup.sh
ADD create_postgres_admin_user.sh /create_postgres_admin_user.sh
ADD postgres-setup.sh /postgres-setup.sh
ADD update_blacklist.sh /update_blacklist.sh
ADD run.sh /run.sh

ADD flag /flag

RUN chmod 755 /*.sh

EXPOSE 31337

