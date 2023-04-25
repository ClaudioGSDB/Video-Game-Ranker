#include "NodeMap.h"


NodeMap::NodeMap()
{
    nodeMap.resize(TABLE_SIZE);
}

void NodeMap::insert(DataNode node)
{
    int key = hashing(node.getId());

    for (auto& oldNode : nodeMap[key]) {
        if (oldNode.getId() == node.getId()) {
            // Key already exists in the hash map
            return;
        }
    }
    // key doesn't exist in the hash map, add it
    nodeMap[key].emplace_back(node);
    numOfElements++;
}

int NodeMap::hashing(int key)
{
    return key % TABLE_SIZE;
}

int NodeMap::getNumOfElements() const {
    return numOfElements;
}

const vector<vector<DataNode>> &NodeMap::getNodeMap() const {
    return nodeMap;
}
