#include <string>
#include "ReadData.h"
#include "DataNode.h"
#include "HashMap.h"

using namespace std;

ReadData::ReadData(string pathToFolder)
{
    char delim = '`';
    int genNum;
    string genName;
    int numOfGenres;
    int key;
    string value;

    //game data
    int ID = 0;
    string title;
    float rating;
    map<int, string> genres;

    //Data structure
    HashMap fullMap;


    for(int i = 0; i < 50; i++)
    {
        string fileName = pathToFolder + "/" + to_string(i) + ".txt";
        ifstream file(fileName);


        if (file.is_open()) //if file exists
        {
            string line;
            //store the genre first
            getline(file, line, delim);
            genNum = stoi(line);
            getline(file, line, delim);
            //line.substr(line.find('|') + 1); NOT NEEDED I THINK
            string genName = line;

            while (getline(file, line, delim))
            {
                if(line == "\n")
                {
                    break;
                }
                //get ID
                ID = stoi(line);
                //get title
                getline(file, title, delim);
                //get rating
                getline(file, line, delim);
                rating = stod(line);
                //get numOfGenres
                getline(file, line, delim);
                numOfGenres = stoi(line);
                //get genres
                for(int j = 0; j < numOfGenres; j++)
                {
                    getline(file, line, delim);
                    key = stoi(line);
                    getline(file, value, delim);
                    genres[key] = value;
                }

                //HASHMAP CUSTOM HERE

                DataNode node(ID, title, rating, genres);
                fullMap.insert(node, genNum);

                //CUSTOM END HERE
            }
            //cout << "File " << i << ".txt exists. Performing action A." << endl;
            file.close();
        }
        else
        {
            //cout << "File " << i << ".txt does not exist. Performing action B." << endl;
        }
    }

}