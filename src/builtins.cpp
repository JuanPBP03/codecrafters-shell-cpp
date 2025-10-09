#ifndef _BUILTINS_
#define _BUILTINS_
#include "builtins.hpp"



sh_status_t echo(std::stringstream& args){

    std::cout << args.str() << std::endl;
    return STATUS_OK;

}

sh_status_t type(std::stringstream& args){

    std::string arg;
    args >> arg;
    if(BUILTIN_COMMANDS.find(arg) != BUILTIN_COMMANDS.end()){
        std::cout << arg << " is a shell builtin" << std::endl;
    }else{
        std::cout << arg << ": not found" << std::endl;
    }

    
    return STATUS_OK;

}

sh_status_t shell_exit(std::stringstream& args){
    
    int exit_code;
    args >> exit_code;
    exit(exit_code ? 0 : exit_code);
    
}

const std::unordered_map<std::string, std::function<sh_status_t(std::stringstream&)>> BUILTIN_COMMANDS = {
    {"echo", echo},
    {"exit", shell_exit},
    {"type", type}
};


#endif 