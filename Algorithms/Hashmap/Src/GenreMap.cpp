#include "GenreMap.h"

using namespace std;

GenreMap::GenreMap()
{

}

void GenreMap::insert(DataNode* node)
{
    map<int, string> genres = node->getGenres();
    for( auto gen : genres)
    {
        if (genreMap[gen.first] == nullptr)
        {
            genreMap[gen.first] = new NodeMap();
        }
        genreMap[gen.first]->insert(*node);
        genreCode[gen.first] = gen.second;
    }
}

const vector<NodeMap *> &GenreMap::getGenreMap() const {
    return genreMap;
}

