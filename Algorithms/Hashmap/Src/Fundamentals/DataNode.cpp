#include "DataNode.h"

DataNode::DataNode()
{
    ID = 0;
    title = "";
    rating = 0.0;
    genres.emplace(make_pair(0, ""));
}
DataNode::DataNode(int ID, string title, double rating, map<int, string> genres)
{
    this->ID = ID;
    this->title = title;
    this->rating = rating;
    this->genres = genres;
}

int DataNode::getId() const
{
    return ID;
}

const string &DataNode::getTitle() const
{
    return title;
}

float DataNode::getRating() const
{
    return rating;
}

const map<int, string>& DataNode::getGenres() const
{
    return genres;
}