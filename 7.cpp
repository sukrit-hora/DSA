
#include <iostream>
using namespace std;

class Graph
{
    int n;
    int adj[20][20];
    bool visited[20];

public:

    // Create Graph using Adjacency Matrix
    void createGraph()
    {
        cout << "Enter number of intersections: ";
        cin >> n;

        if (n <= 0 || n > 20)
        {
            cout << "Invalid number of intersections!\n";
            n = 0;
            return;
        }

        // Initialize Adjacency Matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }

            visited[i] = false;
        }

        int edges;

        cout << "Enter number of roads: ";
        cin >> edges;

        cout << "Enter the roads (source destination):\n";

        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            if (u < 0 || u >= n || v < 0 || v >= n)
            {
                cout << "Invalid vertex!\n";
                continue;
            }

            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }

    // Display Adjacency Matrix
    void displayMatrix()
    {
        cout << "\nAdjacency Matrix:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
            }

            cout << endl;
        }
    }

    // Depth First Search
    void DFS(int vertex)
    {
        visited[vertex] = true;

        cout << vertex << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj[vertex][i] == 1 && !visited[i])
            {
                DFS(i);
            }
        }
    }

    // Start DFS Traversal
    void performDFS()
    {
        if (n == 0)
        {
            return;
        }

        int start;

        cout << "\nEnter starting intersection: ";
        cin >> start;

        if (start < 0 || start >= n)
        {
            cout << "Invalid starting intersection!\n";
            return;
        }

        // Reset Visited Array
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        cout << "\nDFS Traversal: ";
        DFS(start);

        cout << endl;
    }
};

int main()
{
    Graph g;

    g.createGraph();

    g.displayMatrix();

    g.performDFS();

    return 0;
}
