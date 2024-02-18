#pragma once

#include <string>
#include <filesystem>
#include "ThreadPool.hpp"

namespace fs = std::filesystem;

class FindTheName
{
public:
    FindTheName(const std::string &name);
    void search();
    std::string name;
    std::shared_ptr<ThreadPool> t;
};
