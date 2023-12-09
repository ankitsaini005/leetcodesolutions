class Solution {
public:
    void solve(int u,int p,vector<vector<pair<int,int>>>&adj,int n,int &sum,int vis[])
    {
        vis[u]=1;
        for(auto it=adj[u].begin();it!=adj[u].end();it++)
        {
            int v=(*it).first;
            if(v==p||vis[v])
                continue;
            int v1=(*it).second;
            sum+=v1;
            solve(v,u,adj,n,sum,vis);
        }
    }
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) 
    {
        int maxd=maxDistance;
        int ans=0;
        int dis[11][11];
        for(int i=0;i<11;i++)
        {
            for(int j=0;j<11;j++)
            {
                dis[i][j]=1001;
            }
        }
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            if(w<dis[u][v])
            {
                //cout<<w<<"\n";
                dis[u][v]=w;
            }
        }
        for(int i=0;i<=(1<<n)-1;i++)
        {
            int bitr=i;
            set<int>node;
            int idx=0;
            while(bitr>0)
            {
                if(bitr&(1))
                {
                 node.insert(idx);   
                // cout<<i<<" "<<idx<<"\n";
                }
                else
                {
                   // cout<<idx<<" ";
                }
                bitr=bitr/2;
                idx++;
            }
            vector<vector<pair<int,int>>>adj;
            adj.resize(n+1);
           
           // int st=-1;
            for(int k=0;k<roads.size();k++)
            {
                int u=roads[k][0];
                int v=roads[k][1];
                int w=roads[k][2];
                 //cout<<i<<" "<<w<<"\n";
                if(node.find(u)!=node.end()&&node.find(v)!=node.end())
                {
                    //st=u;
                    adj[u].push_back(make_pair(v,w));
                    adj[v].push_back(make_pair(u,w));
                  // cout<<i<<" "<<w<<"\n";
                  
                }
                
            }
            
          //  cout<<i<<"\n";
            int vis[11];
            int dis1[11];
            
          
            int flag=1;
            for(int k=0;k<n;k++)
            {
                
                if((i&(1<<k))==0)
                    continue;
             
              for(int k1=0;k1<11;k1++)
            {
                dis1[k1]=1e9;
              vis[k1]=0;
            }
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push(make_pair(0,k));
            dis1[k]=0;
            
            

            while(!pq.empty())
            {
                pair<int,int>pr=pq.top();
                pq.pop();
                if(vis[pr.second])
                    continue;
                vis[pr.second]=1;
                
                for(auto it:adj[pr.second])
                {
                    if(pr.first+it.second<dis1[it.first])
                    {
                        
                        dis1[it.first]=pr.first+it.second;
                        pq.push(make_pair(dis1[it.first],it.first));
                    }
                }
            }
            for(int k1=0;k1<n;k1++)
            {
                    //cout<<dis1[k]<<" ";   
                    if(((1<<k1)&i)&&dis1[k1]>maxd)
                    {
                        flag=0;
                        break;
                    }
                
            }
            if(flag==0)
                break;
            }
           // cout<<i<<"\n";
           
           
            if(flag)
            {
                ans++;
                cout<<i<<"\n";
                //cout<<"\n";
            }
        }
        return ans;
    }
};