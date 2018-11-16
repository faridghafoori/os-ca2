#include "load_balancer.hpp"
#include "utils.hpp"

using namespace std;


LoadBalancer::LoadBalancer(string _input) {
	input = _input;
	worker_path = "/Users/farid/Desktop/Uni/OS/Projects/Project2/os-ca2/worker";	
}

void LoadBalancer::process_values() {
	std::vector<string> line = split(input, '-');
	for (int i = 0; i < line.size(); ++i) {
		values.push_back(split(line[i], '='));
	}
}

string LoadBalancer::generate_worker_attributes() {
	string filter = "";
	for (int i = 0; i < values.size(); i++){
		for (int j = 0; j < values[i].size(); j++) {
			filter += values[i][j] + '-';
		}
		filter += '&';
	}
	return filter;
}

void LoadBalancer::fork_worker(string dir_name) {
	int fd[2];
	cout << fd << endl;
	if (pipe(fd) == 0) {
		const char* fd0 = int_to_string(fd[READ]).c_str();
		const char* fd1 = int_to_string(fd[WRITE]).c_str();
		// generate data for send to worker (id and filters)
		string data = generate_worker_attributes();
		write (fd[WRITE], data.c_str(), strlen(data.c_str())+1);
		close (fd[WRITE]);
		execl (worker_path, "worker", fd0, fd1, dir_name.c_str(), (char*)0);
	} else {
		cerr << "error in write into pipe !" << endl;
	}
}

int LoadBalancer::get_prc_cnt() {
	for (int i = 0; i < values.size(); i++) {
		if (values[i][0] == "prc_cnt") {
			return string_to_int(values[i][1]);
		} 
	}
	return 1;
}

string LoadBalancer::get_dir_name() {
	for (int i = 0; i < values.size(); i++) {
		if (values[i][0] == "dir") {
			return values[i][1];
		}
	}
	return " ";
}