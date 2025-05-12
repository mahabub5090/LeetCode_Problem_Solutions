// Problem Link: https://leetcode.com/problems/finding-3-digit-even-numbers/description/?envType=daily-question&envId=2025-05-12

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==j || i==k || j==k)continue;

                    int num=digits[i]*100+digits[j]*10+digits[k];
                    if(num%2==0 && num>99)st.insert(num);
                }
            }
        }
        vector<int>ans;
        for(auto &c:st)ans.push_back(c);
        return ans;
    }
};

// Time Complexity : O(N^3);
// Space Complexity: O(N);