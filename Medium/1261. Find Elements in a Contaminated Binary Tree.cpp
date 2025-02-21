// Problem Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/?envType=daily-question&envId=2025-02-21

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
class FindElements {
public:
    unordered_set<int>st;
    void dfs(TreeNode* root){
        if(root->left){
            root->left->val=2*(root->val)+1;
            st.insert(root->left->val);
            dfs(root->left);
        }
        if(root->right){
            root->right->val=2*(root->val)+2;
            st.insert(root->right->val);
            dfs(root->right);
        }
    }
    FindElements(TreeNode* root) {
        root->val=0;
        st.insert(0);
        dfs(root);
    }
    
    bool find(int target) {
        return st.find(target)!=st.end();
    }
};

// Time Complexity : O(1) * O(N) => O(N);
// Space Complexity: O(N);

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */