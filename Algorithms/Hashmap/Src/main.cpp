#include <iostream>
#include "Fundamentals/FunctionsH.h"


int main()
{
    //input - put in function
    map<int, string> inputGenMap = genrePick();

    //creates the entire data structure
    GenreMapH* fullMap = ReadData("Data");

    //Search for top 5 games
    vector<DataNodeH> outputGames = findTop(inputGenMap, fullMap);

    int index = 0;
    for (auto elem : outputGames) {
        cout << index++ << " " << elem.getTitle() << endl;
        //cout << elem.getTitle() << " = " << elem.getRating() << endl;
    }
    return 0;
}
