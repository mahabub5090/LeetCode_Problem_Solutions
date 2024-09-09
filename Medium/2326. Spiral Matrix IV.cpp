// Problem Link: https://leetcode.com/problems/spiral-matrix-iv/submissions/1384408441/?envType=daily-question&envId=2024-09-09

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int>vc;
        while(head!=NULL)vc.push_back(head->val),head=head->next;

        vector<vector<int>>ans(m,vector<int>(n,-1));
        int id=0,s=vc.size();
        int i=0,j=0,cnt=0;
        while(id<s){
           while(j<n && id<s)ans[i][j++]=vc[id++];
           j--;i++;
           while(i<m && id<s)ans[i++][j]=vc[id++];
           i--;j--;
           while(j>cnt && id<s)ans[i][j--]=vc[id++];
           while(i>cnt && id<s)ans[i--][j]=vc[id++];
           cnt++;
           i++,j++;
           n--,m--;
        }
        return ans;
    }
};

// Time Complexity : O(M*N) => O(N^2);
// Space Complexity: O(M*N) => O(N^2);