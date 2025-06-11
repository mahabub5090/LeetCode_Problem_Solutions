// Problem Link: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/description/?envType=daily-question&envId=2025-06-11

class Solution {
public:
    int getStatus(int cnt,int cnt2){
        return ((cnt&1)<<1)|(cnt2&1);
    }
    int maxDifference(string s, int k) {
        int n=s.size(),ans=INT_MIN;

        for(char c='0';c<'5';c++){
            for(char cc='0';cc<'5';cc++){
                if(c==cc)continue;
                int best[4]={INT_MAX,INT_MAX,INT_MAX,INT_MAX};
                int cnt=0,cnt2=0,prev=0,prev2=0;
                int l=-1;
                for(int r=0;r<n;r++){
                    cnt+=s[r]==c;
                    cnt2+=s[r]==cc;
                    while(r-l>=k && cnt2-prev2>=2){
                        int ls=getStatus(prev,prev2);
                        best[ls]=min(best[ls],prev-prev2);
                        l++;
                        prev+=s[l]==c;
                        prev2+=s[l]==cc;
                    }
                    int rs=getStatus(cnt,cnt2);
                    if(best[rs^2]!=INT_MAX){
                        ans=max(ans,cnt-cnt2-best[rs^2]);
                    }
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);

// The following soltuion got TLE =>

// class Solution {
// public:
//     int maxDifference(string s, int k) {
//         int n=s.size(),ans=INT_MIN;
//         for(int i=0;i<n-k+1;i++){
//             int z=0,o=0,t=0,th=0,f=0;
//             for(int j=i;j<n;j++){
//                 if(s[j]=='0')z++;
//                 if(s[j]=='1')o++;
//                 if(s[j]=='2')t++;
//                 if(s[j]=='3')th++;
//                 if(s[j]=='4')f++;
//                 if(j+1>=i+k){
//                     vector<int>odd,even;
//                     if(z%2)odd.push_back(z);
//                     if(o%2)odd.push_back(o);
//                     if(t%2)odd.push_back(t);
//                     if(th%2)odd.push_back(th);
//                     if(f%2)odd.push_back(f);

//                     if(z && z%2==0)even.push_back(z);
//                     if(o && o%2==0)even.push_back(o);
//                     if(t && t%2==0)even.push_back(t);
//                     if(th && th%2==0)even.push_back(th);
//                     if(f && f%2==0)even.push_back(f);

//                     int diff=INT_MIN;
//                     for(auto &c:odd){
//                         for(auto &cc:even){
//                             diff=max(diff,c-cc);
//                         }
//                     }
//                     if(odd.size() && even.size())ans=max(ans,diff);
//                 }
//             }
//         }
//         return ans;
//     }
// };

// Time Complexity : O(N^2);
// Space Complexity: O(1);