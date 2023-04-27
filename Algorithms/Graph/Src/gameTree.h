//
// Created by torre on 4/24/2023.
//

#ifndef GRAPH_SRC_GAMETREE_H_
#define GRAPH_SRC_GAMETREE_H_
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "DataNode.h"
using namespace std;

class gameTree {
	struct treeNode{
		// is the node a tree
		bool isLeaf;
		// is there another node pointing to this one
		bool isChild;

		// games stored in the node sorted from lower to higher id number1
		vector<pair<int, DataNode>> games;


		// vector of pointers to child
		vector<treeNode*> children;

		treeNode(bool leaf = true, bool child = false);
	};

	// amount of key nodes a branch can have (n)
	const int keyN = 3;

	// amount of keys a leaf can have
	const int leafN = 20;

	// total amount of data elements on the tree.
	int count = 0;

	treeNode* root = nullptr;


public:

	gameTree();

	bool insert(DataNode &game, treeNode* parent = nullptr, bool correct = true);

	int leafAmount();

	void findMatch(map<int, string> const &genres, vector<DataNode> &ret, treeNode* parent = nullptr);

};

#endif //GRAPH_SRC_GAMETREE_H_
