#include <iostream>
#include <vector>
#include <queue>
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

void BFS(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    vector<char> result;

    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        result.push_back(current->data);

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }

    for(char c : result)
        cout << c << " ";
}

int main() {

    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->left = new Node('F');
    root->right->right = new Node('G');

    cout << "BFS Traversal: ";
    BFS(root);

}