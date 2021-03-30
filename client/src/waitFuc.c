#include "../include/func.h"
#include "../include/head.h"
int print(pMsgPkg_t pMsgPkg) {
    
    puts(pMsgPkg->agmBuf);
    return 0;
}


int waitFunc(pMsgPkg_t pMsgPkg) {
    if ( TRANS != pMsgPkg->cmdType) {
       print(pMsgPkg);
    }
    
    else {
        printf("dog!\n");
    }
    return 0; 
}
