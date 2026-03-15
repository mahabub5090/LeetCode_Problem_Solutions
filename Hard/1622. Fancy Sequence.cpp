// Problem Link: https://leetcode.com/problems/fancy-sequence/description/?envType=daily-question&envId=2026-03-15

class Fancy {
public:
    using ll=long long;
    int mod=1e9+7;
    vector<int>vc,a,b;

    Fancy() {
        a.push_back(1);
        b.push_back(0);
    }

    // 
    int quickMul(int x,int y){
        ll res=1,curr=x;
        while(y){
            if(y%2)res*=curr,res%=mod;
            curr*=curr;
            curr%=mod;
            y/=2;
        }
        return res;
    }
    int inv(int x){
        return quickMul(x,mod-2);
    }
    // 
    
    void append(int val) {
        vc.push_back(val);
        a.push_back(a.back());
        b.push_back(b.back());
    }
    
    void addAll(int inc) {
        b.back()=(b.back()+inc)%mod;
    }
    
    void multAll(int m) {
        a.back()=1ll*a.back()*m%mod;
        b.back()=1ll*b.back()*m%mod;
    }
    
    int getIndex(int idx) {
        if(idx>=vc.size())return -1;

        int ao=(1ll*inv(a[idx])*a.back())%mod;
        int bo=(b.back()-(1ll*ao*b[idx])%mod+mod)%mod;
        int ans=(1ll*ao*vc[idx]%mod+bo)%mod;
        return ans;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */

 // Time Complexity : O(logM);
 // Space Complexity: O(N);
 // M = mod = 1e9+7;