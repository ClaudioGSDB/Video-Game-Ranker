#include <iostream>
#include <map>
#include <fstream>
#include <limits.h>
#include "gameTreeT.h"


using namespace std;

void mainT();

map<int, gameTreeT*> ReadData(string pathToFolder);

vector<DataNodeT> findTop(map<int, string> genres, map<int, gameTreeT*> &fullMap);

bool compareByRating(const DataNodeT& a, const DataNodeT& b);

map<int, string> genrePick();