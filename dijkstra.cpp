#include<bits/stdc++.h>
using namespace std ;

void dijkstra(vector<vector<pair<int,int>>>adj,int root){

    //make dist vector
    vector<int> dist(adj.size(),INT_MAX) ;
    //make set
    set<pair<int,int>>st ;

    st.insert({0,root}) ;
    dist[root] = 0 ;

    while(!st.empty()){

        pair<int,int> p = *st.begin() ;
         int node = p.second ;
         int distance = p.first ;
         st.erase(p) ;
         cout<<node<<" "<<distance<<endl ;
         //traverse its all adj nodes
         for(auto adj_node:adj[node]){
            if(distance + adj_node.second <dist[adj_node.first] ){
                if(dist[adj_node.first]!=INT_MAX){
                    st.erase({dist[adj_node.first],adj_node.first}) ;
                } 
                st.insert({(distance + adj_node.second),adj_node.first}) ;
                dist[adj_node.first] = distance + adj_node.second ;
            }
         }
    }

    for(int i=0;i<dist.size();i++){
        cout<<i<<"-->"<<dist[i]<<endl ;
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

    dijkstra(adj,0) ;


    return 0 ;
}