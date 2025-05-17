class Solution {
public:
    bool check(string&s,string&t)
    {
        int n=s.length();
        if(n!=t.length()) return false;;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i]) cnt++;
            if(cnt>1) return false;
        }
        return true;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
            int n=words.size();
            vector<int> dp(n,1),prev(n);
            int maxi=0,last=-1;
            for(int i=0;i<n;i++)
            {
                prev[i]=i;
                for(int j=0;j<i;j++)
                {
                    if(groups[i]!=groups[j] && check(words[i],words[j]) && dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                }
                if(dp[i]>maxi)
                {
                    last=i;
                    maxi=dp[i];
                }
            }
            vector<string> ans;
            ans.push_back(words[last]);
            while(prev[last]!=last)
            {
                last=prev[last];
                ans.push_back(words[last]);
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};