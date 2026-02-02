// Problem Link: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/description/?envType=daily-question&envId=2026-02-02

class Solution {
public:
    class Container{
        int k;
        long long tt=0;
        multiset<int>st,st2;

        public:
            Container(int val){
                k=val;
                tt=0;
            }
        
            void adjust(){
                while(st.size()<k && st2.size()>0){
                    int num=*st2.begin();
                    st.insert(num);
                    tt+=num;
                    st2.erase(st2.begin());
                }
                while(st.size()>k){
                    int num=*prev(st.end());
                    st2.insert(num);
                    st.erase(prev(st.end()));
                    tt-=num;
                }
            }
            
            void add(int num){
                if(st2.size() && num>=*st2.begin())st2.insert(num);
                else st.insert(num),tt+=num;
                adjust();
            }

            void erase(int num){
                auto it=st.find(num);

                if(it!=st.end())st.erase(it),tt-=num;
                else st2.erase(st2.find(num));
                adjust();
            }

            long long sum(){
                return tt;
            }
    };

    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();

        Container cnt(k-2);
        for(int i=1;i<k-1;i++)cnt.add(nums[i]);

        long long ans=cnt.sum()+nums[k-1];
        for(int i=k;i<n;i++){
            int j=i-dist-1;
            if(j>0)cnt.erase(nums[j]);
            cnt.add(nums[i-1]);
            ans=min(ans,cnt.sum()+nums[i]);
        }
        return ans+nums[0];
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);