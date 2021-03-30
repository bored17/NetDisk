/* #ifndef __HEAD_H__ */
/* #define __HEAD_H__ */
/* #include "head.h" */
/* #endif */

#ifndef __FUNC_H__
#define __FUNC_H__

/* 命令类型宏定义 */
#define CMD_CD 1
#define CMD_LS 2
#define CMD_PWD 3
#define CMD_PUTS 4
#define CMD_GETS 5
#define CMD_RM 6
#define CMD_MKDIR 7
#define TRANS 8
#define ERROR 9
#define USROK 20
#define USRERR 21
#define PWDOK 22
#define PWDERR 23

/* 数据包结构体 */
typedef struct msgPkg_t{
    int cmdType;
    int bufLen;
    int sfd;
    long fileSize;
    char agmBuf[1024]; // argumentBuf 存放命令参数
}msgPkg_t,*pMsgPkg_t;

/* 函数声明 */
int getConfig(char* IP,char* PORT);
int getCmd(pMsgPkg_t pMsgPkg);
int waitFunc(pMsgPkg_t);

int ls(pMsgPkg_t);

#endif
