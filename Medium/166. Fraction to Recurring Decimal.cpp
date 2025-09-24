// Problem Link: https://leetcode.com/problems/fraction-to-recurring-decimal/description/?envType=daily-question&envId=2025-09-24

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)return "0";

        string frac="";
        if((numerator<0)^(denominator<0))frac+='-';

        long long dividend=llabs(1ll*numerator);
        long long divisor=llabs(1ll*denominator);
        frac+=to_string(dividend/divisor);
        long long rem=dividend%divisor;
        if(rem==0)return frac;

        frac+='.';
        map<long long,int>mp; 
        while(rem!=0){
            if(mp.count(rem)){
                frac.insert(mp[rem],"(");
                frac+=')';
                break;
            }
            mp[rem]=frac.size();
            rem*=10;
            frac+=to_string(rem/divisor);
            rem%=divisor;
        }
        return frac;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);