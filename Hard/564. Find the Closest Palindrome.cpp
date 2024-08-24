// Problem Link: https://leetcode.com/problems/find-the-closest-palindrome/description/?envType=daily-question&envId=2024-08-24

class Solution {
public:
    long long findPal(long long firstHalf,int odd){
        if(odd){
            string c=to_string(firstHalf),c2="";
            c2=c; char mid=c.back();
            c.pop_back(),c2.pop_back();
            reverse(c.begin(),c.end());  
            return stoll(c2+mid+c);
        }
        string c=to_string(firstHalf),c2="";
        c2=c; reverse(c.begin(),c.end());
        return stoll(c2+c);
    }
    string nearestPalindromic(string n) {
        int s=n.size(),mid=s/2+(s%2);
        long long num=stoll(n);
        vector<long long>vc;
        long long firstHalf=stoll(n.substr(0,mid));
        vc.push_back(findPal(firstHalf,s%2));
        vc.push_back(findPal(firstHalf-1,s%2));
        vc.push_back(findPal(firstHalf+1,s%2));
        vc.push_back(pow(10,s-1)-1);
        vc.push_back(pow(10,s)+1);
        long long ans=LLONG_MAX,diff=LLONG_MAX;
        for(auto &c:vc){
            if(c==num)continue;
            long long curr=abs(num-c);
            if(curr==diff){
                ans=min(ans,c);
            }
            if(curr<diff){
                ans=c;
                diff=curr;
            }
        }
        return to_string(ans);
    }
};

// Time Complexity : O(s); 
// Space Complexity: O(s);
// s is the length of input string n;