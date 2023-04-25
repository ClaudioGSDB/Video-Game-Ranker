#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Fundamentals/DataNodeH.h"

using namespace std;

class NodeMapH{
private:
    const int TABLE_SIZE = 1000;
    int numOfElements = 0;
    vector<vector<DataNodeH>> nodeMap;

public:
    NodeMapH();
    void insert(DataNodeH node);
    int hashing(int key);
    int getNumOfElements() const;
    const vector<vector<DataNodeH>> &getNodeMap() const;
};