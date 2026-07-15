#include <fstream>
#include <iostream>
#include <string>

int main() {
  // open the file
  std::ifstream FileReaderObject("CatStory.txt");

  // check if it actually opened
  if(!FileReaderObject.is_open()){
    std::cout << "File not found!" << std::endl;
    return 0;
  }
  std::string line = {};
 // while(std::getline())){

 // }

  // Read the file line by line

  // Close the file
}