// Problem Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/
// Problem Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=daily-question&envId=2026-08-31

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
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         vector<int>vc;
//         while(head!=NULL){
//             vc.push_back(head->val);
//             head=head->next;
//         }
//         vector<int>ans;
//         for(int i=1;i<vc.size()-1;i++){
//             if(vc[i-1]>vc[i] && vc[i+1]>vc[i])ans.push_back(i+1);
//             if(vc[i-1]<vc[i] && vc[i+1]<vc[i])ans.push_back(i+1);
//         }
//         if(ans.size()<2)return {-1,-1};
//         int mx=ans[ans.size()-1]-ans[0],mn=1e9;
//         for(int i=0;i<ans.size()-1;i++){
//             mn=min(mn,ans[i+1]-ans[i]);
//         }
//         return {mn,mx};
//     }
// };

// // Time Complexity : O(3*N) => O(N);
// // Space Complexity: O(2*N) => O(N);


// Way: 2 =>

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
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         vector<int> dist;
        
//         int index=1, prevIndex=-1;
//         ListNode *prevNode=head;
//         head=head->next;

//         while(head && head->next){
//             int prev=prevNode->val, curr=head->val, next=head->next->val;
//             if((prev>curr && curr<next) || (prev<curr && curr>next)){
//                 dist.push_back(index);
//             }

//             index++;
//             prevNode=head;
//             head=head->next;
//         }


//         if(dist.size()<2) return {-1,-1};

//         int minima=INT_MAX, n=dist.size();
//         for(int i=0;i<n-1;i++) minima=min(minima, dist[i+1]-dist[i]);
//         return {minima, dist[n-1]-dist[0]};
//     }
// };

// // Time Complexity : O(N) + O(N) => O(N); 
// // Space COmplexity: O(N);


// Way: 3 =>

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> dist;
        
        int index=1, prevIndex=-1;
        ListNode *prevNode=head;
        head=head->next;

        while(head && head->next){
            int prev=prevNode->val;
            int curr=head->val;
            int next=head->next->val;

            if((prev>curr && curr<next) || (prev<curr && curr>next)){
                if(dist.empty()) dist.push_back(index);
                else if(dist.size()==1) dist.push_back(index-prevIndex);
                else {
                    int prevVal=dist.back(); dist.pop_back();
                    int minDist=min(prevVal, index-prevIndex);
                    dist.push_back(minDist);
                }

                prevIndex=index;
            }

            index++;
            prevNode=head;
            head=head->next;
        }

        if(dist.size()<2) return {-1,-1};

        dist[0]=prevIndex-dist[0];
        swap(dist[0],dist[1]);
        return dist;
    }
};

// Time Complexity : O(N);
// Space COmplexity: O(1);