#include "load_balancer.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
	string input;
	int status;
	while(true) {
		cout << "please enter your command : ";
		getline(cin, input);
		if(input == "quit") {
			break;
		}
		else {
			LoadBalancer lb(input);
			lb.process_values();
			int counter = 0;
			for (int i = 0; i < lb.get_prc_cnt(); i++) {
				counter++;
				if(fork() == 0) {
					// cout << "child: i = " << i << " pid : " << getpid() << endl;
					lb.fork_worker(lb.get_dir_name(), counter);
				} else {
					wait(&status);
				}
			}
		}
	}
	cout << "Enter Quit Command." << endl;
	return 0;
}