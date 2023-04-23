#include <iostream>
#include "ReadData.h"
#include "DataNode.h"

int main()
{
    map<int, string> genres;
    DataNode game(1, "A", 1.0, genres);
    return 0;
}
