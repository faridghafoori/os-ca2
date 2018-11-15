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

string LoadBalancer::generate_worker_attributes(int fd[2]) {
	string f_d = array_of_int_to_string(fd);
	string filter = "";
	filter += f_d + '&';
	for (int i = 0; i < values.size(); i++){
		filter += values[i][1] + '&';
	}
	return filter;
}

void LoadBalancer::fork_worker() {
	int fd[2], bytesRead;
	// generate data for send to worker (id and filters)
	string data = generate_worker_attributes(fd);
	// convert string to char for send with pipe
	char const_data[data.length()];
	for (int i = 0; i < data.length(); i++) {
		const_data[i] = data[i];
	}
	if (pipe(fd) == 0) {
		write (fd[WRITE], data.c_str(), strlen(data.c_str())+1);
		close (fd[WRITE]);
	} else {
		cerr << "error in write into pipe !" << endl;
	}
	execl(worker_path, "worker", const_data, (char*)0);
}

int LoadBalancer::get_prc_cnt() {
	for (int i = 0; i < values.size(); i++) {
		if (values[i][0] == "prc_cnt") {
			return string_to_int(values[i][1]);
		} 
	}
}
