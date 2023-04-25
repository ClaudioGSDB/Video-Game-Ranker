#include <iostream>
#include <map>

using namespace std;

class DataNodeH{
private:
    int ID;
    string title;
    double rating;
    map<int, string> genres;
public:
    DataNodeH();
    DataNodeH(int ID, string title, double rating, map<int, string> genres);

    int getId() const;
    const string &getTitle() const;
    float getRating() const;
    const map<int, string> &getGenres() const;


};