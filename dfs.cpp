#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void DFS(Node* root, vector<char>& result) {
    if (root == NULL) return;

    result.push_back(root->data);

    DFS(root->left, result);
    DFS(root->right, result);
}

int main() {

    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->left = new Node('F');
    root->right->right = new Node('G');

    vector<char> result;

    DFS(root, result);

    cout << "DFS Traversal: ";

    for(char c : result)
        cout << c << " ";
}