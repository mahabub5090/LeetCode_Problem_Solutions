// Problem Link: https://leetcode.com/problems/block-placement-queries/description/?envType=daily-question&envId=2026-05-30


class Solution {
public:
    int maxi=5e4+1;
    vector<int> seg;

    void update(int node,int l,int r,int index,int val){
        if(l==r){
            seg[node]=val;
            return;
        }
        int mid=(l+r)/2;

        if(index<=mid) update(2*node,l,mid,index,val);
        else update(2*node+1,mid+1,r,index,val);

        seg[node]=max(seg[2*node],seg[2*node+1]);
    }
    int query(int node,int l,int r,int ql,int qr){
        if(qr<l || ql>r) return 0;
        if(ql<=l && r<=qr) return seg[node];

        int mid=(l+r)/2;
        int left=query(2*node,l,mid,ql,qr);
        int right=query(2*node+1,mid+1,r,ql,qr);
        return max(left,right);
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        seg.resize(4*maxi,0);

        set<int>barriers;
        barriers.insert(0);

        for(auto &c:queries){
            if(c[0]==1) barriers.insert(c[1]);
        }

        vector<int> pos(barriers.begin(),barriers.end());
        for(int i=1;i<pos.size();i++){
            update(1,0,maxi,pos[i],pos[i]-pos[i-1]);
        }

        vector<bool> ans;
        for(int i=queries.size()-1;i>=0;i--){
            if(queries[i][0]==1){
                int x=queries[i][1];

                auto it=barriers.find(x);
                int leftBarrier=*prev(it);

                update(1,0,maxi,x,0);

                auto rightIt=next(it);
                if(rightIt!=barriers.end()){
                    int rightBarrier=*rightIt;
                    update(1,0,maxi,rightBarrier,rightBarrier-leftBarrier);
                }
    
                barriers.erase(it);
            }
            else{
                int x=queries[i][1];
                int sz=queries[i][2];

                auto it=prev(barriers.upper_bound(x));

                int prevBarrier=*it;
                int bestGap=query(1,0,maxi,0,prevBarrier);
                bestGap=max(bestGap,x-prevBarrier);
                ans.push_back(bestGap>=sz);
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Time Complexity : O(NlogN) + O(NlogM) + O(N*(logN+logM)) + O(N) => O(N*(logN+logM));
// Space Complexity: O(4*M) + O(N) + O(N) + O(N) => O(N+M);
// N = queries.size(), M = maxi;
