// Problem Link: https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/description/?envType=daily-question&envId=2025-10-17

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k){
        int n=s.size();
        vector<vector<int>>left(n,vector<int>(3)),right=left;

        int num=0,mask=0,cnt=0;

        for(int i=0;i<n-1;i++){
            int binary=1<<(s[i]-'a');
            if((mask & binary)==0){
                cnt++;
                if(cnt<=k)mask|=binary;
                else num++,mask=binary,cnt=1;
            }
            left[i+1][0]=num;
            left[i+1][1]=mask;
            left[i+1][2]=cnt;
        }

        num=0,mask=0,cnt=0;

        for(int i=n-1;i>0;i--){
            int binary=1<<(s[i]-'a');
            if((mask & binary)==0){
                cnt++;
                if(cnt<=k)mask|=binary;
                else num++,mask=binary,cnt=1;
            }
            right[i-1][0]=num;
            right[i-1][1]=mask;
            right[i-1][2]=cnt;
        }

        int ans=0;

        for(int i=0;i<n;i++){
            int seg=left[i][0]+right[i][0]+2;
            int ttmask=left[i][1]|right[i][1];
            int ttcnt=0;

            while(ttmask)ttmask&=(ttmask-1),ttcnt++;
            
            if(left[i][2]==k && right[i][2]==k && ttcnt<26)seg++;
            else if(min(ttcnt+1,26)<=k)seg--;

            ans=max(ans,seg);
        }

        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);