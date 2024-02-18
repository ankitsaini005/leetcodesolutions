#define ll long long int
struct Node
{
    Node *arr[26];
    ll cnt;
    public:
    bool find(char c)
    {
        return (arr[c-'a']!=NULL);
    }
    void add(char c,Node *temp1)
    {
        arr[c-'a']=temp1;
        return ;
    }
    Node* next(char c)
    {
        return arr[c-'a'];
    }
    void inc()
    {
        cnt++;
    }
    ll get()
    {
        return cnt;
    }
};
class Trie
{
  Node *root;
  public:
  Trie()
  {
      root=new Node();
  }
  void insert(string &temp,vector<ll>&z)
  {
    Node *root1=root;
    for(int i=0;i<temp.length();i++)
    {
        if(!root1->find(temp[i]))
        {
            //cout<<i<<" ";
            root1->add(temp[i],new Node());
        }
        root1=root1->next(temp[i]);
        if(i+1==z[temp.length()-i-1])
        {
          //  cout<<temp<<" "<<z[temp.length()-i-1]<<"\n";
            root1->inc();
        }
    }
  }
  ll find(string &temp)
  {
      Node *root1=root;
      int i=0;
      for(i=0;i<temp.length();i++)
      {
          //cout<<temp[i]<<" ";
          if(root1->find(temp[i]))
          {
            //  cout<<"2"<<"\n";
              root1=root1->next(temp[i]);
          }
          else
              break;
      }
     // cout<<i<<" "<<temp<<"\n";
      if(i==temp.length())
          return root1->get();
      else
          return 0;
  }
};
vector<ll> z_algo(string &temp)
{
    ll n=temp.length();
        vector<ll>ans(n,0);

    ll l=0;
    ll r=0;
    for(int i=1;i<n;i++)
    {
        if((i<r))
            ans[i]=min(ans[i-l],r-i);
        while((i+ans[i]<n)&&(temp[i+ans[i]]==temp[ans[i]]))
        {
            ans[i]++;
        }
        if(r<(i+ans[i]))
        {
            l=i;
            r=i+ans[i];
        }
    }
    
    return ans;
    
}
class Solution {
public:
    
    long long countPrefixSuffixPairs(vector<string>& words) 
    {
     ll ans=0;
     ll n=words.size();
        Trie t;
        map<string,int>mp;
     for(int i=n-1;i>=0;i--)
     {
        string temp=words[i];
      //  Trie t;
         ans+=mp[temp];
        ans+=t.find(temp);
        vector<ll>z=z_algo(temp);
        t.insert(temp,z);
         mp[temp]++;
     }
        return ans;
    }
};