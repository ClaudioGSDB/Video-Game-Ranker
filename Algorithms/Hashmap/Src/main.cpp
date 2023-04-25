#include <iostream>
#include "Fundamentals/Functions.h"


int main()
{
    //input - put in function
    map<int, string> inputGenMap = genrePick();

    //creates the entire data structure
    GenreMap* fullMap = ReadData("Data");

    //Search for top 5 games
    vector<DataNode> outputGames = findTop(inputGenMap, fullMap); //BUG HERE

    for (auto elem : outputGames) {
        cout << elem.getTitle() << " " << elem.getRating() << endl;
    }
    return 0;
}
