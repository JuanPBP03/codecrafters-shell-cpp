#include "builtins.hpp"
#include "helpers.hpp"


sh_status_t echo(std::stringstream& args){

    std::cout << args.str() << std::endl;
    return STATUS_OK;

}

sh_status_t type(std::stringstream& args){

    std::string arg;
    std::vector<std::filesystem::path> PATH = get_PATH_dirs();
    args >> arg;
    if(arg.empty()){
         std::cout << arg << ": not found" << std::endl;
    }else if(BUILTIN_COMMANDS.find(arg) != BUILTIN_COMMANDS.end()){
        std::cout << arg << " is a shell builtin" << std::endl;
    }else if(!PATH.empty()){
            //std::cout<<"PATH FOUND"<< std::endl;
            for(const auto& dir : PATH){
                fprintf(stderr, "DIR: %s\n", dir.c_str());
                if(std::filesystem::exists(dir / (arg))){
                    std::cout << arg << " is " << (dir/arg).string() << std::endl;
                    return STATUS_OK;
                }
                
            }
            std::cout << arg << ": not found" << std::endl;
        
       
        }
    return STATUS_OK;
}

sh_status_t shell_exit(std::stringstream& args){
    
    int exit_code = 0;
    args >> exit_code;
    exit(exit_code ? 0 : exit_code);
    
}

const std::unordered_map<std::string, std::function<sh_status_t(std::stringstream&)>> BUILTIN_COMMANDS = {
    {"echo", echo},
    {"exit", shell_exit},
    {"type", type}
};
