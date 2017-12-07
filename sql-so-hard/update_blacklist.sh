#!/bin/bash

while true
do
	mysql -uroot bandb -e "delete from blacklists;"
	sleep 60s
done
