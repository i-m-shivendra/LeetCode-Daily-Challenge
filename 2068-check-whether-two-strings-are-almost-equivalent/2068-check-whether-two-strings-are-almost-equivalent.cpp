class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int n = word1.size();
        
        unordered_map <char,int> mp;

        for(int i=0;i<n;i++)
        {
            mp[word1[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            mp[word2[i]]--;
        }

        for(auto it:mp)
        {
            if(abs(it.second) > 3)
            {
                return false;
            }
        }
        return true;
    }
};