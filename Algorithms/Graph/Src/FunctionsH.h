#include <iostream>
#include <map>
#include <fstream>
#include <limits.h>
#include "gameTree.h"


using namespace std;

void mainT();

map<int, gameTree*> ReadData(string pathToFolder);

vector<DataNode> findTop(map<int, string> genres, map<int, gameTree*> &fullMap);

bool compareByRating(const DataNode& a, const DataNode& b);

map<int, string> genrePick();