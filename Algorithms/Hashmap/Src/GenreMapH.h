#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <list>
#include "NodeMapH.h"


class GenreMapH{
private:
    vector<NodeMapH*> genreMap{37, nullptr};
    vector<string> genreCode{37, ""};

public:
    GenreMapH();
    void insert(DataNodeH* node);
    const vector<NodeMapH *> &getGenreMap() const;
};
