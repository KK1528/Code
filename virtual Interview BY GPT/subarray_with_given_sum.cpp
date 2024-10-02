// /*
// Problem Description:
// Given an unsorted array of non-negative integers, find a continuous subarray that adds up to a given sum S. Return the start and end indices of the subarray.

// Example:

// Input: arr = [1, 4, 20, 3, 10, 5], S = 33
// Output: [2, 4] (Subarray [20, 3, 10] adds up to 33)
// Question:
// How would you approach finding a continuous subarray that sums to a given value? Could you explain your thought process and provide a solution in any language of your choice?
// */

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> solve(vector<int> &vec , int S){
//     int n = vec.size();
//     for(int i=0 ; i<n ; i++){
//         int sum = 0;
//         for(int j=i ; j<n ; j++){
//             sum += vec[j];
//             // cout << sum << " ";
//             if(sum == S){
//                 return {i,j};
//             }
//         }
//     }
//     return {-1,-1};
// }

// int main(){
//     vector<int> vec = {1, 4, 20, 3, 10, 5};
//     int S = 33;
//     vector<int> output = solve(vec , S);
//     for( auto it : output){
//         cout<< it << " ";
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& vec, int S) {
    int start = 0, current_sum = 0;
    int n = vec.size();

    for (int end = 0; end < n; end++) {
        current_sum += vec[end];

        // If current_sum exceeds the target sum, move the start pointer to the right
        while (current_sum > S && start <= end) {
            current_sum -= vec[start];
            start++;
        }

        // If current_sum is equal to S, return the start and end indices
        if (current_sum == S) {
            return {start, end};
        }
    }

    // If no subarray is found, return -1, -1
    return {-1, -1};
}

int main() {
    vector<int> vec = {1, 4, 20, 3, 10, 5};
    int S = 33;
    vector<int> output = solve(vec, S);
    for (auto it : output) {
        cout << it << " ";
    }
    return 0;
}
