#include<bits/stdc++.h>
using namespace std ;

void nqueen(vector<string>&ans,vector<vector<string>>&board ,int clm ,int n,vector<int>&row,vector<int>&up_diagonal,vector<int>&down_diagonal){
    //edge case
    if(clm ==n){
        board.push_back(ans) ;
        cout<<"clm : "<<clm<<endl;

        return ;
    }

    // cout<<"clm : "<<clm<<endl;

    for(int i=0;i<n;i++){
        //check  for row
        //  cout<<"clm : "<<clm<<endl
        if(row[i]==1) continue; 
        if(up_diagonal[i+clm]==1) continue; 
        if(down_diagonal[n-1+i-clm]==1) continue;

        ans[i][clm] = 'Q' ;
        row[i] = 1 ;
        up_diagonal[i+clm] = 1 ;
        down_diagonal[n-1+i-clm] = 1 ;
        nqueen(ans,board,clm+1,n,row,up_diagonal,down_diagonal) ;
        ans[i][clm] = 'N' ;
        row[i] = 0 ;
        up_diagonal[i+clm] = 0 ;
        down_diagonal[n-1+i-clm] = 0 ;
    }

}


  int main(){

    int n = 4 ;
    string str(n,'N') ;
    vector<vector<string>> board(n) ;
    vector<string>ans(n) ;
    for(int i=0;i<n;i++){
        ans[i] = str ;
    }

    vector<int>up_Diagonal(2*(n-1),0) ;
    vector<int>down_Diagonal(2*(n-1),0) ;
    vector<int>row(n,0) ;

    // cout<<"t"<<endl;
     nqueen(ans,board,0,n,row,up_Diagonal,down_Diagonal) ;
 
    // board = solveNQueens(4) ;
    for(auto v:board){
        for(auto strr:v){
            cout<<strr<<endl ;
        }cout<<"\n" ;
    }

    return 0 ;
}