class Solution {
public:
    map<string,double>res;
    double ans=1.0;
    void bfs1(string init,map<string,vector<pair<string,double>>>&adj)
    {
        map<string,int>vis;
        queue<pair<string,double>>q;
        q.push(make_pair(init,1.0));
        while(!q.empty())
        {
           pair<string,double>pr=q.front();
           q.pop();
           vis[pr.first]=1;
           res[pr.first]=max(res[pr.first],pr.second);
           for(auto it:adj[pr.first])
           {
               string s=it.first;
               double cnt1=it.second;
               if(vis[s]==0)
               {
                   q.push(make_pair(s,cnt1*pr.second));
               }
           }
        }
    }
    void bfs2(string s,double no,string init,map<string,vector<pair<string,double>>>&adj)
    {
        map<string,int>vis;
        queue<pair<string,double>>q;
        q.push(make_pair(s,no));
        while(!q.empty())
        {
            pair<string,double>pr=q.front();
            q.pop();
            vis[pr.first]=1;
            if(pr.first==init)
            {
                ans=max(ans,pr.second);
               // continue;
            }
            for(auto it:adj[pr.first])
            {
                string s=it.first;
                double cnt1=it.second;
                if(vis[s]==0)
                {
                    //cout<<cnt1<<" "<<pr.second<<"\n";
                    q.push(make_pair(s,cnt1*pr.second));
                }
            }
        }
    }
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2)
    {
       map<string,vector<pair<string,double>>>adj,adj1;
       int n=pairs1.size();
       int m=pairs2.size();
       
        //cout<<n<<" "<<m<<"\n";
       for(int i=0;i<n;i++)
       {
           string f=pairs1[i][0];
           string s=pairs1[i][1];
           adj[f].push_back(make_pair(s,rates1[i]));
           adj[s].push_back(make_pair(f,1/(rates1[i]*1.0)));
       }
       for(int i=0;i<m;i++)
       {
           string f=pairs2[i][0];
           string s=pairs2[i][1];
           adj1[f].push_back(make_pair(s,rates2[i]));
           adj1[s].push_back(make_pair(f,1/(rates2[i]*1.0)));
       }
       bfs1(initialCurrency,adj);
       for(auto it:res)
       {
          string s=it.first;
          double no=it.second;
          // cout<<no<<" "<<s<<" "<<"hi"<<"\n";
          bfs2(s,no,initialCurrency,adj1); 
       }
       
       return ans;
    }
};