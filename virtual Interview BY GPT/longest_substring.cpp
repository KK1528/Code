/*
Question 3: Longest Substring Without Repeating Characters
Problem Description:
Given a string s, find the length of the longest substring without repeating characters.

Example:

Input: s = "abcabcbb"
Output: 3 (The answer is "abc", with the length of 3).
Question:
How would you approach finding the longest substring without repeating characters? Could you explain your thought process and provide a solution in any language of your choice?
*/

#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string &s){
    int n = s.size();
    int i=0,j=0;
    unordered_map<int,int>freq;
    int ans = INT_MIN;
    while(i<=j and j<n){
        if(freq.find(s[j])!=freq.end() and freq[s[j]] >= i){
            i = freq[s[j]]+1;
        }
        freq[s[j]] = j;
        ans = max(ans , j-i+1);
        j++;
    }
    return ans;
}

int main(){
    string s = "abcabcbb";
    int output = longestSubstring(s);
    cout<< output << endl;

    return 0;
}