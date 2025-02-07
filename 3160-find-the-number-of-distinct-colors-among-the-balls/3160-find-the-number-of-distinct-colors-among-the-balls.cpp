class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);

        unordered_map<int, int> colormp; //color -> count
        
        vector<int> ballArr(limit+1, -1); //ball[i] = x; ith ball has x color

        for(int i = 0; i < n; i++) {
            int ball  = queries[i][0];
            int color = queries[i][1];

            if(ballArr[ball] != -1) { //already colored ball
                int prevColor = ballArr[ball];
                colormp[prevColor]--;

                if(colormp[prevColor] == 0) {
                    colormp.erase(prevColor);
                }
            }

            ballArr[ball] = color;
            colormp[color]++;

            result[i] = colormp.size();
        }

        return result;


    }
};