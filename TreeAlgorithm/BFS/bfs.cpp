#include <iostream>
#include <queue>
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

queue<Node*> q;

void bfs(Node *curNode);
void dfs(Node *curNode);

int main() {

	Node *a = new Node;
	Node *b = new Node;
	Node *c = new Node;
	Node *d = new Node;
	Node *e = new Node;
	Node *f = new Node;
	Node *g = new Node;

	a->data = 1;
	b->data = 2;
	c->data = 3;
	d->data = 4;
	e->data = 5;
	f->data = 6;
	g->data = 7;

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;

	a->visit = true;
  q.push(a);


	bfs(a);
	cout<<endl;
	dfs(a);

  delete a;
  delete b;
  delete c;
  delete d;
  delete e;
  delete f;

 return 0;
}


void bfs(Node *curNode) {

  if (curNode == NULL)
		return;

	if (curNode != NULL && curNode->visit == true)
    q.pop();
		cout << curNode->data;
 
	if( curNode->left!= NULL) {
	  curNode->left->visit = true;
	  q.push(curNode);
	}

	if( curNode->right!= NULL) {
	  curNode->right->visit = true;
	  q.push(curNode);
	}
	bfs(curNode->left);
	bfs(curNode->right);
}

void dfs(Node *curNode) {

	if(curNode == NULL)
		return;
	cout << curNode->data <<" ";
  dfs(curNode->left);
	dfs(curNode->right);
}

