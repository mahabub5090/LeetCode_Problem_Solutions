// Problem Link: https://leetcode.com/problems/split-linked-list-in-parts/description/?envType=daily-question&envId=2024-09-08

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
    ListNode* arrToList(auto &c){
        if(c.empty())return NULL;
        ListNode* head = new ListNode(c[0]);
        ListNode* current = head;
        for (int i = 1; i < c.size(); i++) {
            ListNode* newNode = new ListNode(c[i]);
            current->next = newNode;
            current = newNode;
        } 
        return head;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp=head;
        int tt=0;
        vector<int>vc;
        while(temp!=NULL){
            tt++;
            vc.push_back(temp->val);
            temp=temp->next;
        };        
        int size=tt/k;
        int rem=tt%k;
        vector<vector<int>>ans;
        int id=0;
        for(int i=0;i<vc.size();i+=max(size,1)){
            vector<int>temp;
            for(int j=0;j<size+(rem>0) && id<vc.size();j++)temp.push_back(vc[id++]);
            rem-=1;
            ans.push_back(temp);
        }
        vector<ListNode*>mainAns;   
        bool fg=0; 
        for(auto &c:ans){
            ListNode *temp2=arrToList(c);
            if(temp2==NULL)fg=1;
            mainAns.push_back(temp2);
        }
        if(fg){
            while(mainAns.back()==NULL)mainAns.pop_back();
        }
        if(k>tt){
            for(int i=tt;i<k;i++){
                mainAns.push_back({});
            }
        }
        return mainAns;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);