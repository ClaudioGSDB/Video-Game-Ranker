#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

using namespace std;

class HashMap{
private:
    vector<unordered_map<int, string>> hashmap;
public:
    HashMap();
    void insert();
};
