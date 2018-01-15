/**
 * inet_aton函数
 * 将IP地址转为32位网络字节序整数返回
*/

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include "../common/function.h"

int main(int argc, char *argv[])
{
    char *addr = "127.232.124.79";
    struct sockaddr_in addr_inet;

    if(!inet_aton(addr, &addr_inet.sin_addr))
        error_handling("Conversion error");
    else
        printf("Network ordered integer addr: %#x \n",
        addr_inet.sin_addr.s_addr);
    return 0;
}
