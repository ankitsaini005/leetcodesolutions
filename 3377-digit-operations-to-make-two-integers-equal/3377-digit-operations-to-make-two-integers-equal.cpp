class Solution {
public:
    
    int isPrime[10005]; 
    const int INF = 1e9; 
    
    void pre() {
        isPrime[0] = 1; 
        isPrime[1] = 1; 
        for (int i = 2; i < 10005; i++) {
            if (!isPrime[i]) {
                for (int j = 2 * i; j < 10005; j += i) {
                    isPrime[j] = 1; 
                }
            }
        }
    }

    // Finding all possible next numbers 
    vector<int> find(string s) {
        vector<int> v; 
        for (int i = 0; i < s.size(); i++) {
            string curr = s; 
            if (s[i] != '0') {
                curr[i]--; 
                v.push_back(stoi(curr)); 
                curr[i]++; 
            }
            if (s[i] != '9') {
                curr[i]++; 
                v.push_back(stoi(curr)); 
            }
        }
        return v; 
    }
    
    
    int minOperations(int n, int m) {
        pre(); 
        if (!isPrime[n]) {
            return -1; 
        }

        int x = to_string(n).size(); 
        
        vector<int> dp(10005, INF);
        set<vector<int>> q; 
        q.insert({n, n});
        dp[n] = n; 
         
        while (!q.empty()) {
            vector<int> curr = *q.begin(); 
            int node = curr[1]; 
            int w = curr[0]; 
            q.erase(q.begin()); 
            string s = to_string(node); 
            vector<int> children = find(s); 
            for (auto child: children) {
                if (isPrime[child]) {
                    if (dp[child] > dp[node] + child) {
                        dp[child] = dp[node] + child; 
                        q.insert({dp[child], child}); 
                    }
                }
            }
        }
        if (dp[m] == INF) {
            return -1; 
        }
        return dp[m]; 
          
        
    }
};