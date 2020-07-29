echo "Setup wordpress.."

cd wordpress

# service object 생성하여 metalLB로부터 EXTERNAL_IP를 할당받음.
kubectl create -f ./yaml/wordpress-service.yaml >> $LOG_PATH
sleep 1

# 할당 받은 EXTERNAL_IP를 WORDPRESS_IP 환경변수에 저장
kubectl get services | grep wordpress | awk '{print $4}' > WORDPRESS_IP
export WORDPRESS_IP=$(cat < WORDPRESS_IP)

# 만약 EXTERNAL_IP가 아직 할당되지 않아서 <pending> 상태면 할당 될 때 까지 반복
export PENDING=\<pending\>
until [ $WORDPRESS_IP != $PENDING ]                                         
do
	echo "try to get WORDPRESS_IP"
	kubectl get services | grep wordpress | awk '{print $4}' > WORDPRESS_IP
	export WORDPRESS_IP=$(cat < WORDPRESS_IP)
	sleep 1
done
rm WORDPRESS_IP

# 할당 받은 WORDPRESS_IP를 워드프레스 데이터 파일과 설정파일에 수정삽입.
sed "s/WORDPRESS_IP/$WORDPRESS_IP/g" ./files/data/wordpress.sql > ./files/wordpress.sql
sed "s/WORDPRESS_IP/$WORDPRESS_IP/g" ./files/data/wp-config.php > ./files/wp-config.php

# 위 설정파일을 바탕으로 도커이미지빌드
docker build -t ft_wordpress . >> $LOG_PATH
sleep 1

# 빌드한 이미지로 deployment object 생성
kubectl create -f ./yaml/wordpress-deployment.yaml >> $LOG_PATH

echo "Finish wordpress setup"