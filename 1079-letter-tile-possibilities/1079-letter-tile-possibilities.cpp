class Solution {
public:
    int n;

    void solve(string &tiles, vector<bool>& used, unordered_set <string>& st, string& curr){
        st.insert(curr);
        for(int i=0;i<n;i++){
            if(used[i]){
                continue;
            }
            curr.push_back(tiles[i]);
            used[i]=true;
            solve(tiles, used, st, curr);
            used[i] = false;
            curr.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        vector <bool> used(n,false);
        unordered_set <string> st;
        string curr = "";
        solve(tiles, used, st, curr);
        return st.size()-1;
    }
};