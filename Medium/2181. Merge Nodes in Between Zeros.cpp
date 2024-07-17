// Problem Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/?envType=daily-question&envId=2024-07-04

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
    ListNode* mergeNodes(ListNode* head) {
        vector<int>s;
        while(head->next!=NULL){
            s.push_back(head->val);
            head=head->next;
        }
        vector<int>ans;
        int i=s.size(),sum=0;
        while(--i>=0){
            while(s[i]!=0){
                sum+=s[i--];
            }
            ans.push_back((sum));
            sum=0;
        }
        reverse(ans.begin(),ans.end());
        ListNode *head2=new ListNode(),*tail=head2,*prev;
        i=0;
        while(i<ans.size()){
            tail->val=ans[i++];
            tail->next=new ListNode();
            prev=tail;
            tail=tail->next;
        }
        prev->next=NULL;
        return head2;     
    }
};

// Time Complexity : O(4*N) => O(N);
// Space Complexity: O(2*N) => O(N);