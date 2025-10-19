#include "myshell.hpp"

namespace fs = std::filesystem;

std::vector<fs::path> get_PATH_dirs() {
    const char* path = std::getenv("PATH");
    std::vector<fs::path> path_dirs;
    if (!path) return path_dirs;

    std::stringstream ss(path);

    std::string dir;

#ifdef _WIN32
    const char delimiter = ';';  // Windows PATH separator
#else
    const char delimiter = ':';  // POSIX separator
#endif

    while(std::getline(ss, dir, delimiter)){
        if(!dir.empty())
            path_dirs.emplace_back(dir);
    }

    return path_dirs;
    
}