#include "NodeMap.h"


NodeMap::NodeMap()
{
    nodeMap.resize(TABLE_SIZE);
}

void NodeMap::insert(DataNode node)
{
    int key = hashing(node.getId());

    for (auto& oldNode : nodeMap[key]) {
        if (oldNode.getId() == key) {
            // Key already exists in the hash map
            return;
        }
    }
    // key doesn't exist in the hash map, add it
    nodeMap[key].emplace_back(node);
}

int NodeMap::hashing(int key)
{
    return key % TABLE_SIZE;
}