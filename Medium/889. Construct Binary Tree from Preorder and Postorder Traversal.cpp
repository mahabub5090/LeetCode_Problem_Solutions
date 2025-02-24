// Problem Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/?envType=daily-question&envId=2025-02-24

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
    map<int,int>mp;
    vector<int>vc,vc2;
    TreeNode* build(int pre,int pre2,int post,int post2){
        if(pre>pre2 || post>post2)return 0;

        TreeNode* root=new TreeNode(vc[pre]);

        if(pre!=pre2){
            int l=vc[pre+1];
            int mid=mp[l];
            int ls=mid-post+1;

            root->left=build(pre+1,pre+ls,post,mid);
            root->right=build(pre+ls+1,pre2,mid+1,post2-1);
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        vc=preorder,vc2=postorder;
        int n=preorder.size();
        for(int i=0;i<n;i++){
            mp[postorder[i]]=i;
        }
        return build(0,n-1,0,n-1);
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);