#include "GenreMap.h"

using namespace std;

GenreMap::GenreMap() : genreMap(37, nullptr) {}

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
    }
}