//
// Created by Dorothy on 2023/3/21.
//

#ifndef DOCKERCLIENT_CONTAINER_H
#define DOCKERCLIENT_CONTAINER_H
#include <string>
#include <vector>
#include <map>
struct portMappingTable{
    std::string IP;
    int PrivatePort;
    int PublicPort;
    std::string Type;
};
typedef struct portMappingTable portMappingTable;

class Container {
    std::string Id;
    std::string Name;
    std::string Image;
    std::string ImageId;
    std::string Command;
    double Created;
    std::vector<portMappingTable> portMappingTables;
    std::map<std::string, std::string> Labels;
    std::string State;
    std::string Status;


};


#endif //DOCKERCLIENT_CONTAINER_H
