class Solution {
public:
    int check(string &word,vector<int>&mp1,int mid)
    {
        int n=word.length();
        int st=0;
        int en=0;
        // string temp;
        // for(int i=st;i<=en;i++)
        // {
        //     temp+=word[i];
        // }
         int len=0;
        // if((en<n)&&mp1[en].size()>0)
        // {
        //     int len=*(mp1[en].begin());
        //     if(len<=(en-st+1))
        //     st=en-(len-1)+1;
        // }
        // if(en<n)
        // len=max(len,en-st+1);
        //cout<<st<<" "<<en<<"\n";
        while((en<n)&&(st<n)&&(st<=en))
        {
           
               // en++;
            int f=0;
               if((en<n)&&mp1[en]!=0)
               {
                 int len1=mp1[en];
                   if(len1<=(en-st+1))
                 st=en-(len1-1)+1;
                 if(en<st)
                 {
                     st=en+1;
                     en=st;
                     continue;
                 }
               }
              
            
          // 
                //if(en<n)
                len=max(len,en-st+1);
            
                en++;
            
        }
        if(len>=mid)
            return 1;
        else
            return 0;
    }
    int longestValidSubstring(string word, vector<string>& forbidden) 
    {
        unordered_map<string,int>mp;
        vector<int>mp1;
        for(int i=0;i<word.length();i++)
        {
            mp1.push_back(0);
        }
        int n=word.length();
        int m=forbidden.size();
        
        // for(int i=0;i<forbidden.size();i++)
        // {
        //     reverse(forbidden[i].begin(),forbidden[i].end());
        // }
        for(int i=0;i<m;i++)
        {
            mp[forbidden[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            string temp;
            temp+=word[i];
            if((mp.find(temp)!=mp.end())&&mp[temp]>0)
            {
                mp1[i]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
          string temp;
          for(int j=i;j<=min(n-1,(i+10-1));j++)
          {
              temp+=word[j];
            //  cout<<temp<<" ";
              if((mp.find(temp)!=mp.end())&&mp[temp]>0)
              {
                  mp1[j]=j-i+1;
              }
          }
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<i<<" "<<mp1[i]<<"\n";
        // }
        int l=0;
        int r=word.length();
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(word,mp1,mid))
            {
                ans=max(ans,mid);
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};