// Problem Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/?envType=daily-question&envId=2025-02-27

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int>st(arr.begin(),arr.end());
        for(auto &c:arr)st.insert(c);
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(st.find(arr[i]+arr[j])!=st.end()){
                    int cnt=3;
                    int last=arr[i]+arr[j];
                    int last2=arr[j];
                    while(st.find(last+last2)!=st.end()){
                        cnt++;
                        int temp=last;
                        last=last+last2;
                        last2=temp;
                    }
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};


// Time Complexity : O(N^2)*O(logN) => O((N^2)logN);
// Space Complexity: O(N);
