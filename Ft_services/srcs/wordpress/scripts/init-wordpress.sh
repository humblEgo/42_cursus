#!/bin/sh

sleep 5
SEC = 1
#mysql --host=mysql --user=iwoo --password=iwoo123 -p wordpress < /tmp/wordpress.sql > /dev/null 2>&1
mysql --host=mysql --user=iwoo --password=iwoo123 -p wordpress < /tmp/wordpress.sql 2>&1 /dev/null
until [ $? != 1 ]
do
	printf "데이터베이스에 wordpress.sql을 넣지 못했습니다. 다시 시도합니다 ....%d초 경과\n"${SEC}
	sleep 1
	mysql --host=mysql --user=iwoo --password=iwoo123 -p wordpress < /tmp/wordpress.sql 2>&1 /dev/null
    SEC = ${SEC} + 1
done