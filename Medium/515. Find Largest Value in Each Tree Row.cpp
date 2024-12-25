// Problem Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/?envType=daily-question&envId=2024-12-25

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countLevel(auto q){
        int cnt=0;
        while(q.size()){
            auto c=q.front();q.pop();
            cnt=c.second;
            if(c.first->left)q.push({c.first->left,c.second+1});
            if(c.first->right)q.push({c.first->right,c.second+1});
        }
        return cnt+1;
    }
    void bfs(auto q,auto &ans){
        while(q.size()){
            auto c=q.front();q.pop();
            ans[c.second]=max(ans[c.second],c.first->val);
            if(c.first->left)q.push({c.first->left,c.second+1});
            if(c.first->right)q.push({c.first->right,c.second+1});
        }
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        vector<int>ans(countLevel(q),INT_MIN);
        q.push({root,0});
        bfs(q,ans);
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);