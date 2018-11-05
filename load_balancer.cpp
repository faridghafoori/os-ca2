#include "load_balancer.h"

using namespace std;

LoadBalancer::LoadBalancer(string _input) {
	input = _input;
}

string LoadBalancer::get_input() {
	return input;
}

void LoadBalancer::process_values() {
	std::vector<string> line = split(input, '-');
	for (int i = 0; i < line.size(); ++i) {
		values.push_back(split(line[i], '='));
	}
	for (int i = 0; i < values.size(); i++){
		for (int j = 0; j < values[i].size(); j++) {
			cout << values[i][j] << ' ';
		}
		cout << endl;
	}
}

vector<string> LoadBalancer::split(string text, char delimeter) {
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