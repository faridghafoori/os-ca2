#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fstream>
#include "utils.hpp"

#define DATA_SIZE 200

using namespace std;

vector<string> read_from_file(string file_name) {
	vector<string> lines;
	ifstream dir_file;
	dir_file.open("./dir/" + file_name);
	string line;
	if (dir_file.is_open()) {
		lines.clear();
		while (getline(dir_file, line)) {
		    lines.push_back(line);
		}
	} else {
		cout << "There isn't directory with this name !" << endl;
		exit(0);
	}
	dir_file.close();
	return lines;
}

int main(int argc, char const *argv[]) {
	int fd0 = string_to_int(argv[1]);
	int fd1 = string_to_int(argv[2]);
	string dir_name = argv[3];

  	char data[DATA_SIZE];
	read (fd0, data, DATA_SIZE);
    close (fd1); /* Close used end */
    cout << "Read from pipe: " << data << endl;
    vector<string> data_after_parse = standard_split(data, '&');
    vector<vector<string> > datas;
    for (int i = 0; i < data_after_parse.size(); i++) {
    	datas.push_back(standard_split(data_after_parse[i], '-'));
    }

    // vector<string> file_lines = read_from_file(data_after_parse[3]);
    
    

	for (int i = 0; i < datas.size(); i++)
	{
		for (int j = 0; j < datas[i].size(); j++)
		{
			cout << datas[i][j] << " ";
		}
		cout << endl;
	}
}