// Problem Link: https://leetcode.com/problems/separate-squares-ii/description/?envType=daily-question&envId=2026-01-14

class Solution {
public:
    class Slab{
        public:
        long long y,y2,w;
        long double before;
        
        Slab(long long y,long long y2,long long w,long double before){
            this->y=y;
            this->y2=y2;
            this->w=w;
            this->before=before;
            }
    };

    vector<long long>cnt,cover,vc;
    int n;

    void pull(int pos,int l,int r){
        if(cnt[pos]>0)cover[pos]=vc[r+1]-vc[l];
        else if(l==r)cover[pos]=0;
        else cover[pos]=cover[pos*2+1]+cover[pos*2+2];
    }
    void update(int ql,int qr,int val,int pos,int l,int r){
        if(vc[r+1]<=ql || vc[l]>=qr)return;

        if(ql<=vc[l] && vc[r+1]<=qr){
            cnt[pos]+=val;
            pull(pos,l,r);
            return;
        }

        int mid=(l+r)/2;
        update(ql,qr,val,pos*2+1,l,mid);
        update(ql,qr,val,pos*2+2,mid+1,r);
        pull(pos,l,r);
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<long long,int,long long,long long>>events;
        vc.clear();

        for(auto &c:squares){
            long long x=c[0],y=c[1],l=c[2];
            events.push_back({y,1,x,x+l});
            events.push_back({y+l,-1,x,x+l});
            vc.push_back(x);
            vc.push_back(x+l);
        }

        sort(vc.begin(),vc.end());
        vc.erase(unique(vc.begin(),vc.end()),vc.end());
        
        sort(events.begin(),events.end());

        n=vc.size()-1;
        cnt.assign(4*n,0);
        cover.assign(4*n,0);

        vector<Slab>slabs;
        long double tt=0;
        long long prevY=get<0>(events[0]);

        for(int i=0;i<events.size();){
            long long currY=get<0>(events[i]);
            long long dy=currY-prevY;
            long long currW=cover[0];

            if(dy>0 && currW>0){
                slabs.push_back({prevY,currY,currW,tt});
                tt+=(long double)currW*dy;
            }

            while(i<events.size() && get<0>(events[i])==currY){
                auto [y,val,x,x2]=events[i];
                update(x,x2,val,0,0,n-1);
                i++;
            }

            prevY=currY;
        }

        long double target=tt/2.0;
        for(auto &c:slabs){
            long double slabA=(long double)c.w*(c.y2-c.y);

            if(c.before+slabA>=target-(1e-9)){
                long double need=target-c.before;
                return (double)(c.y+(need/c.w));
            }
        }
        return 0.0;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);