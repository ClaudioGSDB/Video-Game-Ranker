#include "HashMap.h"
#include "ReadData.h"
#include "DataNode.h"

HashMap::HashMap(){}

void HashMap::insert(DataNode node, int genNum)
{
    int key = hashing(node.getId());
    hashmap[genNum][key] = node;
}

int HashMap::hashing(int num)
{

}