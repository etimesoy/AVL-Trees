#include <iostream>
#include "AVLTree.hpp"
using namespace std;

int main() {
    AVLTree* tree = new AVLTree(1);
    tree->insert(2);
    tree->insert(3);

    cout << tree->getString() << endl;
    cout << tree->find(2) << endl;
    tree->remove(2);
    cout << tree->getString() << endl;

    delete tree;
    return 0;
}
