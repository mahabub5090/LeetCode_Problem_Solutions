// Problem Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/?envType=daily-question&envId=2026-01-09

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
    int maxDept=0;
    TreeNode* ans=NULL;

    int dfs(auto &root, int dept){
        maxDept=max(maxDept,dept);

        if(root==NULL)return dept;
        
        int l=dfs(root->left,dept+1);
        int r=dfs(root->right,dept+1);

        if(l==maxDept && r==maxDept)ans=root;

        return max(l,r);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);