int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) 
    {
      int n=moveTime.size();
      int m=moveTime[0].size();
      priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,greater<pair<pair<int,int>,pair<int,int>>>>pq;
      pq.push(make_pair(make_pair(0,1),make_pair(0,0)));
      int dis[n+1][m+1];
        int vis[n+1][m+1];
      for(int i=0;i<=n;i++)
      {
          for(int j=0;j<=m;j++)
          {
              dis[i][j]=INT_MAX;
              vis[i][j]=0;
          }
      }
        dis[0][0]=0;
      while(!pq.empty())
      {
         pair<pair<int,int>,pair<int,int>>pr=pq.top();
         int tm=pr.first.first;
         int flag=pr.first.second;
         int x=pr.second.first;
         int y=pr.second.second;
          vis[x][y]=1;
          pq.pop();
         for(int i=0;i<4;i++)
         {
             int nxtx=x+dx[i];
             int nxty=y+dy[i];
             if(nxtx>=0&&nxtx<n&&nxty>=0&&nxty<m&&vis[nxtx][nxty]==0)
             {
                 if(flag)
                 {
                    int waittm=(tm>=moveTime[nxtx][nxty])?0:(moveTime[nxtx][nxty]-tm);
                    if(tm+waittm+1<dis[nxtx][nxty])
                    {
                        dis[nxtx][nxty]=tm+waittm+1;
                        pq.push(make_pair(make_pair(dis[nxtx][nxty],flag^1),make_pair(nxtx,nxty)));
                    }
                 }
                 else
                 {
                   int waittm=(tm>=moveTime[nxtx][nxty])?0:(moveTime[nxtx][nxty]-tm);
                    if(tm+waittm+2<dis[nxtx][nxty])
                    {
                        dis[nxtx][nxty]=tm+waittm+2;
                        pq.push(make_pair(make_pair(dis[nxtx][nxty],flag^1),make_pair(nxtx,nxty)));
                    }  
                 }
                 
             }
         }
      }
        return dis[n-1][m-1];
    }
};