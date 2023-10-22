class Solution {
public:
    int dp[202][202][202];
    int dp1[201][201];
    int cal(int f,int s1,int num,int d,string &s)
    {
        int cnt=0;
       // cout<<f<<" "<<s1<<" "<<d<<" "<<num<<"\n";
     for(int i=0;i<d;i++)
      {
         for(int j=f+i,k=j+(num-1)*d;j<k;j+=d,k-=d)
         {
            // cout<<j<<" "<<k<<"\n";
             if(s[j]!=s[k])
               cnt++;  
         }
      }
      //  cout<<cnt<<"\n";
        return cnt;
    }
    int fin(int idx,int lastidx,int ktm,string &s,int n)
    {
        if(dp1[idx][lastidx]!=-1)
            return dp1[idx][lastidx];
        if((idx-lastidx+1)==1)
            return dp1[idx][lastidx]=1e9;
        dp1[idx][lastidx]=(idx-lastidx);
        int ans=1e9;
        int len=(idx-lastidx+1);
       // cout<<len<<" "<<"length"<<"\n";
         for(int i=1;i*i<=(idx-lastidx+1);i++)
        {
             if(len%i!=0)
                 continue;
            int div=i;
            int div1=len/i;
           // cout<<div<<" "<<i<<"\n";
            int val=cal(lastidx,idx,div1,i,s);
             int val1=1e9;
            if(div!=1&&div!=div1)
            {
                val1=cal(lastidx,idx,i,div1,s);
            }
            ans=min(ans,min(val,val1));
            // cout<<val<<" "<<i<<" "<<val1<<" "<<div1<<" "<<idx<<" "<<lastidx<<"\n";
        }
        dp1[idx][lastidx]=ans;
     //   cout<<ans<<" "<<idx<<" "<<lastidx<<"\n";
        return ans;
    }
    int solve(int idx,int lastidx,int ktm,string &s,int k,int n)
    {
        //cout<<idx<<"\n";
        //return 1;
        if(idx==n)
        {
            if(lastidx==n&&ktm==0)
            {
                dp[idx][lastidx][ktm+4]=0;
                return 0;
            }
            else
              return 1e9;
        }
        if(ktm<=0)
        {
            dp[idx][lastidx][ktm+4]=1e9;
            return 1e9;
        }
        if(dp[idx][lastidx][ktm+4]!=-1)
            return dp[idx][lastidx][ktm+4];
        int ans=1e9;
        int len=idx-lastidx+1;
        ans=min(ans,fin(idx,lastidx,ktm,s,n)+solve(idx+1,idx+1,ktm-1,s,k,n));
        ans=min(ans,solve(idx+1,lastidx,ktm,s,k,n));
        dp[idx][lastidx][ktm+4]=ans;
       // cout<<ans<<"\n";
        return ans;
    }
    int minimumChanges(string s, int k) 
    {
        memset(dp,-1,sizeof dp);
        memset(dp1,-1,sizeof dp1);
        int n=s.length();
        return solve(0,0,k,s,k,n);
    }
};