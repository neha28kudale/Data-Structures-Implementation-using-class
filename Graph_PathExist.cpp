#include<iostream>
#include<vector>

using namespace std;

bool dfs(int s,int d, vector<vector<int>>&adj,vector<bool>&visited){
	if(s==d) return true;
	visited[s]=true;
	for(int neigh : adj[s]){
		if(!visited[neigh]){
			if (dfs(neigh, d, adj, visited))
                return true;
		}
	}
	return false;
}

bool pathExist(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    dfs(0, -1, adj, visited);

    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}
int main(){
	int V = 5;
    vector<vector<int>> adj(V);

    adj[0].push_back(1);
    adj[1].push_back(2);
    //adj[2].push_back(3);
    //disconnects graph
    adj[3].push_back(4);
    
	if (pathExist(V, adj))
        cout << "Path exists";
    else
        cout << "No path exists";

return 0;
}