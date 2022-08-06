#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>



void character_count(std::string file_text );

char to_upper(char file_output);

int open_file(int argc, char *argv[]);

void decrypt(char decryt_letter, std::string &file_text, std::string &return_text);

bool is_alpha(char letter);

bool is_upper(char character) ;
