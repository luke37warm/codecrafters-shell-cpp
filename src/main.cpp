#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include <sstream>
#include <unistd.h>

int main() {
  // Flush after every std::cout / std:cerr 
  // usually it waits until the buffer is full
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;
  std::string command;
  std::string line;

  std::vector<std::string> type_value={"echo", "exit", "type"};

  // TODO: Uncomment the code below to pass the first stage
  while(true){
    std::cout << "$ ";
    std::getline(std::cin, line);
    std::stringstream ss(line);
    ss>>command;

    //to exit REPL
    if(command=="exit") break;

    //echo command
    if(command=="echo"){
      std::string word;
      while(ss>>word){
        std::cout<<word<<" ";
      }
      std::cout<<"\n";
    }
    //type command
    else if(command=="type"){
      bool found=false;
      std::string command_to_know;
      ss>>command_to_know;
      if(std::find(type_value.begin(),type_value.end(),command_to_know)!=type_value.end()){
        std::cout<<command_to_know<<" is a shell builtin"<<std::endl; 
        found=true;
      }
      if(!found && !command_to_know.empty()){
        std::string path_env=std::getenv("PATH");
        std::stringstream ss_path(path_env);
        std::string path;
        while(std::getline(ss_path,path, ':')){
          std::string full_path=path+'/'+command_to_know;
          if(access(full_path.c_str(),X_OK)==0){
            std::cout<<command_to_know<<" is "<<full_path<<std::endl;
            found=true;
            break;
          }
        }
      }
      if(!found){
        std::cout<<command_to_know<<": not found"<<std::endl;
      }
    }
    else{
      std::cout<<command<<": command not found"<<std::endl;
    }
  }
}
