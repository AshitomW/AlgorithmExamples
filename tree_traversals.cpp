#include <iostream>

using namespace std;


struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preOrder(Node* root) {
    if (root == nullptr) return;
    
    cout << root->data << " "; // Announcements first!
    preOrder(root->left);      // Check on the left child
    preOrder(root->right);     // Check on the right child
}

// 2. In-order: Left kid, then Me, then Right kid (The "Sorted" way)
void inOrder(Node* root) {
    if (root == nullptr) return;

    inOrder(root->left);       // Wait for the left side to finish talking
    cout << root->data << " "; // Okay, my turn
    inOrder(root->right);      // Now the right side can go
}

// 3. Post-order: Kids first, Me last
void postOrder(Node* root) {
    if (root == nullptr) return;

    postOrder(root->left);     // Left side goes
    postOrder(root->right);    // Right side goes
    cout << root->data << " "; // I'll just clean up the mess at the end
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    cout << "Pre-order (Root-L-R): "; preOrder(root); cout << endl;
    cout << "In-order (L-Root-R): "; inOrder(root); cout << endl;
    cout << "Post-order (L-R-Root): "; postOrder(root); cout << endl;

    return 0;
}
