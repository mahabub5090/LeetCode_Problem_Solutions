// Problem Link: https://leetcode.com/problems/ugly-number-ii/?envType=daily-question&envId=2024-08-18

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>vc={1};
        int i=0,j=0,k=0;
        while(n--){
            // for(auto &c:vc)cout<<c<<" ";
            // cout<<endl;
            // cout<<i<<" "<<j<<" "<<k<<" "<<vc[i]*2<<" "<<vc[j]*3<<" "<<vc[k]*5<<endl;
               
            vc.push_back(min({vc[i]*2,vc[j]*3,vc[k]*5}));
            if(vc.back()==vc[i]*2)i++;
            if(vc.back()==vc[j]*3)j++;
            if(vc.back()==vc[k]*5)k++;
        }
        return vc[vc.size()-2];
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);