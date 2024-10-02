/*
Problem Description:
You are given an array containing n-1 integers. The array contains distinct numbers in the range from 1 to n. This means that one number between 1 and n is missing from the array.

Example:

Input: [1, 2, 4, 6, 3, 7, 8]
Output: 5
Follow-up:
What if two numbers are missing? How would you modify your solution?

Question:
How would you approach finding the missing number in this array? Could you explain your thought process and provide a solution in any language of your choice?

*/

/*

    29 - 7
    28

    29 - 28 

    number must be <= 7
    31 - 8 = 23
    3  7
    28-23

*/

#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&nums){
    int n = nums.size();
    int sum = accumulate(nums.begin() , nums.end() , 0);
    int diff = (n*(n+1))/2 - sum + n+1;
    return diff;
}
int main(){
    vector<int> nums = {1, 2, 4, 6, 3, 7, 8};
    int output = solve(nums);
    cout<< output <<endl;
    return 0;
}