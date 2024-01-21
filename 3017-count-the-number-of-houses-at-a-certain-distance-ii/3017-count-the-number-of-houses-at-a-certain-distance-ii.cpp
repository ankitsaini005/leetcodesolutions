#define ll long long int
class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y)
    {
        vector<ll>ans;
     
        int arr[n+1];
        for(int i=0;i<=n;i++)
        {
            arr[i]=0;
        }
        if(x>y)
            swap(x,y);
       
        for(int i=1;i<=n;i++)
        {
          arr[0]+=2;
          arr[min((i-1),abs(i-y)+x)]--;// reaching 1; 
          arr[min((n-i),abs(i-x)+1+n-y)]--;//reaching n;
          arr[min(abs(i-y),abs(i-x)+1)]++;// splitting y;
          arr[min(abs(i-x),abs(i-y)+1)]++;// splitting x;
          ll r=max(x-i,0)+max(i-y,0);
          arr[r+(y-x)/2]--;
          arr[r+(y-x+1)/2]--;
        }
        for(int i=1;i<n;i++)
        {
            arr[i]+=arr[i-1];
        }
        for(int i=0;i<n;i++)
        {
          ans.push_back(arr[i]);
        }
        return ans;
    }
};