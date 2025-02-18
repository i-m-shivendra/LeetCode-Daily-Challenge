class Solution {
public:
    bool matchesPattern(string& result, string& pattern){
        for(int i=0;i<pattern.size();i++){
            if(pattern[i]=='I' && result[i]>result[i+1]
            || pattern[i]=='D' && result[i]<result[i+1]){
                return false;
            }
        }
        return true;
    }
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string result = "";

        for(int i=1;i<=n+1;i++){
            result.push_back(i+'0');
        }

        while(!matchesPattern(result,pattern)){
            next_permutation(begin(result),end(result));
        }

        return result;
    }
};