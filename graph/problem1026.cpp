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
    int maxAncestorDiff(TreeNode* root) {
        unordered_map<int, vector<int> > g;
        
        createGraph(root, g);
        
        int ans = 0;
        for(auto node: g) {
            int n = node.first;
            // cout << n << endl;
            for(int i = 0; i < node.second.size(); i++) {
                if(ans < abs(n - node.second[i])) ans = abs(n - node.second[i]);
            }
            // cout << endl;
        }
        
        return ans;
    }
    
    vector<int> createGraph(TreeNode* root, unordered_map<int, vector<int> > &g) {
        if(root == nullptr) return {};

        
        if(root->left != nullptr) {
            g[root->val].push_back(root->left->val);
        }
        if(root->right != nullptr) {
            g[root->val].push_back(root->right->val);
        }
        
        for(auto val: createGraph(root->left, g)) {
            g[root->val].push_back(val);
        }
        for(auto val: createGraph(root->right, g)) {
            g[root->val].push_back(val);
        }
        
        return g[root->val];
    }
};