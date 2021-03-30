#include "../include/head.h"
#include "../include/func.h"


int getConfig(char* IP, char* PORT){
    FILE* fp = fopen("../conf/Netconf", "rb");
    fscanf(fp, "%s %s", IP, PORT);
    return 0;
}
