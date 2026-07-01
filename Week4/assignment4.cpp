#include <iostream>
#include <vector>

void removeCopies(std::vector<int>& data) {

  // pointer starts at 1 because first item can't be duplicate
  //time complexdity is O(n) because I itterate through every item in the vector once
  int value_changing_pointer = 1;
  int current_unique_value = data[0];
  //Goes through the list for duplicates and
  //adds them to beginning of the list after last unique number
  //removes all the extra values after the uniques
  for (int unique_number_seeking_pointer = 1;
       unique_number_seeking_pointer < data.size();
       unique_number_seeking_pointer++) {
      if (current_unique_value != data[unique_number_seeking_pointer]) {
      current_unique_value = data[unique_number_seeking_pointer];
      data[value_changing_pointer] = current_unique_value;
      value_changing_pointer++;
    }
  }
  int num_of_unique_values = value_changing_pointer;
  data.resize(num_of_unique_values);
}

void isAnagram(std::string officer_name, std::string spy_name) {
  std::vector<int> officer_letter_counts(26);
  std::vector<int> anagram_letter_counts(26);
  //Time complexity is O(n) since the longest scaling operation is the for loop
  //which has to go through every character in a string

  //Vector allows for easy storage of number of times
  //a letter appears
  //which can then be compared to find if its an anagram
  for (int character : officer_name) {
    int char_location_in_vector = character - 97;
    officer_letter_counts[char_location_in_vector]++;
  }
  for (int character : spy_name) {
    int char_location_in_vector = character - 97;
    anagram_letter_counts[char_location_in_vector]++;
  }
  if (officer_letter_counts == anagram_letter_counts) {
    std::cout << "No impasta detected!\n";
  } else {
    std::cout << "IMPASTA! IMPASTA!\n";
  }
}

int main() {
  /*Use other test cases to make sure you program works*/
  std::vector<int> server = {1, 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 6};

  /*Print out the original server vector before function called*/
  for (auto data : server) {
    std::cout << data << " ";  // 1,1,2,2,2,3,3,4,5,6,6,6
  }

  removeCopies(server);

  /*Print out the modification of the server vector after function called*/
  for (auto data : server) {
    std::cout << data << " ";
  }

  std::cout << std::endl;

  /****************************TEST
   * ANAGRAM*************************************/

  isAnagram("syeda", "aysed");      // No imposter detected!
  isAnagram("angelo", "annabeth");  // IMPOSTER! IMPOSTER!

  return 0;
}
