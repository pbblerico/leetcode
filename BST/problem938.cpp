#include <bits\stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int answer = 0;
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        in(root, low, high);
        
        return answer;
    }
    
    void in(TreeNode* root, int low, int high) {
        if(root == nullptr) return;
        
        
        if(root->val >= low) in(root->left, low, high);
        if(root->val >= low && root->val <= high) answer += root->val;
        if(root->val <= high) in(root->right, low, high);
    }
};