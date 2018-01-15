/**
 * sockaddr结构体
 * 
*/

struct sockaddr_in
{
    sa_family_t     sin_family; //地址族(Address Family)AF_INET/AF_INET6/AF_LOCAL
    uint16_t        sin_port; //16位TCP/UDP端口号
    struct in_addr  sin_addr; //32位IP地址
    char            sin_zero[8]; //不使用
}

struct in_addr
{
    In_addr_t     s_addr;  //32位IPv4地址
}

struct sockaddr
{
    sa_family_t     sin_family;
    char            sa_data[14];//地址信息
}