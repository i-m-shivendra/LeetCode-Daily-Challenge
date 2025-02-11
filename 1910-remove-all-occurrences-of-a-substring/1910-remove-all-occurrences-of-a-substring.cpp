class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int n = part.size();

        for(char &ch:s)
        {
            ans.push_back(ch);

            if(ans.size() >= n && ans.substr(ans.size() - n) == part)
            {
                ans.erase(ans.size() - n);
            }
        }
        return ans;
    }
};