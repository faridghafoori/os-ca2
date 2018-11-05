#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

class LoadBalancer {
	public:
		LoadBalancer(std::string input);
		std::string get_input();
		void process_values();
		std::vector<std::string> split(std::string text, char ch);
	private:
		std::string input;
		std::vector<std::vector<std::string> > values;
};