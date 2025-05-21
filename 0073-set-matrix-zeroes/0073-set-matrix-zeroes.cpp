class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        vector<vector<int>>a;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[i].size();j++){
                if(m[i][j]==0){
                    a.push_back({i,j});
                }
            }
        }
        for(auto k:a){
            for(int t=0;t<m[k[0]].size();t++){
                m[k[0]][t]=0;
            }
            for(int o=0;o<m.size();o++){
                m[o][k[1]]=0;
            }
        }

    }
};