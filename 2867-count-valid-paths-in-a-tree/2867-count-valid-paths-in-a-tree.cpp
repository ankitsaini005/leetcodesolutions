#define ll long long int

ll prime[100005];
 void seive()
    {
     for(int i=0;i<100005;i++)
     {
        prime[i]=1;
     }
     prime[0]=0;
     prime[1]=0;
     for(int i=2;i*i<100005;i++)
     {
        if(prime[i])
        {
         for(int j=i*i;j<100005;j+=i)
         {
            prime[j]=0;
         }
        }
     }
    }
    vector<vector<ll>>adj;
    ll dp[100005];
    ll ans=0;
    void dfs(ll u,ll p)
    {
      ll cnt=0;
      if(!prime[u])
          cnt=1;
       
      for(auto it:adj[u])
      {
         // cout<<it<<" ";
          if(it==p)
              continue;
          //cout<<it<<" "<<u<<"\n";
          dfs(it,u);
          cnt+=dp[it];
      }
        //cout<<"\n";
      dp[u]=cnt;
       // cout<<u<<" "<<p<<" "<<cnt<<"\n";
        if(prime[u])
            dp[u]=0;
        return ;
 //     return (prime[u]?0:dp[u]);
    }
    void dfs1(ll u,ll p,ll cnt)
    {
      if(prime[u])
      {
        ll sum=cnt;
        vector<ll>vec;
        vec.push_back(cnt);
         // cout<<u<<" ";
        for(auto it:adj[u])
        {
            //cout<<it<<" ";
            if(it==p)
                continue;
            dfs1(it,u,0);
            vec.push_back(dp[it]);
            sum+=dp[it];
        }
         // cout<<"\n";
        //  cout<<u<<" "<<sum<<"\n";
          ll val=0;
        for(int i=0;i<vec.size();i++)
        {
            //ll val=vec[i];
            val+=(sum-vec[i])*vec[i];
        }
          ans+=val/2;
          ans+=sum;
          
      }
      else
      {
        for(auto it:adj[u])
        {
            if(it==p)
                continue;
          //  cout<<u<<" "<<it<<" "<<dp[u]<<" "<<dp[it]<<" "<<(cnt+dp[u]-dp[it])<<"\n";
            dfs1(it,u,cnt+dp[u]-dp[it]);
            
        }
      }//dfs1()
    }
class Solution {
public:
    
    
   
    long long countPaths(int n, vector<vector<int>>& edges)
    {
     seive();
        adj.clear();
     adj.resize(n+1);
        ans=0;
     int m=edges.size();
     for(int i=0;i<m;i++)
     {
        ll u=edges[i][0];
         ll v=edges[i][1];
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
     memset(dp,0,sizeof dp);
     dfs(1,0);// calculating down non-prime;
     dfs1(1,0,0);//calculating up non-prime
     return ans;
    }
};