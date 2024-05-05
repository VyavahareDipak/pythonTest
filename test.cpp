#include<bits/stdc++.h>
using namespace std ;

typedef vector<vector<int>> puzzleState ;
class Node{
    public:
        puzzleState state ;
        int cost ;
        int hurestic ;
        Node* parent ;

        Node(puzzleState state , int cost,Node*parent){
            this->cost=cost ;
            this->state = state ;
            this->parent = parent ;
            this->hurestic= calHurestic(state) ;

        }

        int calHurestic(puzzleState state){
                // cout<<"in hurestic"<<endl ;

                int hurestic =0 ;

                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(state[i][j]!=0){
                        int goal_row = (state[i][j]-1)/3 ;
                        int goal_clm = (state[i][j]-1)%3 ;

                        hurestic += abs(goal_row - i ) + abs(goal_clm-j) ;
                        }

                    }
                }
                // cout<<"hurestic exit"<<endl ;

                return hurestic ;
        }
};

bool isSolvable(puzzleState state){
    // cout<<"in is solvable"<<endl ;
    vector<int>flattened ;
    for(auto row:state){
        for(auto i:row){
            if(i!=0){
                flattened.push_back(i) ;
            }
        }
    }
    int inversions = 0 ;
    for(int i=0;i<flattened.size();i++){
        for(int j=i+1;j<flattened.size();j++){
            if(flattened[i]>flattened[j]){
                inversions++ ;
            }
        }
    }
    // cout<<"inversions = "<<inversions<<endl ;
    // cout<<"solvable exit"<<endl ;
    return inversions%2==0 ;

}

vector<puzzleState> generateSuccesser(puzzleState state){
    //find empty plate
        cout<<"in generate "<<endl ;

    int zero_row ;
    int zero_clm ;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(state[i][j]==0){
               zero_row=i;
               zero_clm=j;
               break ;
            }
        }
    }

    //generate successer
    vector<puzzleState> successers ;
    vector<pair<int,int>> direction = {{-1,0},{0,1},{1,0},{0,-1}} ;
    for(auto dir:direction){
        puzzleState successer = state ;
        int new_row = zero_row + dir.first ; 
        int new_clm = zero_clm + dir.second ; 
        if(new_row>=0 && new_row<3 && new_clm>=0 && new_clm<3){
            swap(successer[zero_row][zero_clm],successer[new_row][new_clm]) ;
            successers.push_back(successer) ;
        }
    }
        cout<<"generate exit"<<endl ;

    return successers ;
}

auto compare = [](Node* a,Node* b){
    return  (a->cost + a->hurestic) > (b->cost + b->hurestic) ;
};

void printState(puzzleState state){

    for(auto row:state){
        for(auto cell : row){
            cout<<cell<<" ";
        }cout<<endl ;
    }

}

vector<puzzleState> aStarSearch(puzzleState state){
    if(!isSolvable(state)){
        cout<<"puzzle not solvable" ;
        return {} ;
    }

    priority_queue<Node*,vector<Node*>,decltype(compare)> pq(compare) ;
    map<puzzleState,int>costs ;
    vector<puzzleState> solution;
    Node * initialState = new Node(state,0,NULL) ;
    pq.push(initialState) ;

    while(!pq.empty()){
        Node* cur_state = pq.top() ;
        pq.pop() ;

        //if hurestic is zero we found solution
        if(cur_state->hurestic==0){
          while(cur_state!=NULL){
            solution.push_back(cur_state->state) ;
            cur_state=cur_state->parent ;
          }
          reverse(solution.begin(),solution.end()) ;
          return solution ;  
        }

        //generate succesers 
        vector<puzzleState>successers = generateSuccesser(cur_state->state) ;

        for(auto successer : successers){
            int new_cost = cur_state->cost + 1 ;
            if(costs.find(successer)==costs.end() || costs[successer]>new_cost){
                costs[successer]=new_cost ;
                Node* newState =new Node(successer,new_cost,cur_state) ;
                pq.push(newState) ;
            }
        }
    }
    return {} ;
}
int main(){
    puzzleState state={{1,0,3},{4,2,5},{6,7,8}} ;
    cout<<"Initial State :"<<endl ;
    printState(state) ;
    vector<puzzleState> solution = aStarSearch(state);
    if(!solution.empty()){
        cout<<"sol"<<solution.size()<<endl;
        for(auto i:solution){
            printState(i) ;
        }
    }
//unsolvable state
// 1 2 3
// 4 5 6
// 8 7 0
    // cout<<isSolvable(state) ;
}