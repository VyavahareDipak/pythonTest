#include<bits/stdc++.h>
using namespace std ;


bool issafe(int node,vector<vector<int>> graph,vector<int>&color,int v,int col){

    for(int i=0;i<v;i++){
        if(graph[node][i]==1 && col==color[i])return false ;
    }

    return true ;
}

bool solve(int node,vector<vector<int>> graph,int m,int v,vector<int>&color){
        if(node==v)return true ;

        for(int i=1;i<=m;i++){
            if(issafe(node,graph,color,v,i)){
                color[node] = i;
                if(solve(node+1,graph,m,v,color)) return true ;
                color[node] = 0 ; 
            }
        }
        return false ;
}

void graphColouring(vector<vector<int>> graph,int m,int v){
    vector<int>color(v,0) ;
    if(solve(0,graph,m,v,color)){
        for(int i=0;i<v;i++){
            cout<<i<<" -> "<<color[i] ;
        }
    }
    else{
        cout<<"not possible." ;
    }
}
int main(){
    int v= 4 ;
    int m = 3 ;
    vector<vector<int>> graph(v,vector<int>(v,0)) ;
    graph[0][1] = 1 ; graph[1][0] = 1 ;
    graph[0][2] = 1 ; graph[2][0] = 1 ;
    graph[0][3] = 1 ; graph[3][0] = 1 ;
    graph[1][3] = 1 ; graph[3][1] = 1 ;
    graph[2][3] = 1 ; graph[3][2] = 1 ;

    for(int i=1;i<=m;i++){
        graphColouring(graph,i,v) ;
    }
    

    return 0 ;
}