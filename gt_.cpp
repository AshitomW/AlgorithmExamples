#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Adding a friendship between two nodes
    void addEdge(int v, int w) {
        adj[v].push_back(w); // For a directed graph
    }

    // --- BFS: The "Gossip" Method (Spreads level by level) ---
    void BFS(int startNode) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        cout << "BFS (Starting at " << startNode << "): ";

        while (!q.empty()) {
            int s = q.front();
            cout << s << " ";
            q.pop();

            // Check all neighbors. If they haven't heard the news, tell them.
            for (int neighbor : adj[s]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // --- DFS: The "Introvert" Method (Dives deep into one path) ---
    void DFSRecursive(int v, vector<bool>& visited) {
        // Mark the current node as "Leave me alone, I'm busy"
        visited[v] = true;
        cout << v << " ";

        // Go as deep as possible with each neighbor
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSRecursive(neighbor, visited);
            }
        }
    }

    // Helper for DFS to handle the visited array setup
    void DFS(int startNode) {
        vector<bool> visited(V, false);
        cout << "DFS (Starting at " << startNode << "): ";
        DFSRecursive(startNode, visited);
        cout << endl;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);
    g.DFS(2);

    return 0;
}
