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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        
        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);
        
        return leaves1 == leaves2;
    }
    
    
    void getLeaves(TreeNode* root, vector<int> & v) {
        if(root == nullptr) return;
        if(root->left == nullptr and root->right == nullptr) {
            v.push_back(root->val);
            return;
        }
        
        getLeaves(root->left, v);
        getLeaves(root->right, v);
    }
};