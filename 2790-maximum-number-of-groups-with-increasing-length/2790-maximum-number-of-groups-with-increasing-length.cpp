#define ll long long int
class Solution {
public:
    int check(vector<int>usage,int n,ll mid,ll pre[])
    {
        for(int i=n-1;i>=0;i--)
        {
            if(mid==0)
                return true;
            ll sum=(mid*(mid+1));
            sum=sum/2;
            if(sum>pre[i])
                return false;
            mid--;
        }
        return true;
        
    }
    int maxIncreasingGroups(vector<int>& usageLimits) 
    {
        int n=usageLimits.size();
        ll l=0;
        ll r=n;
        ll ans=0;
        sort(usageLimits.begin(),usageLimits.end());
        ll pre[n+1];
        for(int i=0;i<=n;i++)
        {
            pre[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(i==0)
                pre[i]=usageLimits[i];
            else
                pre[i]=pre[i-1]+usageLimits[i];
        }
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(check(usageLimits,n,mid,pre))
            {
                ans=max(ans,mid);
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};