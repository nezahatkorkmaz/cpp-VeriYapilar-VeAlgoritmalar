#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
int countFullNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int count = 0;
    if (root->left != NULL && root->right != NULL) {
        count += 1;
    }
    count += countFullNodes(root->left);
    count += countFullNodes(root->right);
    return count;
}

int main() {
    Node* root = new Node{8, NULL, NULL};
    root->left = new Node{4, NULL, NULL};
    root->right = new Node{12, NULL, NULL};
    root->left->left = new Node{2, NULL, NULL};
    root->left->right = new Node{5, NULL, NULL};
    root->right->left = new Node{9, NULL, NULL};
    root->right->right = new Node{14, NULL, NULL};
    root->left->left->right = new Node{3, NULL, NULL};
    root->right->left->right = new Node{10, NULL, NULL};
    root->left->right->right = new Node{7, NULL, NULL};
    
    cout << "Dolu Dugum Sayisi: " << countFullNodes(root) << endl;
    return 0;
}
