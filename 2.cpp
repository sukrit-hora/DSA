
#include <iostream>
using namespace std;

class Queue
{
private:
    int queue[5];
    int front;
    int rear;
    int size;

public:
    Queue()
    {
        size = 5;
        front = -1;
        rear = -1;
    }

    // Insert (Enqueue)
    void insert(int value)
    {
        if (rear == size - 1)
        {
            cout << "Queue Is Full" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        cout << "Element Inserted" << endl;
    }

    // Display Queue
    void display()
    {
        if (front == -1)
        {
            cout << "Queue Is Empty" << endl;
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    // Peek
    void peek()
    {
        if (front == -1)
        {
            cout << "Queue Is Empty" << endl;
            return;
        }

        cout << "\nFirst Value: " << queue[front] << endl;
    }

    // Delete (Dequeue)
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue Is Empty" << endl;
            return;
        }

        cout << "Deleted Element: " << queue[front] << endl;

        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }
};

int main()
{
    Queue a;
    int choice, value;

    do
    {
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a value: ";
            cin >> value;
            a.insert(value);
            break;

        case 2:
            a.dequeue();
            break;

        case 3:
            a.peek();
            break;

        case 4:
            a.display();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
        }

    } while (choice != 5);

    return 0;
}
