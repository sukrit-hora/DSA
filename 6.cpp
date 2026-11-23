
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node* root;

    // Insert Node
    Node* insert(Node* temp, int value)
    {
        if (temp == NULL)
        {
            return new Node(value);
        }

        if (value < temp->data)
        {
            temp->left = insert(temp->left, value);
        }
        else if (value > temp->data)
        {
            temp->right = insert(temp->right, value);
        }
        else
        {
            cout << "Duplicate Employee ID not allowed!\n";
        }

        return temp;
    }

    // Copy BST
    Node* copyTree(Node* temp)
    {
        if (temp == NULL)
        {
            return NULL;
        }

        Node* newNode = new Node(temp->data);

        newNode->left = copyTree(temp->left);
        newNode->right = copyTree(temp->right);

        return newNode;
    }

    // Find Height
    int findHeight(Node* temp)
    {
        if (temp == NULL)
        {
            return -1;
        }

        int leftHeight = findHeight(temp->left);
        int rightHeight = findHeight(temp->right);

        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }

    // Print Leaf Nodes
    void printLeafNodes(Node* temp)
    {
        if (temp == NULL)
        {
            return;
        }

        if (temp->left == NULL && temp->right == NULL)
        {
            cout << temp->data << " ";
            return;
        }

        printLeafNodes(temp->left);
        printLeafNodes(temp->right);
    }

public:

    // Constructor
    BST()
    {
        root = NULL;
    }

    // Insert Employee ID
    void insertID(int value)
    {
        root = insert(root, value);
    }

    // Level Order Traversal
    void levelOrder(Node* temp)
    {
        if (temp == NULL)
        {
            cout << "Tree is Empty!\n";
            return;
        }

        queue<Node*> q;
        q.push(temp);

        while (!q.empty())
        {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != NULL)
            {
                q.push(current->left);
            }

            if (current->right != NULL)
            {
                q.push(current->right);
            }
        }

        cout << endl;
    }

    // Display Original BST
    void displayOriginal()
    {
        cout << "\nOriginal BST (Level Order): ";
        levelOrder(root);
    }

    // Copy BST
    BST* copyBST()
    {
        BST* newBST = new BST();
        newBST->root = copyTree(root);

        return newBST;
    }

    // Display Copied BST
    void displayCopied()
    {
        cout << "\nCopied BST (Level Order): ";
        levelOrder(root);
    }

    // Display Height
    void displayHeight()
    {
        cout << "\nHeight of BST = " << findHeight(root) << endl;
    }

    // Display Leaf Nodes
    void displayLeafNodes()
    {
        if (root == NULL)
        {
            cout << "\nTree is Empty!\n";
            return;
        }

        cout << "\nLeaf Nodes: ";
        printLeafNodes(root);
        cout << endl;
    }
};

int main()
{
    BST original;
    BST* copied = NULL;

    int choice;
    int n;
    int value;

    do
    {
        cout << "\n========================================\n";
        cout << " Employee Database Analysis using BST\n";
        cout << "========================================\n";
        cout << "1. Insert Employee IDs\n";
        cout << "2. Display Original BST (Level Order)\n";
        cout << "3. Copy BST\n";
        cout << "4. Display Copied BST (Level Order)\n";
        cout << "5. Find Height of BST\n";
        cout << "6. Display Leaf Nodes\n";
        cout << "7. Exit\n";
        cout << "========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter number of Employee IDs: ";
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                cout << "Enter Employee ID: ";
                cin >> value;

                original.insertID(value);
            }

            break;

        case 2:
            original.displayOriginal();
            break;

        case 3:
            if (copied != NULL)
            {
                delete copied;
            }

            copied = original.copyBST();

            cout << "\nBST Copied Successfully!\n";
            break;

        case 4:
            if (copied == NULL)
            {
                cout << "\nFirst copy the BST using option 3.\n";
            }
            else
            {
                copied->displayCopied();
            }

            break;

        case 5:
            original.displayHeight();
            break;

        case 6:
            original.displayLeafNodes();
            break;

        case 7:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
