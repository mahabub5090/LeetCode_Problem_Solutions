// Problem Link: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/?envType=daily-question&envId=2024-10-22

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        map<int,long long>mp;
        queue<pair<TreeNode*,int>>q;q.push({root,0});
        while(q.size()){
            auto c=q.front();
            q.pop();
            mp[c.second]+=c.first->val;

            if(c.first->left!=NULL)q.push({c.first->left,c.second+1});
            if(c.first->right!=NULL)q.push({c.first->right,c.second+1});
        }
        vector<long long>vc;
        for(auto &c:mp)vc.push_back(c.second);
        sort(vc.rbegin(),vc.rend());
        if(k>vc.size())return -1;
        return vc[k-1];
    }
};

// Time Complexity : O(N) + O(NlogN) => O(NlogN); 
// Space Complexity: O(2*N) => O(N);