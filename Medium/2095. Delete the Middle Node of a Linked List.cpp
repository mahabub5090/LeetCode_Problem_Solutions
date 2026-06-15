// Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=daily-question&envId=2026-06-15

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
//     ListNode* deleteMiddle(ListNode* head) {
//         int cnt=0;
//         ListNode *curr=head;
//         while(curr){
//             cnt++;
//             curr=curr->next;
//         }

//         int mid=cnt/2+1;
//         ListNode *ans=new ListNode(0);
//         curr=ans, cnt=0;

//         while(head){
//             int val=head->val;
//             head=head->next;

//             cnt++;
//             if(cnt==mid)continue;
        
//             curr->next=new ListNode(val);
//             curr=curr->next;
//         }
//         return ans->next;
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL) return NULL;

        ListNode *slow=head, *fast=head, *prev=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        prev->next=slow->next;
        delete slow;

        return head;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);