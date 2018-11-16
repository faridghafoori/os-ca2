#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sstream>

class LoadBalancer {
	public:
		LoadBalancer(std::string input);
		void process_values();
		void fork_worker(std::string dir_name);
		int get_prc_cnt();
		std::string get_dir_name();
		std::string generate_worker_attributes();
	private:
		std::string input;
		std::vector<std::vector<std::string> > values;
		const char * worker_path;
};