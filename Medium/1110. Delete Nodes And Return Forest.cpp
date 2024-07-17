// Problem Link: https://leetcode.com/problems/delete-nodes-and-return-forest/description/?envType=daily-question&envId=2024-07-17

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
    vector<TreeNode*>ans;
    unordered_set<int>st;
    void dfs(TreeNode *parent,TreeNode* root){
        if(root==NULL)return;
        if(root->left!=NULL)dfs(root,root->left);
        if(root->right!=NULL)dfs(root,root->right);

        if(st.find(root->val)!=st.end()){
            if(root->left!=NULL)ans.push_back(root->left);
            if(root->right!=NULL)ans.push_back(root->right);

            if(parent==NULL)return;

            if(parent->left!=NULL && parent->left->val==root->val) parent->left=NULL;
            if(parent->right!=NULL && parent->right->val==root->val) parent->right=NULL;
        };
    }   
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){
        for(auto &c:to_delete)st.insert(c);
        dfs(NULL,root);
        if(st.find(root->val)==st.end())ans.push_back(root);
        return ans;
    }
};


// Time Complexity : O(N+M) => O(2*N) => O(N); // M is the size of 'to_delete' vector;
// Space Complexity: O(N+M) => O(2*N) => O(N);

// We can use unordered_map rather than using unordered_set in this code. But unordered_set in slightly better than unordered_map while both are using hash table. Beacuse unordered_set is single pair but unordered_map is key,value pair.
// We can also use set/map here rather than unordered_set. But this will increase the exact time complexity O(N+M) to O(N+ M log N);