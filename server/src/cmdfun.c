#include "../include/func.h"
#include "../include/head.h"

int error(pMsgPkg_t pMsgPkg){
    memset(pMsgPkg->agmBuf, 0, sizeof(pMsgPkg->agmBuf));
    sprintf(pMsgPkg->agmBuf, "%s", "error cmd");
    send(pMsgPkg->sfd, pMsgPkg, sizeof(msgPkg_t), 0);
    return 0;
}

int ls(pMsgPkg_t pMsgPkg){
    DIR * pDir = NULL;
    if (0 == pMsgPkg->bufLen) {
        pDir = (DIR*)opendir(".");
    }
    else{
        pDir = (DIR*)opendir(pMsgPkg->agmBuf);
    }

    memset(pMsgPkg->agmBuf, 0, sizeof(pMsgPkg->agmBuf));


    if (NULL == pDir) {
        sprintf(pMsgPkg->agmBuf, "%s", "No such dirent!");
    }
    else{
        struct dirent *pDirent = NULL;
        int ptr = 0;
        while((pDirent = readdir(pDir))){
            if(!strcmp(pDirent->d_name, "..") || !strcmp(pDirent->d_name, ".")){
                continue;
            }
            int ret = sprintf(pMsgPkg->agmBuf + ptr, "%-15s", pDirent->d_name);
            ptr += ret; 
        }
    }

    pMsgPkg->bufLen = strlen(pMsgPkg->agmBuf);
    send(pMsgPkg->sfd, pMsgPkg, sizeof(msgPkg_t), 0);

    closedir(pDir);

    return 0;
}

int cd(pMsgPkg_t pMsgPkg) {
    char buf[256] = {0};
    int ret =chdir(pMsgPkg->agmBuf);
    if (0 == ret) {
    memset(pMsgPkg->agmBuf, 0, sizeof(pMsgPkg->agmBuf));
    getcwd(buf, sizeof(buf));
    sprintf(pMsgPkg->agmBuf, "%s", buf);
    send(pMsgPkg->sfd, pMsgPkg, sizeof(msgPkg_t), 0);
    }
    else {
        memset(pMsgPkg->agmBuf, 0, sizeof(pMsgPkg->agmBuf));
        sprintf(buf, "%s", "invalid dirent");
        sprintf(pMsgPkg->agmBuf, "%s", buf);
        send(pMsgPkg->sfd, pMsgPkg, sizeof(msgPkg_t), 0);
    }
    return 0;
}
    

int pwd(pMsgPkg_t pMsgPkg) {
    char buf[256] = {0};
    memset(pMsgPkg->agmBuf, 0, sizeof(pMsgPkg->agmBuf));
    getcwd(buf, sizeof(buf));
    sprintf(pMsgPkg->agmBuf, "%s", buf);
    puts(pMsgPkg->agmBuf);
    send(pMsgPkg->sfd, pMsgPkg, sizeof(msgPkg_t), 0);
    return 0;
}

int mymkdir(pMsgPkg_t pMsgPkg) {
    if (0 == pMsgPkg->bufLen) {
        sprintf(pMsgPkg->agmBuf, "%s", "args error");
        send(pMsgPkg->sfd, pMsgPkg, sizeof(msgPkg_t), 0);
    } 
    else{
        DIR* pdir = opendir(pMsgPkg->agmBuf);
        if (NULL == pdir) {
            mkdir(pMsgPkg->agmBuf, 0666);
            memset(pMsgPkg->agmBuf, 0, sizeof(pMsgPkg->agmBuf));
            pMsgPkg->bufLen = strlen(pMsgPkg->agmBuf);
            send(pMsgPkg->sfd, pMsgPkg, sizeof(msgPkg_t), 0);
        }
        else{
            memset(pMsgPkg->agmBuf, 0, sizeof(pMsgPkg->agmBuf));
            sprintf(pMsgPkg->agmBuf, "%s", "already exit");
            send(pMsgPkg->sfd, pMsgPkg, sizeof(msgPkg_t), 0);
        }
    }
     return 0;
}
    
int rm(pMsgPkg_t pMsgPkg) {
    if (0 == pMsgPkg->bufLen) {
        sprintf(pMsgPkg->agmBuf, "%s", "args error");
        send(pMsgPkg->sfd, pMsgPkg, sizeof(msgPkg_t), 0);
    } 
    else{
        DIR* pdir = opendir(pMsgPkg->agmBuf);
        if (NULL == pdir) {
            memset(pMsgPkg->agmBuf, 0, sizeof(pMsgPkg->agmBuf));
            sprintf(pMsgPkg->agmBuf, "%s", "no exit dirent");
            send(pMsgPkg->sfd, pMsgPkg, sizeof(msgPkg_t), 0);
        }
        else{ 
        rmdir(pMsgPkg->agmBuf);
        memset(pMsgPkg->agmBuf, 0, sizeof(pMsgPkg->agmBuf));
        pMsgPkg->bufLen = strlen(pMsgPkg->agmBuf);
        send(pMsgPkg->sfd, pMsgPkg, sizeof(msgPkg_t), 0);
        }
    }
    return 0;
}


int putsFile(pMsgPkg_t pMsgPkg) {
    char buf[256] = {0};
    if (0 == pMsgPkg->bufLen) {
        memset(pMsgPkg->agmBuf, 0, sizeof(pMsgPkg->agmBuf));
        sprintf(pMsgPkg->agmBuf, "%s", "invalid file");
        send(pMsgPkg->sfd, pMsgPkg, sizeof(msgPkg_t), 0);
    }
    else {
            
            
    }


}
