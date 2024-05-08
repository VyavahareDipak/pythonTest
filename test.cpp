#include<bits/stdc++.h>
using namespace std ;

void nqueen( vector<vector<string>> &board,vector<string> &ans,int clm,int n ,vector<int> &row,vector<int> &right_slash,vector<int> &left_slash){

    if(clm==n){
        board.push_back(ans) ;
        return ;
    }

    for(int i=0;i<n;i++){

        if(row[i]==1)continue ;
        if(right_slash[i+clm]==1) continue ;
        if(left_slash[n-1+i-clm]==1) continue ;

        ans[i][clm] = 'Q' ;
        row[i] = 1 ;
        right_slash[i+clm] = 1 ;
        left_slash[n-1+i-clm] = 1 ;
        nqueen(board,ans,clm+1,n,row,right_slash,left_slash) ;
        ans[i][clm] = '_' ;
        row[i] = 0 ;
        right_slash[i+clm] = 0 ;
        left_slash[n-1+i-clm] = 0 ;
    }
}


int main(){
    int n = 6 ;
    vector<vector<string>> board ;
    vector<string> ans ;
    string str(n,'_') ;
    for(int i=0;i<n;i++){
        ans.push_back(str) ;
    }

    vector<int> row(n,0) ;
    vector<int> right_slash(2*(n-1),0) ;
    vector<int> left_slash(2*(n-1),0) ;
    nqueen(board,ans,0,n,row,right_slash,left_slash) ;

    for(auto i:board){
        for(auto strr: i){
            cout<<strr<<endl;
        }cout<<endl ;
    }
    return  0 ;
}
