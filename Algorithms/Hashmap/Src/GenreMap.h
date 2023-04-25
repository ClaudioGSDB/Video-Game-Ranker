#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>
#include "NodeMap.h"


class GenreMap{
private:
    vector<NodeMap*> genreMap;
public:
    GenreMap();
    void insert(DataNode* node);
};
