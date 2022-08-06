#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include "header.hpp"

/// this is the function that counts amount of letters in the file
void character_count(std::string file_text) {

	char aplhabet_upper[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
			'J', 'k', 'l', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
			'W', 'X', 'Y', 'Z' };

	char aplhabet_lower[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
			'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
			'w', 'x', 'y', 'z' };
	std::string code = file_text;
	int i = 0;
	int j = 0;
	int amount[26];
	int top1 = -1;
	int top2 = -1;
	int top3 = -1;
	int length = 0;

	code.erase(remove(code.begin(), code.end(), ' '), code.end());
	length = (int) code.length();
	/// loops thought the string
	for (j = 0; j < 26; j++) {
		amount[j] = 0;
		// loops though the alphabet
		for (i = 0; i < length; i++) {
			if (code[i] == aplhabet_lower[j] || code[i] == aplhabet_upper[j]) {
				amount[j]++;
			}

		}
		// prints out letter and amount
		std::cout << (char) aplhabet_upper[j] << " : " << amount[j]
				<< std::endl;
		std::cout << "-------------" << std::endl;

	}
	/// goes though and finds the highest letter count
	for (i = 0; i <= 26; i++) {
		if (amount[i] >= amount[top1]) {
			top3 = top2;
			top2 = top1;
			top1 = i;
			/// replaces amounts when it finds a new second top
		} else if (amount[i] >= amount[top2]) {
			top3 = top2;
			top2 = i;
			/// replaces amounts when it finds a new second top
		} else if (amount[i] > amount[top3]) {
			top3 = i;
		}

	}
	std::cout << "-------------" << std::endl;
	std::cout << "most frequent letters are" << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << (char) aplhabet_upper[top1] << " : " << amount[top1]
			<< std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << (char) aplhabet_upper[top2] << " : " << amount[top2]
			<< std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << (char) aplhabet_upper[top3] << " : " << amount[top3]
			<< std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << " " << std::endl;
}

///------------------------------------------------------------------------------------------------------------
void print_analysis_array() {

}
///------------------------------------------------------------------------------------------------------------
/// changes lower cases letters to up so they can be counted
char to_upper(char character) {
	return (int) character - 32;
}
///------------------------------------------------------------------------------------------------------------
bool is_upper(char character) {
	if (character >= 65 && character <= 90) {
		return true;
	} else
		return false;
}
///------------------------------------------------------------------------------------------------------------
bool is_alpha(char letter) {
	if (((int) letter >= 65 && (int) letter <= 90)
			|| ((int) letter >= 97 && (int) letter <= 122)) {
		return true;
	} else
		return false;
}
///------------------------------------------------------------------------------------------------------------
/// opens the read file for the code to use
int open_file(int argc, char *argv[]) {
	std::string file_text;
	std::cout << argv[1] << std::endl;

	std::ifstream file(argv[1]);
/// this if statement check to see if the file is open other wise it will output "file not found"
	if (file.is_open()) {
		/// gets each line from the file and outputs it to the screen
		while (getline(file, file_text)) {
			std::cout << file_text;
			return true;
		}
		file.close();
	} else {
		std::cout << "File not found" << std::endl;
		return false;
	}
	std::cout << file_text << std::endl;
	return 0;
}
///---------------------------------------------------------------------------------------------------------------
/// decryption cipher
///this functions will decipher the code with the giving input decrptying key
void decrypt(char decryt_letter, std::string &file_text,
		std::string &return_text) {

	std::string test = file_text;
	std::string output;
	int length = test.length();

	int decrypt_number = (int) decryt_letter
			- (is_upper(decryt_letter) ? 65 : 97);
	for (int i = 0; i < length; i++) {
		int temp =
				((int) test[i] < 65 + decrypt_number && (int) test[i] >= 65)
						|| ((int) test[i] < 97 + decrypt_number
								&& (int) test[i] >= 97) ?
						(int) test[i] + 26 : (int) test[i];
		output += (temp < 65) ? temp : temp - decrypt_number;
	}
	return_text = output;
	std::cout << " " << std::endl;
	std::cout << "====================| 100 character sample "
			<< "|==================== " << std::endl;
	std::cout << " " << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << return_text[i];
	}
	std::cout << " " << std::endl;
	std::cout << "================================================================ "
			<< std::endl;
	std::cout << " " << std::endl;
}

