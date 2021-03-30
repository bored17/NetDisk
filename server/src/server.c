#include "../include/process_pool.h"
#include "../include/func.h"
#include "../head.h"
int sfd = 0; 
char IP[64] = {0};
char PORT[64] = {0};
int main(int argc, char** argv)
{   
    getConfig(IP,PORT);
    tcpInit(&sfd, IP, PORT);

    //1.循环创建子进程
    
    makeChild(5);

    //3.创建epoll监听文件描述符
    //循环的把父子进程之间通信的管道描述符交给epoll


    while(1);
                    //如果找到就读管道、并把子进程的状态置为空闲
    
    return 0;
}

