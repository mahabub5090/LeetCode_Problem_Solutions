// Problem Link: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/submissions/1385368831/?envType=daily-question&envId=2024-09-10

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;        
        while(temp->next!=NULL){
            int gcd=__gcd(temp->val,temp->next->val);
            ListNode* curr=new ListNode(gcd);
            curr->next=temp->next;
            temp->next=curr;
            temp=temp->next->next;
        }
        return head;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);