// Problem Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2024-07-15

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode *>mp;
        map<int,bool>isChild;
        TreeNode *parent=NULL,*child=NULL;
        int pv,cv;bool isL;

        for(auto &c:descriptions){
            pv=c[0],cv=c[1],isL=c[2];

            if(mp[pv]==NULL)parent= new TreeNode(pv);
            else parent=mp[pv];

            if(mp[cv]==NULL)child= new TreeNode(cv);
            else child=mp[cv];

            (isL?parent->left:parent->right)=child;
            
            mp[pv]=parent;
            mp[cv]=child;
            isChild[cv]=1;
        }

        TreeNode* root;
        for(auto &[val,node]:mp)if(!isChild[val])root=node;
        return root;
    }
};

// Time Complexity : O(N * (2* log N)) => O(N log N);
// Space Complexity: O(2*N) => O(N);