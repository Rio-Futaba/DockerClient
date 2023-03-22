//
// Created by Dorothy on 2023/3/21.
//

#ifndef DOCKERCLIENT_DOCKERCLIENT_H
#define DOCKERCLIENT_DOCKERCLIENT_H
#include <string>
#include <map>
#include <arpa/inet.h>
#include <sys/un.h>
#include <sys/socket.h>
class DockerClient {
public:

    DockerClient(std::string host);



    //containers
    std::string list_containers();



private:
    void init();
    std::map<std::string,std::string> container_list;
    int fd = -1;
    std::string unix_sock_addr;
    int buffer_size=4*1024*1024;
    int connect_status;
};


#endif //DOCKERCLIENT_DOCKERCLIENT_H
