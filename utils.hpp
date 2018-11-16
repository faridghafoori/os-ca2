#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define READ 0
#define WRITE 1

using namespace std;

string int_to_string(int int_input){
    string string_output;
    stringstream ss;
    ss << int_input;
    string_output = ss.str();
    return string_output;
}

int string_to_int(string text) {
	int number;
	istringstream iss(text);
	iss >> number;
	return number;
}

vector<string> split(string text, char delimeter) {
	text += ' ';
    stringstream ss(text);
    string item;
    vector<string> splittedStrings;
    int cnt = 0;
    while (getline(ss, item, delimeter)) {
    	if(cnt == 0) {
	       	splittedStrings.push_back(item.substr(0, item.length()-1));
    		cnt++;
   	 	}
	 	else {
 		   	splittedStrings.push_back(item.substr(1, item.length()-2));
	 	}
    }
    return splittedStrings;
}

vector<string> standard_split(string text, char delimeter) {
    stringstream ss(text);
    string item;
    vector<string> splittedStrings;
    while (getline(ss, item, delimeter)) {
    	splittedStrings.push_back(item);
    }
    return splittedStrings;
}