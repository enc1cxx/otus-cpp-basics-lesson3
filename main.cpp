#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

#include "file_read_write.h"


int main(int argc, char *argv[]) {

    int current_value = 0;
    int max_value = 100;
    std::string user_name = "";
    int attempts_count = 0;
    bool arg_level = false;
    bool arg_max = false;

    for (int i = 0; i < argc; ++i) {
        if(std::string(argv[i]) == "-table") {
            file_read_write::ReadFile();
            return 0;
        }
        if(std::string(argv[i]) == "-max") {
            arg_max = true;
            max_value = atoi(argv[i + 1]);
        }
        if(std::string(argv[i]) == "-level") {
            arg_level = true;
            if(atoi(argv[i + 1]) == 1) {
                max_value = 10;
            }else if(atoi(argv[i + 1]) == 2){
                max_value = 50;
            }else if(atoi(argv[i + 1]) == 3){
                max_value = 100;
            }else{
                std::cout << "Incorrect parameter of -level" << std::endl;
                return -1;
            }
        }
        if(arg_level && arg_max){
            std::cout << "Error: simultaneous use of -level and -max is not allowed" << std::endl;
            return -1;
        }
	}

    std::mt19937_64 gen(std::time(nullptr));
    std::uniform_int_distribution<int> distrib(0, max_value - 1);

    const int random_value = distrib(gen);

    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::cin >> user_name;

    std::cout << "Enter your guess:" << std::endl;
    do {
        ++attempts_count;

		std::cin >> current_value;

		if (current_value < random_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else if (current_value > random_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else {
			std::cout << "you win! Attempts = " << attempts_count << std::endl << std::endl;
			break;
		}
        
	} while(true);

    file_read_write::WriteFile(user_name, attempts_count);
    file_read_write::ReadFile();



	return 0;
}