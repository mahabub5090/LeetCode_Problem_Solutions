// Problem Link: https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/?envType=daily-question&envId=2024-08-26

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>ans;
    vector<int> postorder(Node* root) {
        if(root==NULL)return ans;
        for(auto &c:root->children) postorder(c);
        ans.push_back(root->val);
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);