// Problem Link: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/?envType=daily-question&envId=2026-02-24

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
    int ans=0;
    void dfs(auto &root,int num){
        if(root==NULL)return;

        int val=num*2+root->val;
        if(root->left==NULL && root->right==NULL){
            ans+=val;
            return;
        }
        dfs(root->left,val);
        dfs(root->right,val);
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};

// Time Complexity :O(N);
// Space Complexity: O(H) => O(N);
// H is the hight of the tree(root);