#!/bin/bash

sudo -u postgres psql -c "select count(*) from users;" -d userdb > /dev/null 2> /dev/null || sudo -u postgres psql < postgres.sql
