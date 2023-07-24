#include <iostream>
#include <fstream>
#include <map>

#include "file_read_write.h"

const std::string high_scores_filename = "high_scores.txt";

void ReadFile(){
	std::ifstream in_file{high_scores_filename};
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return;
	}

	std::cout << "High scores table:" << std::endl;

	std::string username;
	int high_score = 0;
	while (true) {
		// Read the username first
		in_file >> username;
		// Read the high score next
		in_file >> high_score;
		// Ignore the end of line symbol
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}

		// Print the information to the screen
		std::cout << username << '\t' << high_score << std::endl;
	}
}


void WriteFile(std::string user_name, int attempts_count){
	// We should open the output file in the append mode - we don't want
	// to erase previous results.
	std::ifstream file{high_scores_filename, std::ios_base::app};
	if (!file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return;
	}

	std::map<std::string, int> best_results;

	std::string username;
	int high_score = 0;

	while (true) {
		// Read the username first
		file >> username;
		// Read the high score next
		file >> high_score;
		// Ignore the end of line symbol
		file.ignore();

		if (file.fail()) {
			break;
		}
		best_results[username] = high_score;
	}
	//file.close();
	best_results[user_name] = attempts_count;

	std::ofstream file_rewrite{high_scores_filename, std::ios_base::out};
	for(const auto& element : best_results){
		// Append new results to the table:
		file_rewrite << element.first << ' ';
		file_rewrite << element.second;
		file_rewrite << std::endl;
	}

} // end of score here just to mark end of the logic block of code