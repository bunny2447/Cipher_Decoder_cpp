//============================================================================
// Name        : AT2.cpp
// Author      : AAron Metcalfe
// Version     : 2
// Copyright   : Your copyright notice
// Description : Caesar Cipher decryption
//============================================================================
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>
#include "header.hpp"

int main(int argc, char *argv[]) {
	std::string file_text_as_upper;
	std::ifstream file(argv[1]);
	std::string file_text;
	std::string file_save = argv[2];
	std::string return_text;
	char choice = 'y';
	char decryt_letter;

/// this if statement check to see if the file is open other wise it will output "file not found"
	if (file.is_open()) {
		/// gets each line from the file and outputs it to the screen
		while (getline(file, file_text)) {
			for (char &c : file_text) {
/// call the function to change all the lower cases letter to upcase letter so it can be run thought
/// the character_count function as it only accepted upper cases letters.
				if (is_alpha(c) && !is_upper(c)) {
					file_text_as_upper += to_upper(c);
				} else
					file_text_as_upper += c;
			}
		}
/// calls the function to count how many of each diffrent letter there is.
		character_count(file_text_as_upper);

		file.close();

		while (choice == 'y' || choice == 'Y') {
			std::cout << "please enter a letter to try and decypt the cipher"
					<< std::endl;
			std::cin >> decryt_letter;
			if (is_alpha(decryt_letter)) {
				std::cout
						<< "letter choose to try to decryption on the cipher is: "
						<< decryt_letter << std::endl;
				std::cout << " " << std::endl;
				decrypt(decryt_letter, file_text_as_upper, return_text);
			} else
				(std::cout << "Invaild input please input a letter a-z: "
						<< std::endl);

/// test another letter option user input
			std::cout << " " << std::endl;
			std::cout << "DO you want to try another letter? (y/n)"
					<< std::endl;
			std::cin >> choice;

			if (choice == 'n' || choice == 'N') {
///create text file to save decrypt toF
				std::ofstream Myfile(file_save);
				Myfile << return_text;
				std::cout << "====================| Saved to file " << file_save
						<< " |==================== " << std::endl;
				std::cout << " " << std::endl;
				Myfile.close();
			}
		}
	} else {
		std::cout
				<< "====================| File not found |===================="
				<< std::endl;

	}
	return 0;
}

