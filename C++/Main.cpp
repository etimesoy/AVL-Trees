#include <iostream>
#include "AVLTree.hpp"
using namespace std;

int main() {
    int arrLen;
    int first_element;
    int value;
    int val_del;
    int val_find;

    cin >> arrLen;
    cin >> first_element;

    AVLTree* tree = new AVLTree(first_element);
//    tree->insert(2);
    for (int i = 0; i < arrLen - 1; i++){
        cin >> value;
        tree->insert(value);
    }

    cin >> val_del;
    cin >> val_find;

    cout << tree->getString() << endl;
    cout << tree->find(val_fin) << endl;
    tree->remove(val_del);
    cout << tree->getString() << endl;

    delete tree;
    return 0;
}
