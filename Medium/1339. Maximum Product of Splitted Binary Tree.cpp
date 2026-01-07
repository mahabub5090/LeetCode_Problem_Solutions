// Problem Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/?envType=daily-question&envId=2026-01-07

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
    long long dfs(auto &root){
        if(root==NULL)return 0;
        root->val+=dfs(root->left)+dfs(root->right);
        return root->val;
    }

    int maxProduct(TreeNode* root) {
        long long tt=dfs(root),ans=0,mod=1e9+7;

        queue<TreeNode*>q;
        q.push(root);

        while(q.size()){
            auto c=q.front();q.pop();

            if(c==NULL)continue;

            long long curr=(tt-c->val)*c->val;
            ans=max(ans,curr);

            if(c->left)q.push(c->left);
            if(c->right)q.push(c->right);
        }

        return ans%mod;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(N)