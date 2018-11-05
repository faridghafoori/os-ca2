#include "load_balancer.h"

using namespace std;

int main(int argc, char const *argv[]) {
	string input;
	cout << "please enter your command : ";
	getline(cin, input);
	LoadBalancer lb(input);
	if(fork() == 0) {
		cout << "child" << getpid() << endl;
		lb.process_values();
	}
	else {
		cout << "parent" << endl;
	}
	return 0;
}