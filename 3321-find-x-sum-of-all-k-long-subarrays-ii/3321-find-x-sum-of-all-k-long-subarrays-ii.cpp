#define ll long long int
class Solution {
public:
    set<pair<ll,ll>>xfreq,ele;
    ll sum=0;
    vector<ll>ans;
    map<ll,ll>mp;
    void add_remove(int num,int add)
    {
        if(xfreq.count({mp[num],num}))
        {
            xfreq.erase({mp[num],num});
            sum=sum-mp[num]*num;
            mp[num]+=add;
            xfreq.insert({mp[num],num});
            sum+=mp[num]*num;
        }
        else if(ele.count({mp[num],num}))
        {
           // cout<<num<<"hi";
            ele.erase({mp[num],num});
            mp[num]+=add;
           // cout<<num<<" "<<mp[num]<<"\n";
            ele.insert({mp[num],num});
        }
    }
    void maintain(int x,int i)
    {
      //  cout<<sum<<"\n";
        while(xfreq.size()<x&&(!ele.empty()))
        {
           // cout<<sum<<" "<<i<<"\n";
            auto it=ele.rbegin();
            //cout<<"maintain"<<" "<<(*it).first<<" "<<(*it).second<<"\n";
            xfreq.insert({(*it).first,(*it).second});
            
            sum+=(*it).first*(*it).second;
            ele.erase(*it);
             // cout<<sum<<" "<<i<<" "<<(*it).second<<" "<<ele.size()<<"\n";
        }
        if(ele.empty())
          return;
        while(1)
        {
         auto it=*(ele.rbegin());
         auto in=*(xfreq.begin());
         if((it)>(in))
         {
             sum=sum-(in).first*(in).second;
             sum+=(it).first*(it).second;
             // xfreq.erase(in)
            // cout<<(*in).first<<" "<<(*in).second<<"\n";
             ele.insert((in));
              xfreq.erase(in);
             xfreq.insert(it);
             ele.erase(it);
         }
            else
                break;
                             
        }
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            ele.insert(make_pair(mp[nums[i]],nums[i]));
        }
        for(int i=0;i<n;i++)
        {
            add_remove(nums[i],1);
            if(i>=k)
                add_remove(nums[i-k],-1);
            if(i>=k-1)
            {
                maintain(x,i);
                ans.push_back(sum);
            }
        }
        return ans;
    }
};