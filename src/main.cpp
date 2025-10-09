#include "builtins.hpp"

int main() {
  // Flush after every std::cout / std:cerr
  std::stringstream ss;
  std::string command;
  std::stringstream args;
  while(true){

    ss.clear();
    args.clear();
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;
    
    // Uncomment this block to pass the first stage
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);
    ss.str(input);
    ss >> command;
    ss >> std::ws;
    args << ss.rdbuf();

    auto it = BUILTIN_COMMANDS.find(command);
    if(it != BUILTIN_COMMANDS.end()){
      it->second(args);
    }
    else
      std::cout << command << ": command not found" << std::endl;
    args.str("");
    ss.str("");
    
  }
}

