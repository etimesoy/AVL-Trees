#include "AVLTree.hpp"


AVLTree::AVLTree(int v) {
	this->value = v;
	this->height = 1;
	this->left = this->right = nullptr;
}

void AVLTree::update(AVLTree* tree) {
	this->value = tree->value;
	this->height = tree->height;
	this->left = tree->left;
	this->right = tree->right;
}

unsigned char AVLTree::getHeight() {
	return this ? this->height : 0;
}

int AVLTree::bfactor() {
	return this->right->getHeight() - this->left->getHeight();
}

void AVLTree::fixHeight() {
	this->height = std::max(this->left->getHeight(), this->right->getHeight()) + 1;
}

void AVLTree::rotateRight() {
	AVLTree* thisCopy = new AVLTree(this->value);
	thisCopy->update(this);

	AVLTree* newTree = thisCopy->left;
	thisCopy->left = newTree->right;
	newTree->right = thisCopy;
	thisCopy->fixHeight();
	newTree->fixHeight();

	this->update(newTree);
}

void AVLTree::rotateLeft() {
	AVLTree* thisCopy = new AVLTree(this->value);
	thisCopy->update(this);
	
	AVLTree* newTree = thisCopy->right;
	thisCopy->right = newTree->left;
	newTree->left = thisCopy;
	thisCopy->fixHeight();
	newTree->fixHeight();
	
	this->update(newTree);
}

void AVLTree::balance() {
	this->fixHeight();
	if (this->bfactor() == 2) {
		if (this->right->bfactor() < 0)
			this->right->rotateRight();
		this->rotateLeft();
	} else if (this->bfactor() == -2) {
		if (this->left->bfactor() > 0)
			this->left->rotateLeft();
		this->rotateRight();
	}
}

void AVLTree::insert(int val) {
	if (val < this->value) {
		if (this->left)
			this->left->insert(val);
		else
			this->left = new AVLTree(val);
	} else if (val > this->value) {
		if (this->right)
			this->right->insert(val);
		else
			this->right = new AVLTree(val);
	}
	this->balance();
}

bool AVLTree::find(int val) {
	if (val < this->value) {
		return this->left ? this->left->find(val) : false;
	} else if (val > this->value) {
		return this->right ? this->right->find(val) : false;
	} else {
		return true;
	}
}

AVLTree* AVLTree::findmin() {
	return this->left ? this->left->findmin() : this;
}

AVLTree* AVLTree::removemin() {
	if (this->left == nullptr)
		return this->right;
	this->left = this->left->removemin();
	this->balance();
	return this;
}

bool AVLTree::remove(int val) {
	if (!this->find(val))
		return false;
	if (val < this->value) {
		this->left->remove(val);
	} else if (val > this->value) {
		this->right->remove(val);
	} else {
		AVLTree* thisCopy = new AVLTree(this->value);
		thisCopy->update(this);
		AVLTree* leftCopy = thisCopy->left;
		AVLTree* rightCopy = thisCopy->right;
		if (!rightCopy) {
			this->update(leftCopy);
		} else {
			AVLTree* minTree = rightCopy->findmin();
			minTree->right = rightCopy->removemin();
			minTree->left = leftCopy;
			this->update(minTree);
		}
	}
	this->balance();
	return true;
}

std::string AVLTree::getString() {
	std::string leftInorder = this->left != nullptr ? this->left->getString() : "";
	std::string rightInorder = this->right != nullptr ? this->right->getString() : "";
	if (leftInorder.length() > 0) {
		leftInorder = "(" + leftInorder + ") ";
	}
	if (rightInorder.length() > 0) {
		rightInorder = " (" + rightInorder + ")";
	}
	return leftInorder + std::to_string(this->value) + rightInorder;
}

AVLTree::~AVLTree() {
	delete this->left;
	delete this->right;
}
