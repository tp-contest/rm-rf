//

#include "../include/Document.h"

//
// Created by d on 07.04.19.

Document::Document() {
    std::cout << "hello doc consstr" << std::endl;
    state = nullptr;
}

void Document::setId(int id) {
    ID = id;
}


int Document::getId() const {
    return ID;
}

Status Document::loadFile(const char *file_name) {
    std::experimental::filesystem::path path{file_name};
    if(verify(path) != Ok){
        return ERROR;
    }
    auto new_file = new std::ifstream();
    new_file->open(file_name, std::ios::in);
    if(!new_file->is_open()){
        return ERROR;
    }
    file = new_file;
    return Ok;
}

Status Document::verify(const std::experimental::filesystem::path &name) const {
    std::uintmax_t filesize = std::experimental::filesystem::file_size(name);
    if (filesize < MIN_SIZE || filesize > MAX_SIZE) {
        std::cout << filesize << std::endl;
        return ERROR;
    }
    return Ok;
}