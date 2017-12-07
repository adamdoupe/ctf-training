#!/bin/bash

echo "Uploading mysql blacklist database"
mysql -uroot bandb -e "select count(*) from blacklists;" > /dev/null 2> /dev/null || mysql -u root < mysql.sql



