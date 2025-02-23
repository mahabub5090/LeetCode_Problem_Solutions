// Problem Link: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/?envType=daily-question&envId=2025-02-24

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
    TreeNode *solve(int &i,int depth,auto &t){
        if(i>=t.size())return 0;
        int dash=0;
        while(i+dash<t.size() && t[i+dash]=='-')dash++;
        if(dash!=depth)return 0;
        i+=dash;
        int val=0;
        while(i<t.size() && isdigit(t[i])){
            val=val*10+t[i]-'0';
            i++;
        }

        TreeNode *node = new TreeNode(val);

        node->left=solve(i,depth+1,t);
        node->right=solve(i,depth+1,t);

        return node;    
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i=0;
        return solve(i,0,traversal);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);