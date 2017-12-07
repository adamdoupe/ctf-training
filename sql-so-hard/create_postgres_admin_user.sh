#!/bin/bash

sudo -u postgres /usr/lib/postgresql/9.3/bin/postgres -D /var/lib/postgresql/9.3/main -c config_file=/etc/postgresql/9.3/main/postgresql.conf > /dev/null 2>&1 &
echo $! > /tmp/postgres.pid

RET=1
while [[ RET -ne 0 ]]; do
    echo "=> Waiting for confirmation of Postgres service startup"
    sleep 5
    sudo -u postgres psql -c "select 1" -q > /dev/null 2>&1
    RET=$?
done

PASS=${PGSQL_PASS:-$(pwgen -s 12 1)}
_word=$( [ ${PGSQL_PASS} ] && echo "preset" || echo "random" )

if [ -f /postgres-setup.sh ] ; then
  ./postgres-setup.sh
fi

echo "=> Done!"

kill `cat /tmp/postgres.pid` && rm /tmp/postgres.pid
