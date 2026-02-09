// Problem Link: https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2026-02-09

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
    void rightRotate(auto &parent,auto &node){
        TreeNode *temp=node->left;
        node->left=temp->right;
        temp->right=node;
        parent->right=temp;
    }
    void leftRotate(auto &parent,auto &node){
        TreeNode *temp=node->right;
        node->right=temp->left;
        temp->left=node;
        parent->right=temp;
    }
    void makeRotations(auto &head,int cnt){
        TreeNode *curr=head;
        for(int i=0;i<cnt;i++){
            TreeNode *temp=curr->right;
            leftRotate(curr,temp);
            curr=curr->right;
        }
    }


    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL)return root;

        TreeNode *head=new TreeNode(0);
        head->right=root;
        TreeNode *curr=head;
        while(curr->right){
            if(curr->right->left){
                rightRotate(curr,curr->right);
            }
            else curr=curr->right;
        }

        int nodeCnt=0;
        curr=head->right;
        while(curr){
            nodeCnt++;
            curr=curr->right;
        }

        int n=pow(2,floor(log2(nodeCnt+1)))-1;
        makeRotations(head,nodeCnt-n);

        while(n>1){
            n/=2;
            makeRotations(head,n);
        }

        return head->right;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N); // for recursion;