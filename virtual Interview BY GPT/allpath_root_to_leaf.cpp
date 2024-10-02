/*
Given a binary tree, return all root-to-leaf paths in the tree. Each path should be represented as a string in the format root->node1->node2->...->leaf.
Input:
   1
 /   \
2     3
 \
  4
Output: ["1->2->5", "1->3"]
Explanation: All root-to-leaf paths are: 1->2->5, 1->3.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x ) : val(x), left(NULL) , right(NULL) {}
};

void traverse(vector<string>& paths , string temp , TreeNode* root){
    temp += to_string(root->val);
    if(root->left ==nullptr and root->right == nullptr){
        paths.push_back(temp);
    }
else{
    temp+="->";
    if(root->left) traverse(paths , temp , root->left);
    if(root->right) traverse(paths , temp , root->right);
}
    
}

vector<string> solve(TreeNode* root){
    vector<string > paths;
    traverse(paths,"",root);
    return paths;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    vector<string> result = solve(root);
    for (const string& path : result) {
        cout << path << endl;
    }
    return 0;
}