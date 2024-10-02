/*
You are given an array of integers nums and an integer k. Return the number of unique k-diff pairs in the array. A k-diff pair is an integer pair (nums[i], nums[j]), where the following conditions are met:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k

Input: nums = [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).


*/


#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int k) {
    if (k < 0) return 0; 

    unordered_map<int, int> mp;
    int ans = 0;

    for (int num : nums) {
        mp[num]++;
    }

    if (k == 0) {
        for (auto &entry : mp) {
            if (entry.second > 1) ans++;
        }
    } else {
        for (auto &entry : mp) {
            if (mp.find(entry.first + k) != mp.end()) {
                ans++;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;

    int output = solve(nums, k);
    cout << output << endl; 

    return 0;
}




/*

SQL QUERY

SELECT DEPARTMENTNAME , NAME AS EMPLOYEENAME
FROM EMPLOYEE
WHERE SALARY = (
    SELECT MAX(SALARY)
    FROM EMPLOYEE AS E2
    WHERE E2.DEPARTMENTNAME = EMPLOYEE.DEPARTMENTNAME
    AND E2.SALARY < (
        SELECT MAX(SALARY)
        FROM EMPLOYEE AS E3
        WHERE E3.DEPARTMENTNAME = EMPLOYEE.DEPARTMENTNAME
    )
)

*/