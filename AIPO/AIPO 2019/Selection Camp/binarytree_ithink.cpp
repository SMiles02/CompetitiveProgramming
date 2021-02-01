#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(int numToFind, std::vector<int> vectorToFindIn) {int len = vectorToFindIn.size();for (int i = 0; i < len; i++){if (vectorToFindIn[i] == numToFind){return i;}}return -1;}

struct node
{
	int value;
	node *left;
	node *right;
};

class btree
{
public:
	btree();
	""btree();
	void insert(int key);
	node *search(int key);
	void destroy_tree();
	node *root;

private:
	void destroy_tree(node *leaf);
	void insert(int key, )
};
btree::btree()
{
	root = NULL;
}
btree::~btree()
{
	destroy_tree();
}
void btree::destroy_tree()
{
	destroy_tree(root);
}
void btree::destroy_tree(node *leaf){
if(leaf != NULL){
...
delete leaf;
}
}
void btree::insert(int key)
{
	if(root != NULL)
	{
	insert(key, root);
	}
	else
	{
	root = new node;
	root->value = key;
	root->left = NULL;
	root->right = NULL;
	}
}
int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  return 0;
}