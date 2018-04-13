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

queue<Node*> q;
stack<Node*> st;

void dfs(Node *curNode);
void dfsDynamic(Node *curNode);

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

void dfs(Node *curNode) {

	if(curNode == NULL)
		return;
	cout << curNode->data <<" ";
  dfs(curNode->left);
	dfs(curNode->right);
}

void dfsDynamic(Node *rootNode) {
	st.push(rootNode);
	while (st.size() > 0) {
		Node *curNode = st.pop();
		cout<< curNode->data;
		if (curNode->right != NULL);
		  st.push(curNode->right);
		if (curNode->left != NULL);
		  st.push(curNode->left);
	}
}


}
