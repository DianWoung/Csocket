/**
 * 
 *  网络地址初始化的步骤
 *   
 */

struct sockaddr_in addr;
char *serv_ip = "211.217.168.13"; //声明ip地址字符串
char *serv_port = "9190"; // 声明端口号字符串
memset(&addr, 0, sizeof(addr)); //成员初始化为0
addr.sin_family = AF_INET; //指定地址族
addr.sin_addr.s_addr = inet_addr(serv_ip); //基于字符串的ip地址初始化
addr.sin_port = htons(atoi(serv_port)); //基于字符串的端口号初始化

