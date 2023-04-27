#include "DataNodeH.h"

DataNodeH::DataNodeH()
{
    ID = 0;
    title = "";
    rating = 0.0;
    genres.emplace(make_pair(0, ""));
}
DataNodeH::DataNodeH(int ID, string title, double rating, map<int, string> genres)
{
    this->ID = ID;
    this->title = title;
    this->rating = rating;
    this->genres = genres;
}

int DataNodeH::getId() const
{
    return ID;
}

const string &DataNodeH::getTitle() const
{
    return title;
}

float DataNodeH::getRating() const
{
    return rating;
}

const map<int, string>& DataNodeH::getGenres() const
{
    return genres;
}