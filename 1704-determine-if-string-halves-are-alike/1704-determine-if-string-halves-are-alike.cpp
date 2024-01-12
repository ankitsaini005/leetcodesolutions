class Solution {
public:
    bool halvesAreAlike(string s) {
        
        unordered_map<char , int> iV;
        int left = 0 , right = 0;
        
        iV['A'] = iV['E'] = iV['I'] = iV['O'] = iV['U'] = 1;
        
        for(int i = 0 ; i < s.size() / 2 ; i++) {
            if(iV[s[i]] || ( s[i] - 97 >= 0 && iV[s[i] - 32])) {
                left++;
            }
        }
        
        for(int i = s.size() / 2 ; i < s.size() ; i++) {
            if(iV[s[i]] || (s[i] - 97 >= 0 && iV[s[i] - 32])) {
                right++;
            }
        }
        
        return (left == right);
    }
};