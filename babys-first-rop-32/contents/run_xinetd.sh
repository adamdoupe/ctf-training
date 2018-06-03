#!/bin/bash
# Adapted from: https://rimuhosting.com/knowledgebase/linux/misc/trapping-ctrl-c-in-bash

cd /challenge

# trap ctrl-c and call ctrl_c()
trap ctrl_c INT

function ctrl_c() {
	kill -9 $APP_PID
}

/usr/sbin/xinetd -dontfork -f challenge.conf & export APP_PID=$!
echo "Running succesfully, go forth and hack!"
wait $APP_PID

