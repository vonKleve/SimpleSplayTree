#include "SplayTree.h"

inline Node::~Node()
{
	if (this)
	{
		if (left)
			delete left;
		if (right)
			delete right;
		if (parent)
			delete parent;
	}
}


inline void SplayTree::left_rotate(Node *x)
{
	Node *y = x->right;
	if (y)
	{
		x->right = y->left;
		y->left = x;
		if (x->right)
			x->right->parent = x;
		y->parent = x->parent;
	}

	if (!x->parent)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	x->parent = y;
}

inline void SplayTree::right_rotate(Node *x)
{
	Node *y = x->left;
	if (y)
	{
		x->left = y->right;
		y->right = x;
		if (x->left)
			x->left->parent = x;
		y->parent = x->parent;
	}

	if (!x->parent)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	x->parent = y;
}

void SplayTree::splay(Node *x)
{
	while (x->parent)
	{
		if (!x->parent->parent)
		{
			if (x->parent->left == x)
				right_rotate(x->parent);
			else
				left_rotate(x->parent);
		}
		else if (x->parent == x->parent->parent->left && x == x->parent->left)
		{
			right_rotate(x->parent->parent);
			right_rotate(x->parent);
		}
		else if (x->parent == x->parent->parent->right && x == x->parent->left)
		{
			right_rotate(x->parent);
			left_rotate(x->parent);
		}
		else if (x->parent == x->parent->parent->right && x == x->parent->right) 
		{
			left_rotate(x->parent->parent);
			left_rotate(x->parent);
		}
		else 
		{
			left_rotate(x->parent);
			right_rotate(x->parent);
		}
	}
}

void SplayTree::replace(Node *u, Node *v) {
	if (!u->parent) root = v;
	else if (u == u->parent->left) u->parent->left = v;
	else u->parent->right = v;
	if (v) v->parent = u->parent;
}

Node* SplayTree::subtree_minimum(Node *u) {
	while (u->left) u = u->left;
	return u;
}

Node* SplayTree::subtree_maximum(Node *u) {
	while (u->right) u = u->right;
	return u;
}

void SplayTree::Destroy(Node *temp)
{
	if (temp)
	{
		Destroy(temp->left);
		Destroy(temp->right);
		delete temp;
	}
}

SplayTree::~SplayTree()
{
	Destroy(root);
}

void SplayTree::insert(Player * pl,long key)
{
	Node *z = root;
	Node *p = nullptr;

	while (z)
	{
		p = z;
		if (key >= z->key)
			z = z->right;
		else
			z = z->left;
	}

	z = new Node(pl,key);
	z->parent = p;

	if (!p)
		root = z;
	else if (key >= p->key)
		p->right = z;
	else
		p->left = z;

	splay(z);
}

void SplayTree::show(Node *temp, bool flag, int level)
{
	if (flag)
		temp = root;
	if (temp)
	{
		
		show(temp->left, 0, level + 1);
		for (int i = 0; i < level; i++)
			std::cout << " ";
		std::cout << temp->key << " name:" << temp->player->alphabet << "\n";
		show(temp->right, 0, level + 1);
	}
}

void Team::display()
{
	for (auto it = players.begin(); it != players.end(); it++)
	{
		std::cout << (*it)->alphabet << " ";
	}
}
