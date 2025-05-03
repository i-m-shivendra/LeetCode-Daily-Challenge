class Solution {
public:
    int rotations(vector<int>& tops, vector<int>& bottoms, int target){
        int ans = 0;
        for(int i=0;i<tops.size();i++){

            if(tops[i] == target){
                continue;
            }
            
            if(bottoms[i] == target){
                ans++;
            }

            else{
                return INT_MAX;
            }
        }
        return ans;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        for(int i=1;i<=6;i++){
            ans = min(ans, rotations(tops,bottoms, i));
            ans = min(ans, rotations(bottoms, tops, i));

        }

        return ans == INT_MAX ? -1 : ans;
    }
};