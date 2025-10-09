#ifndef _BUILTINS_
#define _BUILTINS_
#include "myshell.hpp"

sh_status_t echo(std::stringstream& input);

sh_status_t echo(std::stringstream& input){

    std::cout << input.str() << std::endl;
    return STATUS_OK;

}



#endif 