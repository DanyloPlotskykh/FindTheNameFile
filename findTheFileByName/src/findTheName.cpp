#include "findTheName.hpp"

#include <vector>
#include <thread>
#include <iostream>

#define MAX_TREADS 8

namespace fs = std::filesystem;

FindTheName::FindTheName(const std::string &name) : name(name) {}

void searchInDir(const fs::path &searchPath, const std::string &name, std::shared_ptr<ThreadPool> t)
{
    try
    {
        for (const auto &entry : fs::recursive_directory_iterator(searchPath))
        {
            if (fs::is_regular_file(entry) && entry.path().filename() == name)
            {
                std::cout << "file - " << entry.path().filename() << " was found in " << entry.path() << std::endl;
                t->stoped();
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error - " << e.what() << '\n';
    }
}

void FindTheName::search()
{
    fs::path path = fs::path("C:\\");
    int directoryCount = std::count_if(
        fs::directory_iterator(path),
        fs::directory_iterator(),
        [](const fs::directory_entry &entry)
        {
            return fs::is_directory(entry.status());
        });

    (directoryCount > MAX_TREADS) ? t = std::make_shared<ThreadPool>(MAX_TREADS) : t = std::make_shared<ThreadPool>(directoryCount);
    for (const auto &dir : fs::directory_iterator(path))
    {
        auto paths = dir.path();
        t->enqueue([paths, this]()
                   { searchInDir(paths, name, t); });
    }
}
