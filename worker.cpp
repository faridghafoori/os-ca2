#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fstream>
#include "utils.hpp"
#include <dirent.h>

#define DATA_SIZE 200

using namespace std;

vector<string> read_from_file(string dir_folder_name, string file_name) {
	vector<string> lines;
	ifstream dir_file;
	dir_file.open(dir_folder_name + "/" + file_name);
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

void data_filtering(vector<string> data, int cnt, int num_of_files, int worker_id) {
	cout << "cnt : " << cnt << endl;
	cout << "worker_id : " << worker_id-1 << endl;
	if(cnt == worker_id-1) {
		cout << "worker_id = cnt = " << cnt << endl;
	}
	// int i = 0;
	// cout << cnt << endl;
	// cout << num_of_files << endl;
	// cout << file_name << endl;
	// cout << "-------------------" << endl;
	// if (cnt == num_of_files - 1) {
	// 	for (int i = 0; i < data.size(); i++) {
	// 		cout << data[i] << endl;
	// 	}
	// }
	// for(int i = 0; i < data.size(); i++) {
	// 	cout << data[i] << endl;
	// }
}

void files_proccess(string dir_folder, vector<string> files, int worker_id) {
	for (int i = 0; i < files.size(); i++) {
		data_filtering(read_from_file(dir_folder, files[i]), i, files.size(), worker_id);
    }
}

int main(int argc, char const *argv[]) {
	int fd0 = string_to_int(argv[1]);
	int fd1 = string_to_int(argv[2]);
	int counter = string_to_int(argv[4]);
	int prc_cnt = string_to_int(argv[5]);
	string dir_folder = "./dir/";
	string dir_name = argv[3];
	dir_folder += dir_name;

	// read form unnamed pipe
  	char data[DATA_SIZE];
	read (fd0, data, DATA_SIZE);
    close (fd1);
    cout << "Read from pipe: " << data << endl;
    vector<string> data_after_parse = standard_split(data, '&');
    vector<vector<string> > datas;
    for (int i = 0; i < data_after_parse.size(); i++) {
    	datas.push_back(standard_split(data_after_parse[i], '-'));
    }

    // open and read files from directory name
    struct dirent *pDirent;
    DIR *pDir;
    vector<string> files_name;
    files_name.clear();
    pDir = opendir(dir_folder.c_str());
    if (pDir == NULL) {
        cout << "Cannot open directory '" << dir_folder.c_str() << "'" << endl;
        exit(1);
    }
    while ((pDirent = readdir(pDir)) != NULL) {
    	files_name.push_back(pDirent->d_name);
    }
    closedir (pDir);

    // remove [.] and [..] form the vector
    files_name.erase(files_name.begin(), files_name.begin() + 2);
    if(files_name.size() == 0) {
	    cout << "There isn't files in directory !" << endl;
    } else {
	    for (int i = 0; i <= files_name.size(); i++) {
	    	if (i == counter) {
		    	files_proccess(dir_folder, files_name, i);
	    	}
	    }
    }
}