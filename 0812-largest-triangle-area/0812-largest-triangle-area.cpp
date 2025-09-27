class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = INT_MIN;
        int n = points.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int x1 = points[i][0];
                    int y1 = points[i][1];

                    int x2 = points[j][0];
                    int y2 = points[j][1];

                    int x3 = points[k][0];
                    int y3 = points[k][1];

                    double tempArea = abs((x1*(y2-y3) +
                    x2*(y3-y1) + x3*(y1-y2)));

                    maxArea = max(maxArea, 0.5*tempArea);
                }
            }
        } 
        return maxArea;
    }
};