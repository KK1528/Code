/*
Question 1: Maximum Sum of Contiguous Subarray
Problem Description:
Given an integer array, find the maximum sum of any contiguous subarray.

Example:

Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6 (The maximum sum is from the subarray [4, -1, 2, 1]).
Question:
How would you approach finding the maximum sum of a contiguous subarray? Explain your thought process and provide a solution in any language of your choice.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int maximumsum(vector<int>& nums){
        int ans = INT_MIN;
        int sum =0;
        for(auto it : nums){
            sum += it;
            ans = max(ans,sum);
            if(sum<0) sum =0;
        }
        return ans;
    }
};

 

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution ob1;
    int ans = ob1.maximumsum(nums);
    cout<< ans;
    return 0;
}