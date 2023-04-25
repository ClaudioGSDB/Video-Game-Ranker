#include <iostream>
#include <map>
#include <fstream>
#include <limits.h>
#include "../GenreMap.h"

using namespace std;

GenreMap* ReadData(string pathToFolder);

vector<DataNode> findTop(map<int, string> genres, GenreMap* fullMap);

bool compareByRating(const DataNode& a, const DataNode& b);

map<int, string> genrePick();