#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Visiting every floor of the tree one by one
void levelOrder(Node* root) {
    if (root == nullptr) return;

    // The waiting room for nodes
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        // Grab the person at the front of the line
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        // If they have kids, send them to the back of the line
        if (current->left != nullptr)
            q.push(current->left);
        
        if (current->right != nullptr)
            q.push(current->right);
    }
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;

    return 0;
}
