#include "../include/func.h"
#include "../include/head.h"

int getCmd(pMsgPkg_t pMsgPkg) {
    char buf[128] = {0};
    char cmd[128] = {0};
    printf("cmd:");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf,"%s %s", cmd, pMsgPkg->agmBuf);
    if (!strcmp("pwd", cmd)) {
       pMsgPkg->cmdType = CMD_PWD;
    }    
    else if (!strcmp("ls", cmd)) {
       pMsgPkg->cmdType = CMD_LS; 
    }
    else if (!strcmp("cd", cmd)) {
        pMsgPkg->cmdType = CMD_CD;
    }
    else if (!strcmp("mkdir", cmd)) {
        pMsgPkg->cmdType = CMD_MKDIR;
    }
    else if (!strcmp("rmdir", cmd)) {
        pMsgPkg->cmdType = CMD_RM;
    }
    else {
        pMsgPkg->cmdType = ERROR; 
    }
    pMsgPkg->bufLen = strlen(pMsgPkg->agmBuf);

    return 0;
}

