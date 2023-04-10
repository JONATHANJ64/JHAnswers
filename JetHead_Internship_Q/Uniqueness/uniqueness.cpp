#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  // Prompt user for input
  std::string input;
  std::cout << "Enter a string: ";
  std::getline(std::cin, input);

  // Create an unordered map to keep track of character counts
  std::unordered_map<char, int> char_counts;

  // Iterate through each character in the input string and increment the count
  // in the unordered map
for (std::string::size_type i = 0; i < input.size(); ++i) {
  char_counts[input[i]]++;
}
  // Check if there are any duplicate characters and print them out
  bool is_unique = true;
  std::cout << "Duplicate characters: ";
  for (auto const& pair : char_counts) {
    if (pair.second > 1) {
      std::cout << pair.first << " ";
      is_unique = false;
    }
  }

  // If there are no duplicate characters, print a message indicating that
  if (is_unique) {
    std::cout << "All characters are unique\n";
  } else {
    std::cout << "\n";
  }

  return 0;
}
