class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        int curr = groups[0];
        vector<string> res;
        res.push_back(words[0]);
        for (int i = 1; i < groups.size(); i++) {
            if (groups[i] != curr) {
                curr = 1 - curr;
                res.push_back(words[i]);
            }
        }
        return res;
    }
};