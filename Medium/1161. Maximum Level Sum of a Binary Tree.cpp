// Problem Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=daily-question&envId=2026-01-06

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
    int maxLevelSum(TreeNode* root) {
        unordered_map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});

        while(q.size()){
            auto [node,level]=q.front();
            q.pop();
            
            mp[level]+=node->val;
            
            if(node->left)q.push({node->left,level+1});
            if(node->right)q.push({node->right,level+1});
        }

        int ans=0,mx=INT_MIN;
        for(auto &c:mp){
            if(c.second==mx)ans=min(ans,c.first);
            if(c.second>mx)ans=c.first,mx=c.second;
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(2*N) => O(N);
