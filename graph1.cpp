#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;
    Graph(int v) {
        V = v;
        adj.resize(v);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int x : adj[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

void BFS(int st, vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[st] = true;
    q.push(st);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int x : adj[node]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

    bool dfs(int node, vector<vector<int>> &adj, 
             vector<bool> &vis, vector<bool> &pathVis) {
        
        vis[node] = true;
        pathVis[node] = true;

        for (int neigh : adj[node]) {
            // go to unvisited node
            if (!vis[neigh]) {
                if (dfs(neigh, adj, vis, pathVis))
                    return true;
            }
            // if already in current path → cycle
            else if (pathVis[neigh]) {
                return true;
            }
        }

        pathVis[node] = false; // backtrack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &adj) {
        vector<bool> vis(V, false), pathVis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis))
                    return true;
            }
        }
        return false;
    }

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    // g.addEdge(1,2); // Uncomment to create a cycle
    g.addEdge(1,4);

    g.printGraph();
    
    cout << "\nDFS: ";
    vector<bool> visited(5,false);
    DFS(0, g.adj, visited);

    cout << "\nBFS: ";
    BFS(0, g.adj, 5);

    cout << "\nCycle present? " << (isCyclic(5,g.adj) ? "Yes" : "No") << endl;

    return 0;
}
