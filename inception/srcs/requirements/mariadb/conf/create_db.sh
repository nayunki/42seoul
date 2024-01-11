# /tmp/init_db.sql 파일 생성, 아래 내용을 해당 파일에 적는다.
cat > /tmp/create_db_sql << EOF
USE mysql;
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS $MYSQL_DB_NAME;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PWD';
GRANT ALL PRIVILEGES ON $MYSQL_DB_NAME.* TO '$MYSQL_USER'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PWD';
FLUSH PRIVILEGES;
EOF
# 모든 ip에서 접속 가능하도록 설정 -> '%'
# mysql 재시작없이 설정 변경 적용

# run init.sql
/usr/bin/mysqld --user=mysql --bootstrap < /tmp/create_db_sql
# 위의 스크립트로 mysql DB서버 설정. --bootstrap 옵션 : 서버 구동 없이 테이블 생성
/usr/bin/mysqld -u mysql
# 초기화된 MySQL DB 서버를 실행. mysql 사용자로 실행한다.
