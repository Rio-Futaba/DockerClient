//
// Created by Dorothy on 2023/3/21.
//

#ifndef DOCKERCLIENT_DOCKERCLIENT_H
#define DOCKERCLIENT_DOCKERCLIENT_H
#include <iostream>
#include <string>
#include <arpa/inet.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <memory>
#include <fstream>
#include <vector>




class DockerClient {
    DockerClient(std::string host);

    //system
    std::string system_info();
    std::string docker_version();

    //images
    std::string dockerimages();

    //containers
    std::string list_containers();
    std::string inspect_container();
    std::string logs_container();
    std::string create_container();
    std::string start_container();
    std::string get_container_changes();
    std::string stop_container();
    std::string kill_container();
    std::string pause_container();
    std::string wait_container();
    std::string delete_container();
    std::string unpause_container();
    std::string restart_container();
    std::string attach_to_container();
    std::string copy_from_container();


private:
    int fd;
    std::string unix_sock_addr;
    int buffer_size;

};


#endif //DOCKERCLIENT_DOCKERCLIENT_H
