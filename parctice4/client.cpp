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
    int sock;
    int str_len;
    char message[BUF_SIZE];
    sockaddr_in server_addr;
    if (argc != 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        if (errno != 0)
            cerr << strerror(errno) << endl;
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (-1 == connect(sock, (sockaddr * )&server_addr, sizeof(server_addr))) {
        if (errno != 0)
            cerr << strerror(errno) << endl;
        exit(1);
    }

    printf("Connected success!\n");

    while (true) {
        printf("Input message(Q to quit):");
        fgets(message, BUF_SIZE, stdin);
        if (!strcmp(message, "q\n") || !strcmp(message, "Q\n"))
            break;
        write(sock, message, strlen(message));
        str_len = read(sock, message, BUF_SIZE - 1);
        message[str_len] = '\0';
        printf("Message from server: %s", message);
    }

    close(sock);






    return 0;
}