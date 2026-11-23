
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Binary
{
private:
    Node *root;

public:
    Binary()
    {
        root = NULL;
    }

    // Create Binary Tree
    Node* create()
    {
        int value;

        cout << "\nEnter node value (-1 for no node): ";
        cin >> value;

        if (value == -1)
            return NULL;

        Node *newNode = new Node;
        newNode->data = value;

        cout << "Enter left child of " << value;
        newNode->left = create();

        cout << "Enter right child of " << value;
        newNode->right = create();

        return newNode;
    }

    void build()
    {
        cout << "\nCreate Binary Tree\n";
        root = create();
    }

    // Inorder Traversal
    void inorder(Node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    // Preorder Traversal
    void preorder(Node *temp)
    {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    // Postorder Traversal
    void postorder(Node *temp)
    {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

    void displayinorder()
    {
        cout << "\nInorder Traversal: ";
        inorder(root);
    }

    void displaypreorder()
    {
        cout << "\nPreorder Traversal: ";
        preorder(root);
    }

    void displaypostorder()
    {
        cout << "\nPostorder Traversal: ";
        postorder(root);
    }
};

int main()
{
    Binary B;
    int choice;

    B.build();

    cout << "\n1. Display Inorder";
    cout << "\n2. Display Preorder";
    cout << "\n3. Display Postorder";

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            B.displayinorder();
            break;

        case 2:
            B.displaypreorder();
            break;

        case 3:
            B.displaypostorder();
            break;

        default:
            cout << "\nInvalid Choice!";
    }

    return 0;
}
