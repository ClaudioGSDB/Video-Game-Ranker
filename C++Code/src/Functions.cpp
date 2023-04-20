#include <regex>
#include <fstream>
#include <iostream>
#include <set>
#include "Functions.h"

using namespace std;

regex FD = regex(" - ");

void cleanText(string inFile)
{
    size_t pos;
    string line;
    set<string> noReps;
    //[[:ascii:]]+ Free Download .* REGEX
    ifstream readFile(inFile);
    ofstream writeFile("data/Clean Data.txt");

    if(readFile.is_open())
    {
        while(getline(readFile, line))
        {
            noReps.insert(line);
            //writeFile << line << endl;
        }
        std::set<string>::iterator it;
        for (it = noReps.begin(); it != noReps.end(); ++it) {
            writeFile << *it << endl;
        }
        readFile.close();
        writeFile.close();
    }
}
