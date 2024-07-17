// Problem Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>vc;
        while(head!=NULL){
            vc.push_back(head->val);
            head=head->next;
        }
        vector<int>ans;
        for(int i=1;i<vc.size()-1;i++){
            if(vc[i-1]>vc[i] && vc[i+1]>vc[i])ans.push_back(i+1);
            if(vc[i-1]<vc[i] && vc[i+1]<vc[i])ans.push_back(i+1);
        }
        if(ans.size()<2)return {-1,-1};
        int mx=ans[ans.size()-1]-ans[0],mn=1e9;
        for(int i=0;i<ans.size()-1;i++){
            mn=min(mn,ans[i+1]-ans[i]);
        }
        return {mn,mx};
    }
};

// Time Complexity : O(3*N) => O(N);
// Space Complexity: O(2*N) => O(N);