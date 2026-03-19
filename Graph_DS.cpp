#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
//Graph representation using adj list 
class Graph{
    int V;
    bool isUndir;
    list<int>*l;
public:
    Graph(int V,bool isUndir=true){
        this->V=V;
        l=new list<int>[V];
        this->isUndir=isUndir;
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
    }
    void print(){
        for(int u=0; u<V; u++){
            list<int>neighbors = l[u];
            cout<<u<<" : ";
            for(int v: neighbors){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    //BFS TRAVERSAL - USING QUEUE DATA STRUCTURE 
    
    void bfs(){
        queue<int>q;
        vector<bool>vis(V,false);
        q.push(0); //Add root node
        vis[0]=true; //mark it as visited
        while(!q.empty()){ //run loop for adjacent nodes 
            int u = q.front(); //save the front node of Queue 
            q.pop(); // pop it
            cout<<u<<" -> "; //print that saved node 
            list<int>neighbour = l[u]; // neighbour node list 
            for(int v : neighbour){ //traverse the neighbour list 
                if(!vis[v]){ // if node not visited  and in Queue
                    vis[v] = true; // mark it visited
                    q.push(v); // add it in queue
                }
            }
        }
        cout<<"End"<<endl;
    }
    void dfs_recursive(int u,vector<bool>&vis){
        vis[u] = true;
        cout<<u<<" -> ";
        list<int>neighbour = l[u];
        for(int v : neighbour){
            if(!vis[v])
                dfs_recursive(v,vis);
        }
        
    }
    bool UndirectedCycle(int s,int p,vector<bool>&vis){
        vis[s] = true;
        list<int>neighbor = l[s];
        for(int v:neighbor){
            if(!vis[v]){
                if(UndirectedCycle(v,s,vis))
                    return true;
            }else{
                if(v!=p){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCyUndir(){
        vector<bool>vis(V,false);
        return UndirectedCycle(0,-1,vis);
    }
    bool dirCycleHelp(int s, vector<bool>&vis,vector<bool>&recPath){
        vis[s] = true;
        recPath[s] = true;
        list<int>neigh = l[s];
        for(int v: neigh){
            if(!vis[v]){
                if(dirCycleHelp(v,vis,recPath)){
                    return true;
                }
            }else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[s] = false;
        return false;
    }
    bool idCycleDir(){
        vector<bool>vis(V,false);
        vector<bool>recPath(V,false);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dirCycleHelp(i,vis, recPath)){
                    return true;
                }
            }
        }
        return false;
    }

};
int main(){
    Graph graph(4,false);
    graph.addEdge(1,0);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    // graph.addEdge(3,0);
    graph.print();

    cout<<"\n----------BFS Traversal--------------\n";
    graph.bfs();
    cout<<"\n----------DFS Traversal--------------\n";
    vector<bool>vis(7,false);
    graph.dfs_recursive(0,vis);
    cout<<"\nGraph is Directed :: "<<graph.idCycleDir();

    return 0;
    
}