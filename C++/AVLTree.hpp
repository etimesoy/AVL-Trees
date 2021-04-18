#pragma once
#include <string>


class AVLTree {
private:
	int value;
	unsigned char height;
	AVLTree* left;
	AVLTree* right;
	
	void update(AVLTree* tree);
	static unsigned char getHeight(AVLTree* tree);
	int bfactor();
	void fixHeight();
	void rotateRight();
	void rotateLeft();
	void balance();
	AVLTree* findmin();
	AVLTree* removemin();
	bool _remove(int v);

public:
	AVLTree(int v); // value

	void insert(int v);
	bool find(int v);
	bool remove(int v); // true, если получилось удалить, иначе - false

	std::string getString();

	~AVLTree();
};
