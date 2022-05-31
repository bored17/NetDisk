#!/bin/bash

# 下载资源


myPath=$(whiptail --title " Input Box" --inputbox "input installion Location" 10 60 /opt 3>&1 1>&2 2>&3)

exitstatus=$?

if [ $exitstatus = 0 ]; then
    echo "Your name is:" $myPath
else
    echo "You chose Cancel."
fi

kafkaVersion=fasdf.12
flumeVersion=
flinkVersion=
sparkVersion=
esVersion=
mysqlVersion=
pgsqlVersion=
#!/bin/bash
OPTIONS=$(whiptail --title "Checklist Dialog" --checklist \
"Choose software to install" 15 60 8 \
"kafka" "${kafkaVersion}" ON \
"flume" "Popular Ubuntu" OFF \
"flink" "Stable CentOS" ON \
"spark" "Stable CentOS" ON \
"elasticsearch" "Stable CentOS" ON \
"mysql" "Stable CentOS" ON \
"postgresql" "Rising Star Mint" OFF 3>&1 1>&2 2>&3)

exitstatus=$?
if [ $exitstatus = 0 ]; then
    echo "Your favorite distros are:" $OPTIONS
else
    echo "You chose Cancel."
fi

for i in $OPTIONS
do
    if [ -f $i ]; then 
    echo $i
    mv $i $myPath
    cd $myPath
    tar xfvz $i
    cd -
    else 
    echo "no such file: $i"
    fi
done
