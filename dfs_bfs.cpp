#include<bits/stdc++.h>
using namespace std ;

class dfs_bfs{

    public:
        void dfs(int root,vector<vector<int>>&adj,vector<int>&visited){

            visited[root] = 1 ;

            cout<<root<<" ,";

            for(auto node: adj[root]){
                if(visited[node]!=1) dfs(node,adj,visited) ;
            }

        }

        void bfs(int root ,vector<vector<int>>&adj){
            queue<int>q ;
            vector<int>visited(adj.size(),0) ;

            q.push(root) ;
            visited[root] = 1 ;

            while(!q.empty()){
                int node = q.front() ;
                q.pop() ;
                cout<<node<<" " ;
                for(auto adj_node:adj[node]){
                    if(visited[adj_node]!=1){
                        visited[adj_node] = 1 ;
                        q.push(adj_node) ;
                    }
                }
            }
        }

};
int main(){

    vector<int> visited(6,0);

    vector<vector<int>> adj = {{1,2},{0},{0,3,4,5},{2},{2,5},{2,4}} ;
    dfs_bfs obj ;
    obj.dfs(4,adj,visited) ;
    cout<<endl; 
    obj.bfs(5,adj);



    return 0 ;
}