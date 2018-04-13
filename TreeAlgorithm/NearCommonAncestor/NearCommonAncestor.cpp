#include <iostream>
#include <stack>
using namespace std;

typedef struct NODE{
	NODE *left;
	NODE *right;
	int  data;
	bool visit;

	NODE() {
		left = NULL;
		right = NULL;
		data = 0;
		visit = false;
	}

} Node;
//-------------------------------
// Common Function
//-------------------------------
void Dfs(Node *curNode);
void DfsDynamic(Node *curNode);

//-------------------------------
// Resolution Function
//-------------------------------
Node* GetNearestAncestor(Node *root, int var1, int var2);

//-------------------------------
// Global Variables
//-------------------------------
stack<Node*> st;

//-------------------------------
int main() {

	Node *root = new Node;
	Node *b = new Node;
	Node *c = new Node;
	Node *d = new Node;
	Node *e = new Node;
	Node *f = new Node;
	Node *g = new Node;

	root->data = 20;
	b->data = 8;
	c->data = 22;
	d->data = 4;
	e->data = 12;
	f->data = 10;
	g->data = 14;

	root->left = b;
	root->right = c;
	b->left = d;
	b->right = e;
	e->left = f;
	e->right = g;

	// Call DFS
	Dfs(root);
  
	Node *nearNode = GetNearestAncestor(root, 4, 14);
	cout << endl << nearNode->data <<endl;

  delete root;
  delete b;
  delete c;
  delete d;
  delete e;
  delete f;

 return 0;
}

void Dfs(Node *curNode) {

	if(curNode == NULL)
		return;
	cout << curNode->data <<" ";
  Dfs(curNode->left);
	Dfs(curNode->right);
}

void DfsDynamic(Node *rootNode) {
	st.push(rootNode);
	while (st.size() > 0) {
		//Node *curNode = st.popi();
		//cout<< curNode->data;
		//if (curNode->right != NULL);
		//  st.push(curNode->right);
		//if (curNode->left != NULL);
		//  st.push(curNode->left);
	}
}

Node* GetNearestAncestor(Node *root, int var1, int var2) {
	while (root != NULL) {
		int rootData = root->data;

		if ( var1 < rootData && var2 < rootData)
      root = root->left;
		else if ( var1 > rootData && var2 > rootData)
      root = root->right;
		else
      return root;
  }
  // NULL TREE case
  return NULL;
}
