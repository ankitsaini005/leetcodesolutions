#define modulo 1000000007
#define ll long long int
class Solution {
public:
    vector<vector<ll>> multiply(vector<vector<ll>>&arr1,vector<vector<ll>>&arr2)
    {
        vector<vector<ll>>rt_res(26,vector<ll>(26,0));
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                for(int k=0;k<26;k++)
                {
                    rt_res[i][j]=rt_res[i][j]%modulo+((arr1[i][k])%modulo*(arr2[k][j])%modulo)%modulo;
                }
            }
        }
        return rt_res;
    }
    vector<vector<ll>> calculate_expo(vector<vector<ll>>&arr,int k)
    {
        vector<vector<ll>>res(26,vector<ll>(26,0));
        for(int i=0;i<26;i++)
        {
            res[i][i]=1;
        }
        while(k>0)
        {
            if(k&1)
            {
                res=multiply(res,arr);
            }
            arr=multiply(arr,arr);
            k=k/2;
        }
        return res;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums)
    {
      int n=s.length();
      int sz=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]-'a']++;
        }
      vector<vector<ll>>arr(26,vector<ll>(26,0));
      for(int i=0;i<sz;i++)
      {
         for(int j=1;j<=nums[i];j++)
         {
             arr[(i+j)%26][i]++;
         }
      }
      // so we have calculated it for one traversal now using matrix exponentiation we need to know its pw
      //vector<vector<int>>f_res(26,vector<int>(26,0));
      vector<vector<ll>> f_res=calculate_expo(arr,t);
        vector<ll> ans(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans[i] = (ans[i] + f_res[i][j] * mp[j]) % modulo;
            }
        }
      int tot_ans=0;
      for(int i=0;i<26;i++)
      {
          tot_ans=(tot_ans%modulo+ans[i]%modulo)%modulo;
      }
        return tot_ans;
    }
};