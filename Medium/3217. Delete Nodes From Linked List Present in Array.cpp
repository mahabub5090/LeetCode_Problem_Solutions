// Problem Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2024-09-06
// Problem Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2025-11-01

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//         vector<int>vc;
//         map<int,int>mp;
//         while(head!=NULL){
//             vc.push_back(head->val);
//             head=head->next;
//         }
//         for(auto &c:nums) mp[c]++;

//         ListNode* ans=new ListNode(),*temp=ans,*tail;
//         for(auto &c:vc){
//             if(mp[c])continue;
//             temp->val=c;
//             temp->next=new ListNode();
//             tail=temp;
//             temp=temp->next;
//         }
//         tail->next=NULL;
//         return ans;
//     }
// };

// // Time Complexity : O(N+M) => O(N);
// // Space Complexity: O(N+M) => O(N);
// // N = nums size, M= ListNode size;

// way: 2 =>

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
class Solution {
    void dfs(auto &prev,auto &mp){
        while(prev && mp[prev->val])prev=prev->next;
        if(prev)dfs(prev->next,mp);
    }
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(auto &c:nums)mp[c]++;
        dfs(head,mp);
        return head;
    }
};

// Time Complexity : O(N+M) => O(N);
// Space Complexity: O(N+M) => O(N);
// N = nums size, M= ListNode size;
