
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Create Linked List
    void createList()
    {
        int n, value;

        cout << "\nEnter number of nodes: ";
        cin >> n;

        if (n <= 0)
        {
            cout << "List is empty.\n";
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << "Enter value " << i << ": ";
            cin >> value;
            insertEnd(value);
        }

        cout << "\nLinked List Created.\n";
    }

    // Insert at End
    void insertEnd(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Display Linked List
    void display()
    {
        if (head == NULL)
        {
            cout << "\nLinked List is empty.\n";
            return;
        }

        Node *temp = head;

        cout << "\nLinked List: ";

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Delete Node
    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "\nLinked List is empty.\n";
            return;
        }

        Node *temp = head;
        Node *previous = NULL;

        // Delete First Node
        if (head->data == value)
        {
            head = head->next;
            delete temp;
            cout << "\nNode Deleted.\n";
            return;
        }

        while (temp != NULL && temp->data != value)
        {
            previous = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "\nValue not found.\n";
            return;
        }

        previous->next = temp->next;
        delete temp;

        cout << "\nNode Deleted.\n";
    }
};

int main()
{
    LinkedList obj;
    int value;

    obj.createList();
    obj.display();

    cout << "\nEnter value to delete: ";
    cin >> value;

    obj.deleteNode(value);

    obj.display();

    return 0;
}
