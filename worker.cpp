#include <iostream>
#include <string>
#include "utils.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
	vector<string> values = standard_split(argv[1], '&');
	string fd = values[0];
	string brand = values[1];
	string price = values[2];
	string dir = values[4];
	cout << fd << " - " << brand << " - " << price << " - " << dir << endl;
}