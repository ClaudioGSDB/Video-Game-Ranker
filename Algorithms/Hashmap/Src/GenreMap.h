#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>
#include "NodeMap.h"


class GenreMap{
private:
    vector<NodeMap*> genreMap{37, nullptr};
    vector<string> genreCode{37, ""};

public:
    GenreMap();
    void insert(DataNode* node);
    const vector<NodeMap *> &getGenreMap() const;
};
