#include "builtins.cpp"

int main() {
  // Flush after every std::cout / std:cerr
  std::stringstream ss;
  std::string command;
  std::stringstream args;
  while(true){

    ss.clear();
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;
    
    // Uncomment this block to pass the first stage
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);
    ss.str(input);
    ss >> command;
    args << ss.rdbuf();

    if(command == "exit 0")
      return 0;
    else if(command == "echo"){
      echo(args);
    }
    else
      std::cout << command << ": command not found" << std::endl;
  
    
  }
}

