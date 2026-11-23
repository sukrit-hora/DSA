
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int n;
    vector<int> adj[20];
    bool visited[20];

public:

    // Create Graph using Adjacency List
    void createGraph()
    {
        cout << "Enter number of users: ";
        cin >> n;

        if (n <= 0 || n > 20)
        {
            cout << "Invalid number of users!\n";
            n = 0;
            return;
        }

        int edges;

        cout << "Enter number of friendships: ";
        cin >> edges;

        cout << "Enter friendships (source destination):\n";

        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            if (u < 0 || u >= n || v < 0 || v >= n)
            {
                cout << "Invalid vertex!\n";
                continue;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    // Display Adjacency List
    void displayList()
    {
        cout << "\nAdjacency List:\n";

        for (int i = 0; i < n; i++)
        {
            cout << i << " -> ";

            for (int j : adj[i])
            {
                cout << j << " ";
            }

            cout << endl;
        }
    }

    // Breadth First Search
    void BFS(int start)
    {
        if (start < 0 || start >= n)
        {
            cout << "Invalid starting user!\n";
            return;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        visited[start] = true;
        q.push(start);

        cout << "\nBFS Traversal: ";

        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();

            cout << vertex << " ";

            for (int neighbour : adj[vertex])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph g;
    int start;

    g.createGraph();
    g.displayList();

    cout << "\nEnter starting user: ";
    cin >> start;

    g.BFS(start);

    return 0;
}
