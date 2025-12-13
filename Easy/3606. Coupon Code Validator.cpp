// Problem Link: https://leetcode.com/problems/coupon-code-validator/description/?envType=daily-question&envId=2025-12-13

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>>vc;
        for(int i=0;i<code.size();i++){
            if(isActive[i]){
                vc.push_back({code[i],businessLine[i]});
            }
        }

        sort(vc.begin(),vc.end(),[](auto &c,auto &d){
            if(c.second==d.second)return c.first<d.first;
            if(c.second=="electronics")return true;
            if(d.second=="electronics")return false;
            if(c.second=="grocery")return true;
            if(d.second=="grocery")return false;
            if(c.second=="pharmacy")return true;
            if(d.second=="pharmacy")return false;
            if(c.second=="restaurant")return true;
            return false;
        });

        vector<string>ans;
        for(int i=0;i<vc.size();i++){
            string cupon=vc[i].first,line=vc[i].second;
            int cnt=0;
            for(auto &c:cupon){
                if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') || c=='_')continue;
                cnt++;
                break;
            }
            if(cnt)continue;
            if(line!="electronics" && line!="grocery" && line!="pharmacy" && line!="restaurant")cnt++;
            if(cnt==0 && cupon.size())ans.push_back(cupon);
        }
        return ans;
    }
};

// Time Complexity : O(2*N) + O(NlogN) => O(NlogN);
// Space Complexity: O(N);