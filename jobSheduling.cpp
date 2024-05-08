#include<bits/stdc++.h>
using namespace std ;

void jobSheduler(map<int,int>profit,map<int,int>deadline,int n){

    //make priority queue 
    //compare func
    auto compare  = [](pair<int,int>a,pair<int,int>b){
        return (a.second < b.second) ;
    };

    priority_queue<pair<int,int> ,vector<pair<int,int>>,decltype(compare)>pq(compare) ;

    for(auto i:profit){
        pq.push(i) ;
    }
    vector<int>shedule(n,-1) ;
    vector<int>job(n,-1) ;
    cout<<"---------------------------------------"<<endl ;
    while(!pq.empty()){
        pair<int,int>p = pq.top() ;
        cout<<p.first<<p.second<<endl ;
        pq.pop() ;

        int crnt_deadline = deadline[p.first] ;

        for(int i= min(n,crnt_deadline)-1;i>=0;i--){
            if(shedule[i]==-1){
                shedule[i]=p.second ; //store profit ;
                job[i] = p.first ;    // store job ;
                break ;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<"j"<<job[i]<<": "<<shedule[i]<<" -> " ;
    }
}

int main(){
    map<int,int>profit ;
    map<int,int>deadline ;
    // profit[1]=1 ;
    // profit[2]=5 ;
    // profit[3]=20 ;
    // profit[4]=10 ;
    // profit[5]=15 ;
    // deadline[1] = 3 ;
    // deadline[2] = 3 ;
    // deadline[3] = 2 ;
    // deadline[4] = 1 ;
    // deadline[5] = 2 ;
    profit[1]=35 ;
    profit[2]=30 ;
    profit[3]=25 ;
    profit[4]=20 ;
    profit[5]=15 ;
    profit[6]=12 ;
    profit[7]=5 ;
    

    deadline[1] = 3 ;
    deadline[2] = 4 ;
    deadline[3] = 4 ;
    deadline[4] = 2 ;
    deadline[5] = 3 ;
    deadline[6] = 2 ;
    deadline[7] = 1 ;
    jobSheduler(profit,deadline,4) ;
    return 0 ;
}