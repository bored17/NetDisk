groupadd mysql
useradd -r -g mysql -s /bin/false mysql
cd /usr/local
if  [ ! -f  "/usr/local/mysql-8.0.29-linux-glibc2.12-x86_64.tar.xz"  ]; then
wget https://dev.mysql.com/get/Downloads/MySQL-8.0/mysql-8.0.29-linux-glibc2.12-x86_64.tar.xz
else
echo  "tar.xz already exit"
fi

tar -xf mysql-8.0.29-linux-glibc2.12-x86_64.tar.xz

if  [ ! -f  "/usr/local/mysql"  ]; then
ln -s mysql-8.0.29-linux-glibc2.12-x86_64  mysql
else
rm -rf /usr/local/mysql
ln -s mysql-8.0.29-linux-glibc2.12-x86_64  mysql
fi

cd mysql
mkdir mysql-files
chown mysql:mysql mysql-files
chmod 750 mysql-files
bin/mysqld --initialize --user=mysql
bin/mysql_ssl_rsa_setup
bin/mysqld_safe --user=mysql &
# Next command is optional
cp support-files/mysql.server /etc/init.d/mysql.server
