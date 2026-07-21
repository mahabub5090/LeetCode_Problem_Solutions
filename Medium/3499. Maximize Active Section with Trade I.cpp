// Problem Link: https://leetcode.com/problems/maximize-active-section-with-trade-i/description/?envType=daily-question&envId=2026-07-21

// class Solution {
// public:
//     int maxActiveSectionsAfterTrade(string s) {
//         vector<pair<char,int>> sections;
//         int cnt=1, n=s.size();
//         for(int i=1;i<n;i++){
//             if(s[i]==s[i-1]) cnt++;
//             else {
//                 sections.push_back({s[i-1],cnt});
//                 cnt=1;
//             }
//         }
//         sections.push_back({s[n-1],cnt});

//         int len=sections.size();
//         vector<int> pref(len,0);
//         pref[0]=sections[0].first=='1'?sections[0].second:0;
//         for(int i=1;i<len;i++){
//             pref[i]=sections[i].first=='1'?sections[i].second:0;
//             pref[i]+=pref[i-1];
//         }

//         int ans=pref[len-1];
//         for(int i=1;i<len-1;i++){
//             if(sections[i].first=='1'){
//             int tt=sections[i-1].second+sections[i].second+sections[i+1].second;

//                 ans=max(ans,tt+pref[i-1]+pref[len-1]-pref[i]);
//             }
//         }
    
//         return ans;
//     }
// };

// // Time Complexity : O(N) + O(K) + O(K) => O(N);
// // Space Complexity: O(K) + O(K) => O(N);
// // K is the number of contiguous block, K <= N;


// Way: 2 => 

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int cnt=1, mx=0, totalActive=0;
        queue<int> q;

        for(int i=1;i<n+1;i++){
            if(i<n) totalActive+=s[i]=='1';

            if(i<n && s[i]==s[i-1]) cnt++;
            else {
                q.push(cnt);
                cnt=1;

                if(s[i-1]=='0' && q.size()>=3){
                    while(q.size()>3) q.pop();

                    int one=q.front(); q.pop();
                    int two=q.front(); q.pop();
                    int three=q.front(); q.pop();

                    mx=max(mx,one+three);

                    q.push(three);
                }
            }
        }

        return (s[0]=='1') + mx + totalActive;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(4) => O(1);