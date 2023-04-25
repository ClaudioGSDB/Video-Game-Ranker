#include "NodeMapH.h"


NodeMapH::NodeMapH()
{
    nodeMap.resize(TABLE_SIZE);
}

void NodeMapH::insert(DataNodeH node)
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

int NodeMapH::hashing(int key)
{
    return key % TABLE_SIZE;
}

int NodeMapH::getNumOfElements() const {
    return numOfElements;
}

const vector<vector<DataNodeH>> &NodeMapH::getNodeMap() const {
    return nodeMap;
}
