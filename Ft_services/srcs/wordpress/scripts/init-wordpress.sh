#!/bin/sh

sleep 5
echo "=========================데이터베이스에 sql을 넣어봅니다. 잘될까?========================================="
mysql --host=mysql --user=iwoo --password=iwoo123 wordpress < tmp/wordpress.sql > /dev/null
echo result: $?
echo "=========================데이터베이스에 sql을 넣었습니다. 잘 되었을까요???================================"
until [ $? != 1 ]
do
	echo "데이터베이스에 wordpress.sql을 넣지 못했습니다. 다시 시도합니다 ...."
	sleep 1
	mysql --host=mysql --user=iwoo --password=iwoo123 wordpress < tmp/wordpress.sql > /dev/null
	echo result: $?
done