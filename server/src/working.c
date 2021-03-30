#include "../include/func.h"

int working(pMsgPkg_t pMsgPkg) {
    switch(pMsgPkg->cmdType){
        case CMD_CD:cd(pMsgPkg);
        break;
        case CMD_LS:ls(pMsgPkg);
        break;
        case CMD_PWD:pwd(pMsgPkg);
        break;
        case CMD_MKDIR:mymkdir(pMsgPkg);
        break;
        case CMD_RM:rm(pMsgPkg);
        break;
        case CMD_GETS:putsFile(pMsgPkg);
        break;
        /* case CMD_PUTS:getsFile(pMsgPkg); */
        /* break; */
        
        case ERROR:error(pMsgPkg);
        break;

        default:
        break;
        
        
    } 
    return 0;
    
}
