#include "../include/process_pool.h"
#include "../include/func.h"
extern int sfd ;
int makeChild(int processNum)
{
    int childFd = 0;
    for(int i = 0; i < processNum; ++i){
        childFd = fork();
        if(0 == childFd){
            childFunc();
            exit(0);
        }
    }
    return 0;
}

int childFunc()
{
    msgPkg_t msgPkg;
    memset(&msgPkg, 0, sizeof(msgPkg_t));
    int epfd = epoll_create(1);
    epollAddFd(epfd, sfd);
    struct epoll_event *evs = (struct epoll_event*)calloc(1, sizeof(struct epoll_event));
    while(1){
        epoll_wait(epfd, evs, 1, -1);
        if(evs[0].data.fd == sfd){
            int clientFd = accept(sfd, NULL, NULL);
            //跟客户端建立通信、发送数据
            while(1){
                printf("start\n");
                int ret = recv(clientFd,&msgPkg, sizeof(msgPkg), MSG_WAITALL);
                msgPkg.sfd = clientFd;
                if (0 ==ret) {
                    printf("disconnect\n");
                    break;
                }
                //发送完数据后，写管道通知自己完成数据交互，需要把状态信息置为空闲
                working(&msgPkg);
                printf("end\n");
            }
        }

    }
    return 0;
}
