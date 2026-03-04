#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

int main() {
  // Flush after every std::cout / std:cerr 
  // usually it waits until the buffer is full
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::vector<std::string> type_value={"echo", "exit", "type"};

  // TODO: Uncomment the code below to pass the first stage
  while(true){
    std::cout << "$ ";
    std::string command;
    std::getline(std::cin, command);

    //to exit REPL
    if(command=="exit") break;

    //echo command
    if(command.substr(0,5)=="echo "){
      std::cout<<command.substr(5)<<std::endl;
    }else if(command.substr(0,5)=="type "){
      if(std::find(type_value.begin(),type_value.end(),command.substr(5))!=type_value.end()){
        std::cout<<command.substr(5)<<" is a shell builtin"<<std::endl;
      }else{
        std::cout<<command.substr(5)<<": command not found"<<std::endl;
      }
    }else{
      std::cout<<command<<": command not found"<<std::endl;
    }
  }
}
