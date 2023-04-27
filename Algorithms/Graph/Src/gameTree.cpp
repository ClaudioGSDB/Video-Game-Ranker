//
// Created by torre on 4/24/2023.
//

#include "gameTree.h"
gameTree::treeNode::treeNode(bool leaf, bool child) : isLeaf(leaf), isChild(child){}


gameTree::gameTree() = default;

// given a game, and a parent node (root by default)
bool gameTree::insert(DataNode &game, treeNode* parent, bool correct) {

	int belowi = -1;

	// this makes recursion works :)
	if(!parent){
		parent = root;
	}

	// tree empty
	if(!parent){
		// create a new leaf node
		parent = new treeNode();
		//push the game to the node
		parent->games.emplace_back(game.getId(), game);
		// update root
		root = parent;
	}
	// if tree not empty
	else{
		// if node is a leaf
		if(parent->isLeaf){
			// input the string
			parent->games.emplace_back(game.getId(), game);
			// sort the tree
			std::sort(parent->games.begin(), parent->games.end(),[](auto &a, auto&b){
				return a.first < b.first;});

		}
		// if root is a branch (go down one lvl and find the correct leaf node)
		else{
			// if id we're trying to insert is bigger than the last id on branch
			if(game.getId() > parent->games[parent->games.size() - 1].first){
				// save the position of the pointer to the branched node
				belowi = (int) parent->children.size() - 1;
				// check if the node below is correctly formatted
				correct = insert(game, parent->children[parent->children.size() - 1]);
			}
			// if id we're trying to insert is less than the current id we're checking
			else{
				// for every key in branch
				for(int child = 0 ; child < parent->children.size() ; child++){
					if(game.getId() < parent->games[child].first){
						// save the position of the pointer to the branched node
						belowi = child;
						// check if the node below is correctly formatted.
						correct = insert(game, parent->children[child]);
						break;
					}
				}
			}
		}
	}

	// if the node we're standing on exceeds its max size (10 or 4 - 1)
	if(parent->isLeaf and parent->games.size() > leafN ){
		// change the flag so that it can be fixed later on the function call.
		correct = false;
	}
	else if(!parent->isLeaf and parent->games.size() > keyN){
		correct = false;
	}

	// if there is a size discrepancy, either on the node we're standing on, or
	if(!correct){
		treeNode* left = nullptr;
		treeNode* right = nullptr;
		pair<int, DataNode> middle;
		vector<pair<int, DataNode>> del;
		int middleI  = 0;

		// if the node below is the one who changed the state
		if(belowi != -1){
			// the node below we're working on
			treeNode* belowN = parent->children[belowi];
			// we're working on belowN child of parent, splitting belowN

			// find the middle value
			middleI = (int) belowN->games.size() / 2;
			middle = make_pair(belowN->games[middleI].first, belowN->games[middleI].second);



			//if belowN isLeaf
			if(belowN->isLeaf){
				// whichever way it is , this is false
				belowN->isLeaf = false;
				// create left and right with isLeaf = true, and isChild = true
				left = new treeNode(true, true);
				right = new treeNode(true, true);


				// copy everything to the left of middle to the left treenode, and to the right inclusive to the right
				for(auto &i : belowN->games){
					if(i.first < middle.first){
						// copy to left
						left->games.emplace_back(i);
					}
					else if(i.first >= middle.first){
						right->games.emplace_back(i);
					}
					if(i.first != middle.first){
						del.emplace_back(i);
					}
				}

			}
			// if belowN !isLeaf
			else{
				// whichever way it is , this is false
				belowN->isLeaf = false;
				// create left and right with isLeaf = false, and isChild = true
				left = new treeNode(false, true);
				right = new treeNode(false, true);

				// copy everything to the left of middle to the left treenode, and to the right exclusive to the right
				for(auto &i : belowN->games){
					if(i.first < middle.first){
						// copy to left
						left->games.emplace_back(i);
					}
					else if(i.first > middle.first){
						right->games.emplace_back(i);
					}
					if(i.first != middle.first){
						del.emplace_back(i);
					}
				}
			}

			// cleanup the original node
			for(auto &i : del){
				if(i.first != middle.first){
					auto newEnd = remove(belowN->games.begin(), belowN->games.end(), i);
					belowN->games.erase(newEnd, belowN->games.end());
				}
			}

			// if middle is the biggest element in
			if(middle.first > parent->games[parent->games.size() - 1].first){
				// insert the game
				parent->games.push_back(middle);
				parent->children.push_back(left);
				parent->children.push_back(right);
			}
			else{
				for(int i = 0 ; i < parent->games.size() ; i++){
					if(middle.first < parent->games[i].first){
						// insert the game
						parent->games.insert(parent->games.begin() + i, middle);
						// insert the two pointers
						parent->children.insert(parent->children.begin() + i, left);
						parent->children.insert(parent->children.begin() + i + 1, right);
					}
				}
			}

			if(!belowN->children.empty()){
				for(int i = 0 ; i < belowN->children.size() ; i++){
					if(i <= middleI){
						// push to left children
						left->children.emplace_back(belowN->children[i]);
					}
					else{
						// push to right children
						right->children.emplace_back(belowN->children[i]);
					}
				}
			}

			// delete the old pointer
			auto newEnd = remove(parent->children.begin(), parent->children.end(), parent->children[belowi]);
			parent->children.erase(newEnd, parent->children.end());

			// if the node we're standing on exceeds its max size (10 or 4 - 1)
			if(parent->isLeaf and parent->games.size() > leafN ){
				// change the flag so that it can be fixed later on the function call.
				correct = false;
			}
			else if(!parent->isLeaf and parent->games.size() > keyN){
				correct = false;
			}
			else{
				correct = true;
			}
		}
		// if there is a node above us, let that one take care of it
		else if(parent->isChild){
			return correct;
		}
		// if the root has the wrong dimensions
		if(parent == root and !correct){
			// find the middle value
			middleI = (int) parent->games.size() / 2;
			middle = make_pair(parent->games[middleI].first, parent->games[middleI].second);

			// if starting the tree, root childs are all leaves
			if(parent->isLeaf){
				parent->isLeaf = false;
				// create left and right with isLeaf = true, and isChild = true
				left = new treeNode(true, true);
				right = new treeNode(true, true);

				// copy everything to the left of middle to the left treenode, and to the right inclusive to the right
				for(auto &i : parent->games){
					if(i.first < middle.first){
						// copy to left
						left->games.emplace_back(i);
					}
					else if(i.first >= middle.first){
						right->games.emplace_back(i);
					}
					if(i.first != middle.first){
						del.emplace_back(i);
					}
				}
			}
			// if more deep in the process, root childs are branches
			else{
				parent->isLeaf = false;
				// create left and right with isLeaf = false, and isChild = true
				left = new treeNode(false, true);
				right = new treeNode(false, true);

				// copy everything to the left of middle to the left treenode, and to the right exclusive to the right
				for(auto &i : parent->games){
					if(i.first < middle.first){
						// copy to left
						left->games.emplace_back(i);
					}
					else if(i.first > middle.first){
						right->games.emplace_back(i);
					}
					if(i != middle){
						del.emplace_back(i);
					}
				}
			}

			// cleanup the root
			for(auto &i : del){
				if(i.first != middle.first){
					auto newEnd = remove(parent->games.begin(), parent->games.end(), i);
					parent->games.erase(newEnd, parent->games.end());
				}
			}

			if(!parent->children.empty()){
				for(int i = 0 ; i < parent->children.size() ; i++){
					if(i <= middleI){
						// push to left children
						left->children.emplace_back(parent->children[i]);
					}
					else{
						// push to right children
						right->children.emplace_back(parent->children[i]);
					}
				}
			}
			parent->children.clear();
			parent->children.push_back(left);
			parent->children.push_back(right);
			correct = true;
		}
	}

	return correct;
}
int gameTree::leafAmount() {
	return count;
}
void gameTree::findMatch(map<int, string> const &genres, vector<DataNode> &ret, gameTree::treeNode *parent) {
	if(!parent){
		parent = root;
	}

	// if branch node, go through all the childs
	if(!parent->isLeaf){
		for(auto i : parent->children){
			findMatch(genres, ret, i);
		}
	}
	else{
		// for every game stored
		for(auto node : parent->games){
			if(all_of(genres.begin(), genres.end(), [&node](const auto& genre) {
				return node.second.getGenres().count(genre.first) != 0;
			}))
			{
				if(ret.size() < 5)
				{
					ret.emplace_back(node.second);
				}
				else if(node.second.getRating() > ret.back().getRating())
				{
					ret.back() = node.second;
				}
				sort(ret.begin(), ret.end(), [](auto &a, auto &b){return a.getRating() > b.getRating();});
			}
		}
	}
}
