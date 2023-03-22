//
// Created by Dorothy on 2023/3/21.
//

#include "DockerClient.h"
#include <unistd.h>

DockerClient::DockerClient(std::string host):unix_sock_addr(host) {


}


auto DockerClient::init() ->void {
    if (fd != -1) {
        return;
    }
    if (fd == -1){
        fd = socket(AF_UNIX,SOCK_STREAM,0);
    }
    sockaddr_un address ;
    address.sun_family = AF_UNIX;
    strcpy(address.sun_path,unix_sock_addr.c_str());
    int len = sizeof(address);
    if (connect(fd, (struct sockaddr *)&address, len) == -1){
        connect_status =-1;
        return;
    }
    connect_status = 1;
}

auto DockerClient::list_containers() ->std::string {
    std::string  uri("GET /containers/json HTTP/1.1\\r\\nHost: localhost\\r\\nAccept: application/json\\r\\n\\r\\n");
    if (connect_status !=1 ){
        init();
    }
    if(write(fd,uri.c_str(),strlen(uri.c_str())) == -1){
        return "";
    }
    char buffer[buffer_size];
    int n = recv(fd,buffer,buffer_size,0);
    return n > 0 ? std::string(buffer):"";
}