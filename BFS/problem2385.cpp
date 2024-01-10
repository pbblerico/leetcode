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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int> > g;
        map<int, int> steps;
        
        createGraph(root, g, steps);
        
        queue<int> q;
        q.push(start);
        steps[start] = 0;
        
        int ans = 0;
        while(!q.empty()) {
            int val = q.front();
            q.pop();
            
            for(int i = 0; i < g[val].size(); i++) {
                if(steps[g[val][i]] != -1) {
                    continue;
                }
                steps[g[val][i]] = steps[val] + 1;
                q.push(g[val][i]);
            }
        }
        for(auto step: steps) {
            ans = max(ans, step.second);
        }
        
        return ans;
    }
    
    void createGraph(TreeNode* root, unordered_map<int, vector<int> > &g, map<int, int>& steps) {
        if(root == nullptr) return;
        
        steps[root->val] = -1;
        if(root->left != nullptr) {
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
            
        }
        if(root->right != nullptr) {
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
           
        }
        
        createGraph(root->left, g, steps);
        createGraph(root->right, g, steps);
        
        
    }
    
   
};