// Problem Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=daily-question&envId=2026-06-14

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
//     int pairSum(ListNode* head) {
//         vector<int> vc;
//         while(head){
//             vc.push_back(head->val);
//             head=head->next;
//         }

//         int ans=0, n=vc.size();
//         for(int i=0;i<n/2;i++) ans=max(ans,vc[i]+vc[n-1-i]);
//         return ans;
//     }
// };

// // Time Complexity : O(N) + O(N) => O(N);
// // Space Complexity: O(N);


// Way: 2 =>

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
public:
    int pairSum(ListNode* head) {
        ListNode *slow=head, *fast=head, *prev=NULL;
        while(fast && fast->next){
            fast=fast->next->next;

            ListNode *nextNode=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextNode;
        }

        int ans=0;
        ListNode *left=prev,*right=slow;
        while(left){
            ans=max(ans,left->val + right->val);
            left=left->next;
            right=right->next;
        }
        return ans;
    }
};

// Time Complexity : O(N/2) + O(N/2) => O(N);
// Space Complexity: O(1);