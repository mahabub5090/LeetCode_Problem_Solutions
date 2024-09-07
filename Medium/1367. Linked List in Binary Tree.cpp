// Problem Link: https://leetcode.com/problems/linked-list-in-binary-tree/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(auto head,auto curr,auto &root){
        if(curr==NULL)return 1;
        if(root==NULL)return 0;
        if(curr->val==root->val)curr=curr->next;
        else if (head->val==root->val)head=head->next;
        else curr=head;
        return dfs(head,curr,root->left)||dfs(head,curr,root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head,head,root);
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N) => O(N);
// N = head size and M= root size;