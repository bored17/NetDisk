#include "../include/func.h"
#include "../include/head.h"
#include "../include/process_pool.h"
char IP[64] = {0};
char PORT[64] = {0};

int main(int argc, char *argv[]) {
    int sfd = 0;

    getConfig(IP, PORT);
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    ERROR_CHECK(sfd, -1, "socket");
    struct sockaddr_in serAddr;
    memset(&serAddr, 0, sizeof(serAddr));

    serAddr.sin_family = AF_INET;
    serAddr.sin_addr.s_addr = inet_addr(IP);
    serAddr.sin_port = htons(atoi(PORT));

    int ret = connect(sfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
    ERROR_CHECK(ret, -1, "connect");

    pMsgPkg_t pMsgPkg = (pMsgPkg_t)calloc(1, sizeof(msgPkg_t));



    while (1) {
        puts("循环开始");
        memset(pMsgPkg, 0, sizeof(msgPkg_t));
        

         
        getCmd(pMsgPkg);
        send(sfd, pMsgPkg, sizeof(msgPkg_t), 0);
        
        memset(pMsgPkg, 0, sizeof(msgPkg_t));

        recv(sfd, pMsgPkg, sizeof(msgPkg_t), MSG_WAITALL);
        
        waitFunc(pMsgPkg);

        puts("循环结束");

    } 

    
    return 0;

}
