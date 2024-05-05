#include<bits/stdc++.h>
using namespace std ;

class disjointSet{

    vector<int> size,ul_parent ;
    public :
    disjointSet(int n){
        size.resize(n+1,1) ;
        ul_parent.resize(n+1) ;
        for(int i=0;i<=n;i++){
            ul_parent[i] = i ;
        }

    }

    int findUl_parent(int node){
        if(node==ul_parent[node]) return node ;
        findUl_parent(ul_parent[node]) ;
    }

    int unionBySize(int u,int v){
        int ulp_u = findUl_parent(u) ;
        int ulp_v = findUl_parent(v) ;

        if(ulp_u==ulp_v) return -1;

        if(size[ulp_u]>size[ulp_v]){
            ul_parent[ulp_v] = ulp_u ;
            size[ulp_u] +=size[ulp_v] ; 
        }

        else{
            ul_parent[ulp_u] = ulp_v ;
            size[ulp_v] +=size[ulp_u] ; 
        }
        return 1 ;
    }

} ;

void kruskal(vector<vector<int>>edges,int n){
    
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq ; 

        //arange all edges in descending order
        for(auto i:edges){
            pq.push({i[2],{i[0],i[1]}}) ;
        }

        disjointSet obj(n) ;
        int cost = 0 ;
        vector< pair<int,pair<int,int>>>graph ;
        while(!pq.empty()){
            pair<int,pair<int,int>> p = pq.top() ;
            pq.pop() ;
            int result = obj.unionBySize(p.second.first,p.second.second) ;
            if(result==1){
                 cost+=p.first ;
                 graph.push_back(p) ;
            }
        }

        for(auto i:graph){
            cout<<i.second.first<<" -->"<<i.second.second<<" = "<<i.first<<endl ;
        }
        cout<<"cost = "<<cost<<endl ;


}

int main(){

    vector<vector<int>> edges  ={ {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}} ;

    kruskal(edges,5) ;



}