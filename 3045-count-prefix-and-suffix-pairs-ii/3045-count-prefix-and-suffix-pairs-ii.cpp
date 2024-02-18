#define ll long long int
class Node{
    private:
        bool isend;
        Node* links[26];
        ll count=0;
    public:
        bool containsKey(char ch)
        {
            return links[ch-'a']!=NULL;
        }
        void put(char ch,Node* node)
        {
            links[ch-'a']=node;
        }
        Node* get(char ch)
        {
            return links[ch-'a'];
        }
        bool isending()
        {
            return isend;
        }
        void end()
        {
            isend=true;
        }
        void pluscount()
        {
            count++;
        }
        ll getcount()
        {
            return count;
        }
    
};

class Trie{
    private:
        Node* root;
    public:
        Trie()
        {
            root=new Node();
        }
        void insert(string &str,vector<int>&val)
        {
            Node* node=root;
            for(int i=0;i<str.size();i++)
            {
                char ch=str[i];
                if(!node->containsKey(ch))
                {
                    node->put(ch,new Node());
                }
                node=node->get(ch);
                if(val[str.size()-i-1]==i+1)
                {
                    node->pluscount();
                }
                
            }
            node->end();
        }
        bool match(string &str)
        {
            Node* node=root;
            for(char ch:str)
            {
                if(node->containsKey(ch))
                {
                    node=node->get(ch);
                }
                else{
                    return false;
                }
            }
            return node->isending();
        }
        ll solve(string &str)
        {
            int i=0;
            Node* node=root;
            for(i=0;i<str.size();i++)
            {
                char ch=str[i];
                if(node->containsKey(ch))
                {
                    node=node->get(ch);
                }
                else{
                    break;
                }
            }
            if(i==str.size())
            {
                return node->getcount();
            }
            return 0;
        }
    
};


class Solution {
public:
    
    
    vector<int>  calculateZ(string &input) {
        vector<int>Z(input.size(),0);
        int left = 0;
        int right = 0;
        for(int k = 1; k < input.size(); k++) {
            if(k > right) {
                left = right = k;
                while(right < input.size() && input[right] == input[right - left]) {
                    right++;
                }
                Z[k] = right - left;
                right--;
            } else {
                int k1 = k - left;
                if(Z[k1] < right - k + 1) {
                    Z[k] = Z[k1];
                } else { 
                    left = k;
                    while(right < input.size() && input[right] == input[right - left]) {
                        right++;
                    }
                    Z[k] = right - left;
                    right--;
                }
            }
        }
        return Z;
    }
    
    long long countPrefixSuffixPairs(vector<string>& words) {
        
        Trie trie;
        int n=words.size();
        ll ans=0;
        map<string,int>mp;
        for(int i=n-1;i>=0;i--)
        {
            ans+=mp[words[i]];
            ans+=trie.solve(words[i]);
            vector<int>val=calculateZ(words[i]);
            trie.insert(words[i],val);
            mp[words[i]]++;
        }
        return ans;
        
    }
};