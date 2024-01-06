#define ll long long int
class Solution {
public:
    ll dp[20][2][2];
    ll solve(ll idx,string &s,ll lim,ll tight,ll leadingz,ll n,string &s1)
    {
       // cout<<n<<" "<<s1.length()<<" "<<n-s1.length()<<"\n";
        //return 0;
        if(s1.length()>n)
            return 0;
        if(n==s1.length())
        {
           // cout<<"\n";
            if(s1>s)
                return 0;
            else
                return 1;
        }
        if(idx>=n-s1.length())
        {
            //cout<<"in"<<"\n";
           // return 0;
           // cout<<idx<<" "<<"\n";
            if(leadingz)
                return 1;
            if(tight)
            {
                string temp=s;
                ll idx1=0;
               // cout<<"in"<<"\n";
                for(int i=0;i<idx;i++)
                {
                    if(lim<(ll)(temp[i]-'0'))
                    {
                        temp[i]=(char)('0'+lim);
                    }
                }
                for(int i=idx;i<s.length();i++)
                {
                    temp[i]=s1[idx1];
                    idx1++;
                }
               // cout<<temp<<"\n";
                if(temp>s)
                    return 0;
                else
                {
                  //  cout<<"1"<<"\n";
                    return 1;
                }
            }
            else
            {
                return 1;
            }
        }
        if(dp[idx][tight][leadingz]!=-1)
            return dp[idx][tight][leadingz];
        ll limit=(tight)?(ll)(s[idx]-'0'):lim;
        ll limit1=limit;
        limit=min(limit,lim);
        ll ans=0;
        if(leadingz)
        {
           for(int i=0;i<=limit;i++)
           {
              if(i==0)
              {
                 // cout<<idx<<" "<<i<<" "<<limit<<" "<<tight<<"\n";
                 ans+=solve(idx+1,s,lim,0,1,n,s1);
              }
              else
              {
                 // cout<<idx<<" "<<i<<" "<<limit<<" "<<tight<<"\n";
                 ans+=solve(idx+1,s,lim,((tight)&(i==limit1)),0,n,s1);
              }
           }
        }
        else
        {
            for(int i=0;i<=limit;i++)
            {
                //cout<<idx<<" "<<i<<" "<<limit<<" "<<tight<<"\n";
                ans+=solve(idx+1,s,lim,((tight)&(i==limit1)),0,n,s1);
            }
        }
       dp[idx][tight][leadingz]=ans;
        return ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) 
    {
        memset(dp,-1,sizeof dp);
        string temp=to_string(start-1);
        string temp1=to_string(finish);
        ll len=temp.length();
        ll len1=temp1.length();
        ll len2=s.length();
        ll val=solve(0,temp,limit,1,1,len,s);
        //cout<<val<<"\n";
        memset(dp,-1,sizeof dp);
        ll val1=solve(0,temp1,limit,1,1,len1,s);
        //cout<<val1<<"\n";
        return val1-val;
    }
};