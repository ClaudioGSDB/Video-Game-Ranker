#include "ReadData.h"
#include "DataNode.h"

using namespace std;

ReadData::ReadData(string pathToFolder)
{
    int genNum;
    string genName;

    int ID;
    string title;
    float rating;
    int numOfGenres;
    map<int, string> genres;
    int key;
    string value;


    for(int i = 0; i < 36; i++)
    {
        string fileName = pathToFolder + "/" + to_string(i) + ".txt";
        cout << fileName << endl;
        ifstream file(fileName);

        if (file.is_open()) //if file exists
        {
            string line;

            //store the genre first
            getline(file, line, '|');
            genNum = stoi(line);
            getline(file, line);
            //line.substr(line.find('|') + 1); NOT NEEDED I THINK
            string genName = line;

            while (getline(file, line, '|'))
            {
                //get ID
                ID = stoi(line);
                //get title
                getline(file, title, '|');
                //get rating
                getline(file, line, '|');
                rating = stof(line);
                //get numOfGenres
                getline(file, line, '|');
                numOfGenres = stoi(line);
                //get genres
                for(int j = 0; j < numOfGenres; j++)
                {
                    getline(file, line, '|');
                    key = stoi(line);
                    getline(file, value, '|');
                    genres[key] = value;
                }
            }
            cout << "File " << i << ".txt exists. Performing action A." << endl;
            file.close();
        }
        else
        {
            cout << "File " << i << ".txt does not exist. Performing action B." << endl;
        }
    }

}