// Problem Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2024-09-24
// Problem Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2026-05-21

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> mp;
        for(auto &c:arr1){    
            string a=to_string(c), pref="";
            for(auto &c2:a)pref+=c2, mp[pref]++;
        }

        int ans=0;
        for(auto &c:arr2){    
            string a=to_string(c), pref="";
            for(auto &c2:a){
                pref+=c2;
                if(mp.count(pref)) ans=max(ans,(int)pref.size());
            }
        }
        return ans;
    }
};

// Time Complexity : O(N*(L*L)) + O(M*(L*L)) => O((N+M)*(9*9)) => O(N+M); 
// Space Complexity: O(N*(L*L)) => O(N*(9*9)) => O(N);
// L = maximum possible number of digits in arr1[i] or arr2[i];
// 1 <= arr1[i], arr2[i] <= 1e8;