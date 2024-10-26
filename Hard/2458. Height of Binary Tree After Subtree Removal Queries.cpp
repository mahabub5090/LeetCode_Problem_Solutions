// Problem Link: https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/?envType=daily-question&envId=2024-10-26

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
    int maxh=0;
    int pre[100001]={};
    int po[100001]={};
    
    void preOrder(TreeNode* root,int height){
        if(root==NULL)return;
        pre[root->val]=maxh;
        maxh=max(maxh,height);
        preOrder(root->left,height+1);
        preOrder(root->right,height+1);
    }
    void postOrder(TreeNode* root,int height){
        if(root==NULL)return;
        po[root->val]=maxh;
        maxh=max(maxh,height);
        postOrder(root->right,height+1);
        postOrder(root->left,height+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        preOrder(root,0);
        maxh=0;
        postOrder(root,0);
        vector<int>ans;
        for(auto &c:queries){
            ans.push_back(max(pre[c],po[c]));
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);