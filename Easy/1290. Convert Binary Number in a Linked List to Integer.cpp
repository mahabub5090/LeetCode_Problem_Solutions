// Problem Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/?envType=daily-question&envId=2025-07-14

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
    int cnt=0;
    int dfs(ListNode* head){
        if(head==NULL)return 0;
        int rest=dfs(head->next);
        cnt++;
        return rest+(head->val?pow(2,cnt-1):0);
    }
    int getDecimalValue(ListNode* head) {
        int ans=0;
        ans=dfs(head);
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(N); // Due to call stack;

// Way => 2:

class Solution {
public: 
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head){
            ans*=2;
            ans+=head->val;
            head=head->next;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);
