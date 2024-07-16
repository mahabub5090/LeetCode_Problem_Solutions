// Problem Link: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/?envType=daily-question&envId=2024-07-16

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
    string start,dest;
    void dfs(TreeNode *node,string &s,int sv,int dv){
            if(node==NULL)return;
            if(node->val==sv)start=s;
            if(node->val==dv)dest=s;
            s+='L'; dfs(node->left,s,sv,dv); s.pop_back();
            s+='R'; dfs(node->right,s,sv,dv); s.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s="";
        dfs(root,s,startValue,destValue);
        int i=0;
        while(start[i]==dest[i])i++;
        string ans="";
        for(int j=0;j<start.size()-i;j++)ans+='U';
        for(int j=i;j<dest.size();j++)ans+=dest[j];
        return ans;
    }
};

// Time Complexity: O(3*N) => O(N);
// Space Complexity: O(3*N) => O(N);