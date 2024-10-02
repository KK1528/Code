/*
Question 4: Merge Intervals
Problem Description:
Given a collection of intervals, merge all overlapping intervals.

Example:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Intervals [1,3] and [2,6] overlap, so they are merged into [1,6].
Question:
How would you approach merging overlapping intervals? Could you explain your thought process and provide a solution in any language of your choice?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>>mergeintervals(vector<vector<int>>& intervals){
            sort(intervals.begin() , intervals.end());
            vector<vector<int>> ans ;
            int n = intervals.size();

            for( int i=0 ; i< n ; i++){
                int first = intervals[i][0];
                int second = intervals[i][1];

                while(i+1 < n and intervals[i+1][0] < second){
                    second = intervals[i+1][1];
                    i++;
                }
                ans.push_back({first,second});
            }

        return ans;
        }
};

int main(){
    vector<vector<int>> intervals = {{1,3},{2,5},{7,9},{8,10}};
    Solution ob1;
    vector<vector<int>> ans = ob1.mergeintervals(intervals);
    for(auto it : ans){
        cout << "[" << it[0] <<"," << it[1] << "]" << " ";
    }
    return 0;
}