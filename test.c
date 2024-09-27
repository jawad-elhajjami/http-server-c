#include <stdio.h>
#include "Nodes/Server.h"
#include <unistd.h>
#include <string.h>


void launch(struct Server *server){
    
    char buffer[30000];
    int addr_len = sizeof(server->address);
    while(1){
        printf("========= WAITING FOR CONNECTION ========= \n");
        int new_socket = accept(server->socket, (struct sockaddr *)&server->address, &addr_len);
        read(new_socket, buffer, 30000);
        printf("%s \n", buffer);
        char *hello = "HTTP/1.1 200 OK\r\n"
                "Date: Mon, 27 Jul 2009 12:28:53 GMT\r\n"
                "Server: CustomServer\r\n"
                "Content-Length: 88\r\n"
                "Content-Type: text/html\r\n"
                "Connection: Closed\r\n"
                "\r\n"
                "<html><body><h1>Hello, World!</h1></body></html>";
        write(new_socket, hello, strlen(hello));
        close(new_socket);
    }
}

int main(){
    struct Server server = server_constructor(AF_INET, 0, SOCK_STREAM, INADDR_ANY, 8080, 10, launch);
    server.launch(&server);
}