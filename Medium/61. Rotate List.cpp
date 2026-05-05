// Problem Link: https://leetcode.com/problems/rotate-list/description/?envType=daily-question&envId=2026-05-05

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
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         ListNode* curr=head;
//         vector<int> arr;
//         while(curr){
//             arr.push_back(curr->val);
//             curr=curr->next;
//         }
//         int n=arr.size();
//         if(n && k) k%=n;
//         if(n==0 || k==0) return head;

//         head=new ListNode(arr[n-k]);
//         curr=head;
//         for(int i=n-k+1;i<n;i++){    
//             curr->next=new ListNode(arr[i]);
//             curr=curr->next;
//         }
//         for(int i=0;i<n-k;i++){    
//             curr->next=new ListNode(arr[i]);
//             curr=curr->next;
//         }
//         return head;
//     }
// };

// // Time Complexity : O(N) + O(N) => O(N);
// // Space Complexity: O(N);

// Way: 2 =>

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;

        ListNode *tail=head;
        int n=1;
        while(tail->next)tail=tail->next,n++;

        k%=n;
        if(k==0) return head;

        tail->next=head;
        int move=n-k;

        while(move--) tail=tail->next;

        head=tail->next;
        tail->next=NULL;
        return head;
    }
};

// Time Complexity : O(N) + O(N) => O(N);
// Space Complexity: O(1);