#include "load_balancer.h"

using namespace std;

int main(int argc, char const *argv[]) {
	string input;
	cout << "please enter your command : ";
	getline(cin, input);
	LoadBalancer lb(input);
	if(fork() == 0) {
		cout << "child" << endl;
		cout << getpid() << endl;
		lb.process_values();
		lb.fork_worker();
	}
	else {
		cout << "parent" << endl;
	}
	return 0;
}