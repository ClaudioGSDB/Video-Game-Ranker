#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Fundamentals/DataNode.h"

using namespace std;

class NodeMap{
private:
    const int TABLE_SIZE = 1000;
    vector<vector<DataNode>> nodeMap;
public:
    NodeMap();
    void insert(DataNode node);
    int hashing(int key);
};