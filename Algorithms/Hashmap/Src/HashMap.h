#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include "DataNode.h"

using namespace std;

class HashMap{
private:
    map<int, map<int, DataNode>> hashmap;
public:
    HashMap();
    void insert(DataNode node, int genNum);
    int hashing(int num);
};

/*
Try This ASK OFFICE HOURS
class HashMap {
private:
    const int TABLE_SIZE = 1000;  // The size of the hash table
    vector<list<pair<int, int>>> table;  // The hash table

public:
    HashMap() {
        table.resize(TABLE_SIZE);
    }

    void put(int key, int value) {
        int hash = key % TABLE_SIZE;
        auto& list = table[hash];

        // Search for the key in the linked list
        for (auto& kvp : list) {
            if (kvp.first == key) {
                // Key already exists in the hash map, update the value
                kvp.second = value;
                return;
            }
        }

        // Key not found in the linked list, add a new key-value pair
        list.emplace_back(key, value);
    }
};*/
