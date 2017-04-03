#pragma once

#include <iostream>
#include <string>
#include <vector>

struct Team;

struct Player {
	std::string alphabet;
	Team *team;
};

struct Team {
	std::vector<Player*>players;
	void display();
};

struct Node {
	long key;
	Player *player;
	Node *parent, *left, *right;
	Node(Player *_player = nullptr, long value = 0, Node *_p = nullptr, Node *_l = nullptr, Node *_r = nullptr) : 
		player(_player), key(value), parent(_p), left(_l), right(_r) {};
	//~Node();
};

class SplayTree final {
	Node *root;

	void left_rotate(Node *);
	void right_rotate(Node *);
	void splay(Node *);
	void replace(Node *, Node *);
	Node* subtree_minimum(Node *);
	Node* subtree_maximum(Node *);
	void Destroy(Node *);
public:
	SplayTree(Node *_r = nullptr) : root(_r) {};
	~SplayTree();

	void insert(Player *, long key);
	void show(Node *, bool, int);
	void erase_element(int);
};