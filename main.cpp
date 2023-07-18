#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



int current_value = 0;
int max_value = 100;
string username = "";
int attempt_counter = 0;
bool arg_level = false;
bool arg_max = false;


int main(int argc, char *argv[]) {

    for (int i = 0; i < argc; ++i) {
        if(string(argv[i]) == "-table") {
            return 0;
        }
        if(string(argv[i]) == "-max") {
            arg_max = true;
            max_value = atoi(argv[i + 1]);
        }
        if(string(argv[i]) == "-level") {
            arg_level = true;
            if(atoi(argv[i + 1]) == 1) {
                max_value = 10;
            }else if(atoi(argv[i + 1]) == 2){
                max_value = 50;
            }else if(atoi(argv[i + 1]) == 3){
                max_value = 100;
            }else{
                cout << "Incorrect parameter of -level" << endl;
                return -1;
            }
        }
        if(arg_level && arg_max){
            cout << "Error: simultaneous use of -level and -max is not allowed" << endl;
            return -1;
        }
	}


    srand(time(NULL));
    const int random_value = rand() % max_value;
    cout << "Hi! Enter your name, please:"s << endl;
    cin >> username;

    cout << "Enter your guess:"s << endl;
    do {
        ++attempt_counter;

		cin >> current_value;

		if (current_value < random_value) {
			cout << "X > "s << current_value << endl;
		}
		else if (current_value > random_value) {
			cout << "X < "s << current_value << endl;
		}
		else {
			cout << "you win! Attempts = "s << attempt_counter << endl;
			break;
		}
        
	} while(true);

	return 0;
}