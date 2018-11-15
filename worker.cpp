#include <iostream>
#include <string>

using namespace std;

void parse_data(string data) {
	cout << data << endl;
}

int main(int argc, char const *argv[]) {
	cout << "in worker  : " << argv[1] << endl;
	parse_data(argv[1]);
}