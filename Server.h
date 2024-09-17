
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

struct Server{

    int domain;
    int protocol;
    int service;
    __u_long interface;
    int port;
    int backlog;
    struct sockaddr_in address;
    void (*launch)(void);
}

struct Server server_consutructor(int domain, int protocol, int service, __u_long interface, int port, int backlog, void (*launch)(void));