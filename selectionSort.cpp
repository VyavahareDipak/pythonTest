#include<bits/stdc++.h>
using namespace std ;

/* T.C = O(n)
First, we will select the range of the unsorted array using a loop (say i) that indicates the starting index of the range.
The loop will run forward from 0 to n-1. The value i = 0 means the range is from 0 to n-1, and similarly, i = 1 means the range is from 1 to n-1, and so on.
(Initially, the range will be the whole array starting from the first index.)
Now, in each iteration, we will select the minimum element from the range of the unsorted array using an inner loop.
After that, we will swap the minimum element with the first element of the selected range(in step 1). 
Finally, after each iteration, we will find that the array is sorted up to the first index of the range. */

int main(){
    vector<int> nums = {100,2,30,22,5,6,2,78} ;
    int size = nums.size() ;
    for(int i=0;i<size;i++){
        int maxi = nums[i] ;
        int indx = i ;
        for(int j=i+1 ;j<size;j++){
            if(nums[j]<maxi){
                maxi = nums[j] ;
                indx = j ;
             }
        }
        swap(nums[i],nums[indx]) ;
    }

    for(auto i:nums){
        cout<<" "<<i;
    }
    return 0 ;
}