#include<bits/stdc++.h>
using namespace std ;

void prims(vector<vector<pair<int,int>>>adj,int root){

    //visited
    vector<int> visited(adj.size(),0) ;

    //to store mst
    vector<pair<int,int>> mst ;

    //to store tree sum
    int sum = 0 ;

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq ;

    pq.push({0,{root,-1}}) ;
    // visited[root] = 1 ;
    while(!pq.empty()){

        auto p = pq.top() ;
        pq.pop() ;

        int wt = p.first ;
        int node = p.second.first ;
        int prnt = p.second.second ;

        if(visited[node]!=1){
            visited[node] = 1 ;
            mst.push_back({prnt,node}) ;
            sum+=wt ;
            for(auto i : adj[node]){
                if(visited[i.first]!=1){
                    pq.push({i.second,{i.first,node}}) ;
                    // visited[i.first]=1 ;
                }
            }
        } 
    }
    for(auto i:mst){
        cout<<i.first<<"--> "<<i.second<<endl ;
    }
}

int main(){

    vector<vector<pair<int,int>>>adj = {
    {{1,5},{2,3},{5,1}},
    {{0,5}},
    {{0,3},{3,2},{4,4},{5,3}},
    {{2,2}},
    {{2,4},{5,5}},
    {{0,1},{2,3},{4,5}}
    } ;
    prims(adj,0) ;
    return 0 ;
}