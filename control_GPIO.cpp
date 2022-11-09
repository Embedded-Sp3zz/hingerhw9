// control_GPIO.cpp
//
// this script takes 3 command line arguments:
// 1. gpio number (used for output)
// 2. state - hi or low
// 3. gpio number (used for input)
//
// Writes state argument to gpio1
//
// Reads current value of gpio2
//
// Prints results for user
//
// example invocation: ./control_GPIO 60 hi 46

#include<sstream>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

#define GPIO_PATH "/sys/class/gpio/"

int writeGPIO(string gpio_number, string state){
	ofstream fs;
	string path(GPIO_PATH);

	ostringstream s;
	s << "gpio" << gpio_number;
	string name = string(s.str()) + "/";

	fs.open((path + name + "value").c_str());
	
	if(state == "hi"){
	       	fs << "1";
	}
	else{
	       	fs << "0";
	}
	fs.close();
	return 0;
}

string readGPIO(string gpio_number){
	ifstream fs;
	string path(GPIO_PATH);

	ostringstream s;
	s << "gpio" << gpio_number;
	string name = string(s.str()) + "/";

	fs.open((path + name + "value").c_str());
	string input;
	getline(fs, input);
	fs.close();
	return input;
}

int main(int argc, char* argv[]){
	if(argc!=4){
		cout << "Usage is: ./control_GPIO gpio_number state gpio_number" << endl;
		cout << "where gpio1 is set to output state, and gpio2 reads the input" << endl;
		return 2;
	}
	string gpio1(argv[1]);
	string state(argv[2]);
	string gpio2(argv[3]);
	cout << "Starting the control_GPIO program" << endl;
	cout << "The current GPIO path is: " << GPIO_PATH << endl;

	writeGPIO(gpio1, state);
	cout << "State: " <<  state << " written to " << gpio1 << endl;

	string readState;
	readState = readGPIO(gpio2);
	cout << "Value: " <<  readState << " read from " << gpio2 << endl;

	cout << "Finished the control_GPIO program" << endl;
	return 0;
}
	

