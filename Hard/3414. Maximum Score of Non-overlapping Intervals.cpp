// Problem Link: https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/description/?envType=daily-question&envId=2026-09-13

class Solution {
public:
	using ll = long long;
    
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> vc;
        for(int i=0;i<n;i++){
            int l=intervals[i][0], r=intervals[i][1], w=intervals[i][2];
			vc.push_back({l,r,w,i});
        }

		sort(vc.begin(), vc.end(), [](auto &a, auto &b){
           return a[1]<b[1];
        });

        vector<vector<ll>> dp(n+1, vector<ll>(5));
        vector<vector<vector<int>>> indices(n+1, vector<vector<int>>(5));

        for(int i=0;i<n;i++){
            int l=vc[i][0], r=vc[i][1], w=vc[i][2], index=vc[i][3];

			int k=lower_bound(vc.begin(), vc.begin()+i, l, [](auto &a, int val){
                return a[1]<val;
                }) - vc.begin();

            for(int j=1;j<5;j++){
                ll s=dp[i][j];
                ll s2=dp[k][j-1]+w;

                if(s>s2){
					dp[i+1][j]=dp[i][j];
                    indices[i+1][j]=indices[i][j];
                    continue;
                }

                vector<int> ni=indices[k][j-1];
                ni.push_back(index);
                sort(ni.begin(), ni.end());

                if(s==s2 && ni>indices[i][j]) ni=indices[i][j];

                dp[i+1][j]=s2;
                indices[i+1][j]=ni;
            }
        }
        
        return indices[n][4];
    }
};

// Time Complexity : O(N) + O(NlogN) + O(N*logN) => O(NlogN);
// Space Complexity: O(N) + O(N*5) + O(N*5) => O(N);