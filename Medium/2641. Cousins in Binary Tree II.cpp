// Problem Link: https://leetcode.com/problems/cousins-in-binary-tree-ii/description/?envType=daily-question&envId=2024-10-23

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        map<int,long long>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(q.size()){
            auto c=q.front();q.pop();
            mp[c.second]+=c.first->val;
            if(c.first->left)q.push({c.first->left,c.second+1});
            if(c.first->right)q.push({c.first->right,c.second+1}); 
        }
        root->val=0;
        q.push({root,0});
        while(q.size()){
            auto c=q.front();q.pop();
            int tt=0;
            if(c.first->left)tt+=c.first->left->val;
            if(c.first->right)tt+=c.first->right->val;
            if(c.first->left){
                c.first->left->val=mp[c.second+1]-tt;
                q.push({c.first->left,c.second+1});
            }
            if(c.first->right){
                c.first->right->val=mp[c.second+1]-tt;
                q.push({c.first->right,c.second+1});
            }
        }
        return root;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(N);