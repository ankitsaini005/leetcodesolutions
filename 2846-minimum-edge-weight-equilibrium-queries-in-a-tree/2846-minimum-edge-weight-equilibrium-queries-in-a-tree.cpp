#define ll long long int
class Solution {
public:
    vector<vector<pair<ll,ll>>>adj;
    unordered_map<ll,vector<ll>>mp;
    ll sparse[10005][17];
    ll level[10005];
    ll par[10005];
    void dfs(ll u,ll p,ll dep,ll arr1[])
    {
        sparse[u][0]=p;
        level[u]=dep;
        par[u]=p;
        for(auto it:adj[u])
        {
            if(it.first==p)
                continue;
            ll v=it.first;
            ll w=it.second;
            arr1[w]++;
            dfs(v,u,dep+1,arr1);
            arr1[w]--;
        }
        for(int i=0;i<27;i++)
        {
            mp[u][i]=arr1[i];
        }
        
    }
    ll lca(ll u,ll v)
    {
        if(u==v)
            return u;
        if(level[u]>level[v])
            swap(u,v);
        ll d=level[v]-level[u];
        while(d>0)
        {
            ll i=log2(d);
            v=sparse[v][i];
            d=d-(1<<i);
        }
        if(u==v)
            return u;
        for(int i=16;i>=0;i--)
        {
            if(sparse[u][i]!=-1&&sparse[u][i]!=sparse[v][i])
            {
                u=sparse[u][i];
                v=sparse[v][i];
            }
        }
        return par[u];
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) 
    {
        ll sz=edges.size();
        ll q=queries.size();
        adj.resize(n+1);
        for(int i=0;i<sz;i++)
        {
            ll u=edges[i][0];
            ll v=edges[i][1];
            adj[u].push_back(make_pair(v,edges[i][2]));
            adj[v].push_back(make_pair(u,edges[i][2]));
        }
        for(int i=0;i<10005;i++)
        {
            for(int j=0;j<17;j++)
            {
                sparse[i][j]=-1;
            }
        }
        for(int i=0;i<10005;i++)
        {
            level[i]=0;
            par[i]=-1;
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=26;j++)
            {
                mp[i].push_back(0);
            }
        }
        ll arr1[27];
        for(int i=0;i<27;i++)
        {
            arr1[i]=0;
        }
        dfs(0,-1,1,arr1);
        for(int j=1;j<17;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(sparse[i][j-1]!=-1)
                {
                    sparse[i][j]=sparse[sparse[i][j-1]][j-1];
                }
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<27;j++)
        //     {
        //         cout<<mp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        vector<int>ans;
        for(int i=0;i<q;i++)
        {
            ans.push_back(0);
        }
        ll arr[27];
        for(int i=0;i<27;i++)
        {
            arr[i]=0;
        }
        for(int i=0;i<q;i++)
        {
            ll f=queries[i][0];
            ll s=queries[i][1];
            ll cal=lca(f,s);
            //cout<<cal<<" ";
            
            ll maxi=0;
            ll sum=0;
            for(int j=0;j<27;j++)
            {
                arr[j]=mp[f][j]+mp[s][j];
                arr[j]=arr[j]-2*mp[cal][j];
                maxi=max(maxi,arr[j]);
                sum+=arr[j];
            }
            // cout<<cal<<"\n";
            // for(int j=0;j<27;j++)
            // {
            //     cout<<arr[j]<<" ";
            // }
            // cout<<"\n";
            ans[i]=sum-maxi;
        }
        return ans;
        
    }
};