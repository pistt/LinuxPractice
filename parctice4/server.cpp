#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define EXPAND(str) str##t

void print(const sockaddr_in& test) {
    cout << "IP:" << inet_ntoa(test.sin_addr) << endl;
    cout << "Port:" << test.sin_port << endl;
    cout << AF_INET << endl;
}

const auto BUF_SIZE = 1024;

int main(int argc, char** argv) {
    int ser_sock, cli_sock;
    char message[BUF_SIZE];
    int str_len, i;

    sockaddr_in ser_addr, cli_addr;
    socklen_t cli_addr_sz;

    if (argc != 2) {
        printf("Usage: %s <port> \n", argv[0]);
        exit(1);
    }

    ser_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (ser_sock == -1) {
        if (errno != 0)
            cerr << strerror(errno) << endl;
        exit(1);
    }

    memset(&ser_addr, 0, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ser_addr.sin_port = htons(atoi(argv[1]));

    if (-1 == bind(ser_sock, (sockaddr * )&ser_addr, sizeof(ser_addr))) {
        if (errno != 0)
            cerr << strerror(errno) << endl;
        exit(1);
    }

    if (listen(ser_sock, 5) == -1) {
        if (errno != 0)
            cerr << strerror(errno) << endl;
        exit(1);
    }

    cli_addr_sz = sizeof(cli_addr);
    
    for (int i = 0; i < 3; ++i) {
        cli_sock = accept(ser_sock, (sockaddr * )&cli_addr, &cli_addr_sz);
        if (cli_sock == -1) {
            if (errno != -1)
                cerr << strerror(errno) << endl;
            exit(1);
        }

        printf("Connect client %d......\n", i + 1);
        while (0 != (str_len = read(cli_sock, message, BUF_SIZE)))
            write(cli_sock, message, str_len);

        close(cli_sock);
    }

    close(ser_sock);
    return 0;
}

    // sockaddr_in addr;
    // const char* server_ip = "127.0.0.1";
    // decltype(addr.sin_port) server_port = 3456;

    // /* 创建 socket */
    // errno = 0;
    // int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    // if (server_sock == -1) {
    //     if (errno != 0)
    //         printf("%d", errno);
    //         printf("%s", strerror(errno));
    //     return 0;
    // }

    // /* 地址初始化 */
    // memset(&addr, 0, sizeof(addr));
    // addr.sin_family = AF_INET;
    // addr.sin_addr.s_addr = inet_addr(server_ip);
    // addr.sin_port = server_port;

    // /* 分配地址相关信息 */
    // int bindinfo = bind(server_sock, (sockaddr * )&addr, sizeof(addr));


    // print(addr);
    // cout << server_sock << endl << bindinfo << endl;

