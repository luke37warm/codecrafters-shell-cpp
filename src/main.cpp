#include <iostream>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr 
  // usually it waits until the buffer is full
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // TODO: Uncomment the code below to pass the first stage
  while(true){
    std::cout << "$ ";
    std::string command;
    std::getline(std::cin, command);
    if(command=="exit") break;
    std::cout<<command<<": command not found"<<std::endl;
  }
}
