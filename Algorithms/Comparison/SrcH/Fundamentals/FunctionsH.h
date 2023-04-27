#include <iostream>
#include <map>
#include <fstream>
#include <limits.h>
#include "../GenreMapH.h"

using namespace std;

void mainC();

void mainH();

GenreMapH* ReadDataH(string pathToFolder);

vector<DataNodeH> findTop(map<int, string> genres, GenreMapH* fullMap);

bool compareByRating(const DataNodeH& a, const DataNodeH& b);

map<int, string> genrePick();