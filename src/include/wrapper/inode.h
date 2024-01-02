#pragma once

#include <string>
#include <sstream>
#include <sys/stat.h>
#include <unordered_map>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>

#include "common/config.h"
#include "adaptor/leveldb_adaptor.h"

namespace wrapperfs {

struct inode_metadata {
    struct stat stat;
};

struct inode_data {
    std::unordered_map<std::string, std::string> map;
};

struct inode_t {
    inode_metadata metadata;
    inode_data data;
};

bool get_inode(LevelDBAdaptor* adaptor, size_t inode_id, inode_t* &inode);
bool put_inode(LevelDBAdaptor* adaptor, size_t inode_id, inode_t* inode);

}