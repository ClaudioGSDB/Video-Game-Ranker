#include <iostream>
#include <map>

using namespace std;

class DataNode{
private:

private:
    int ID;
    string title;
    double rating;
    map<int, string> genres;
public:
    DataNode();
    DataNode(int ID, string title, double rating, map<int, string> genres);

    int getId() const;
    const string &getTitle() const;
    float getRating() const;
    const map<int, string> &getGenres() const;
};