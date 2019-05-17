#include <iostream>
#include <cstring>

using namespace std;

struct Tree {
    int x;
    Tree *left, *right;
};

void add_leaf(Tree *&node, int data);

void my_print(Tree *tree);

bool target_function(Tree *tree1, Tree *tree2);

int main() {
    Tree *root1 = nullptr;
    char str1[] = "nstya";
    for (int i = 0; i < strlen(str1); i++) {
        add_leaf(root1, (int) str1[i]);
    }
    cout << "\nmy_print(root1)" << endl;
    my_print(root1);
    cout << endl;

    Tree *root2 = nullptr;
    char str2[] = "nastya";
    for (int i = 0; i < strlen(str2); i++) {
        add_leaf(root2, (int) str2[i]);
    }
    cout << "\nmy_print(root2)" << endl;
    my_print(root2);
    cout << endl;

    cout << "target_function\n";
    if (target_function(root1, root2)) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << endl;
//    system("pause");
}

bool target_function(Tree *tree1, Tree *tree2) {
    if (tree1 == nullptr && tree2 == nullptr) {
        return true;
    } else if (tree1 != nullptr && tree2 != nullptr) {
        if (tree1->x != tree2->x) {
            return false;
        } else {
            if (target_function(tree1->left, tree2->left)) {
                return target_function(tree1->right, tree2->right);
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
}

void my_print(Tree *tree) {
    if (tree == nullptr) {
        return;
    }
    cout << tree->x << " ";
    my_print(tree->left);
    my_print(tree->right);
}

void add_leaf(Tree *&node, int data) {
    if (node == nullptr) {
        Tree *temper = new Tree;
        temper->x = data;
        temper->left = nullptr;
        temper->right = nullptr;
        node = temper;
    } else {
        if (data <= node->x) {
            add_leaf(node->left, data);
        } else {
            add_leaf(node->right, data);
        }
    }
}
