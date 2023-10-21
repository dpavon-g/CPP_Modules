#include <iostream>
#include <fstream>

std::string string_replace(std::string line, std::string old_string, std::string new_string) {

  std::string final_string;
  int old_len = old_string.length();
  int new_len = new_string.length();
  int i;
  int letter_counter;
  
  i = 0;
  while (line[i] != '\0') {
    if (line[i] == old_string[0]) {
      letter_counter = 0;
      while (line[i + letter_counter] == old_string[letter_counter] && line[i + letter_counter] != '\0') {
        letter_counter++;
      }
      if (old_string[letter_counter] == '\0') {
        i += letter_counter;
        final_string = final_string + new_string;
      }
    }
    final_string = final_string + line[i];
    if (line[i])
      i++;
  }
  final_string = final_string + '\0';
  (void)old_len;
  (void)new_len;
  return (final_string);

}

int main(int argc, char *argv[]) {
  int i;
  std::string new_line;

  i = 0;
  if (argc != 4) {
    std::cout << "Invalid number of arguments" << std::endl;
    return (-1);
  }
  else {
    std::string line;
    std::ifstream ini_file(
      argv[1]
      );
    if (ini_file) {
      std::ofstream out_file(std::string(argv[1])+".replace");
      if (out_file) {
        std::cout << "File " + std::string(argv[1]) + ".replace created" << std::endl;
        while (std::getline(ini_file, line)) {
            new_line = string_replace(line, std::string(argv[2]), std::string(argv[3]));
            out_file << new_line + "\n";
        }
        i = 0;
      }
      std::cout << "Copy finished \n";
    }
    else {
      std::cout << "Error. File doesn't exist." << std::endl;
    }
  }
}

