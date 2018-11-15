#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sstream>

#define READ 0
#define WRITE 1

class LoadBalancer {
	public:
		LoadBalancer(std::string input);
		void process_values();
		void fork_worker();
		int get_prc_cnt();
		std::string generate_worker_attributes(int fd[2]);
	private:
		std::string input;
		std::vector<std::vector<std::string> > values;
		const char * worker_path;
};