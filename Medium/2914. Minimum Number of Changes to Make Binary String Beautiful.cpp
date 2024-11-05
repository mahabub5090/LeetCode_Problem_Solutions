// Problem Link: 2914. Minimum Number of Changes to Make Binary String Beautiful

class Solution {
public:
    int minChanges(string s) {
        int cnt=0,cnt2=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')cnt++;
            else cnt2++;
            if((i+1)%2==0){
                ans+=min(cnt,cnt2);
                cnt=0;
                cnt2=0;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);