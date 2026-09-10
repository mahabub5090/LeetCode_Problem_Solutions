// Problem Link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/?envType=daily-question&envId=2026-09-10

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
    int cnt=0;

    void dfs(int &sum, int &nodeCnt, auto &node){
        if(node==NULL){
            sum=0;
            nodeCnt=0;
            return;
        } 

        int lsum=0, lcnt=0;
        int rsum=0, rcnt=0;

        dfs(lsum, lcnt, node->left);        
        dfs(rsum, rcnt, node->right);

        sum = lsum+rsum+node->val;
        nodeCnt = lcnt+rcnt+1;
        if(sum/nodeCnt == node->val) cnt++;
    }


    int averageOfSubtree(TreeNode* root) {
        int sum, nodeCnt;
        dfs(sum, nodeCnt, root);
        return cnt;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);