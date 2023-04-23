//
// Created by torre on 4/23/2023.
//

#ifndef DATA_SORT__DATASORT_H_
#define DATA_SORT__DATASORT_H_
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <regex>
#include <fstream>
using namespace std;

class dataSort {
	map<string, regex> regexCase;

	//set<int> gamesVisited;

	map<int, ofstream> genreFiles;

	void commaRemove(string &line);

public:
	set<int> gamesVisited;
	// given a formatted input file, return the categories sorted by file in the output folder
	dataSort(string inputFile, string ouputPath);

};

#endif //DATA_SORT__DATASORT_H_
