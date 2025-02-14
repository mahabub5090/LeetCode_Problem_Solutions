// Problem Link: https://leetcode.com/problems/product-of-the-last-k-numbers/description/?envType=daily-question&envId=2025-02-14

// class ProductOfNumbers {
// public:
//     vector<int>vc;
    
//     ProductOfNumbers() {
        
//     }
    
//     void add(int num) {
//         vc.push_back(num);
//     }
    
//     int getProduct(int k) {
//         int ans=1,n=vc.size(),i=n-1;
//         while(n-i-1<k)ans*=vc[i],i--;
//         return ans;
//     }
// };

// Time Complexity : O(N)*O(K) => O(N^2);
// Space Complexity: O(N);
// Here N is the total call of add and getProduct; And K is the maximam parameter of getProduct function;

// Way: 02 => 

class ProductOfNumbers {
public:
    vector<int>vc={1},pref={1};
    int cnt=0;

    ProductOfNumbers() {

    }
    void add(int num) {
        if(num==0){
            pref={1};
            cnt=0;
            return;
        }
        int last=(pref.back()?pref.back():1);
        pref.push_back(last*num);
        cnt++;
    }
    
    int getProduct(int k) {
        int n=pref.size();
        if(cnt<k)return 0;
        return pref[n-1]/pref[n-1-k];
    }
};

// Time Complexity : O(N) * O(1) => O(N);
// Space Complexity: O(N);
// Here N is the total call of add and getProduct;

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */