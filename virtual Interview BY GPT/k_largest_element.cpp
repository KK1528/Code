/*
Problem Description:
Given an integer array nums and an integer k, return the kth largest element in the array.

Example:

Input: nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5 (The 2nd largest element is 5).
Question:
How would you approach finding the k-th largest element in the array? Could you explain your thought process and provide a solution in any language of your choice?
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int klargestelement(vector<int>& nums , int k){
        priority_queue<int,vector<int> ,greater<int> > pq; 
        for(int i=0 ; i<nums.size() ; i++){
            if(pq.size() < k) pq.push(nums[i]);
            else if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

// 6 5   

int main(){
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    Solution ob1;
    int ans = ob1.klargestelement(nums,k);
    cout<< ans;
    return 0;
}