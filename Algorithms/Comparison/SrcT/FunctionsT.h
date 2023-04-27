#include <iostream>
#include <map>
#include <fstream>
#include <limits.h>
#include "gameTreeT.h"


using namespace std;

void mainT();

map<int, gameTreeT*> ReadDataT(string pathToFolder);

vector<DataNodeT> findTopT(map<int, string> genres, map<int, gameTreeT*> &fullMap);

map<int, string> genrePickT();