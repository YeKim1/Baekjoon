#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	char key;
	Node* right;
	Node* left;
	Node* par;

	Node(char k) : key(k), right(NULL), left(NULL), par(NULL) {};
};

class Tree {
public:
	Node* root;
	vector<Node*> v;

	Tree(Node* n) : root(n) { v.push_back(n); };
	
	void push(int k) {
		Node* node = new Node(k);
		v.push_back(node);
	}
	
	Node * findByKey(int k) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i]->key == k) return v[i];
		}
	}

	void preorder(Node* n) {
		if (!n) return;

		cout << n->key;
		preorder(n->right);
		preorder(n->left);
	}

	void inorder(Node* n) {
		if (!n) return;
		
		inorder(n->right);
		cout << n->key;
		inorder(n->left);
	}

	void postorder(Node* n) {
		if (!n) return;

		postorder(n->right);
		postorder(n->left);
		cout << n->key;
	}
};

int main() {
	int n;
	cin >> n;

	Node* node = new Node('A');
	Tree* tree = new Tree(node);
	for (int i = 1; i < n; i++) {
		tree->push('A' + i);
	}

	char k, right, left;

	for (int i = 0; i < n; i++) {
		cin >> k >> right >> left;
		Node* node = tree->findByKey(k);
		if (right != '.') {
			Node* rightNode = tree->findByKey(right);
			node->right = rightNode;
			rightNode->par = node;
		}
		if (left != '.') {
			Node* leftNode = tree->findByKey(left);
			node->left = leftNode;
			leftNode->par = node;
		}
	}

	tree->preorder(tree->root);
	cout << "\n";
	tree->inorder(tree->root);
	cout << "\n";
	tree->postorder(tree->root);
}