class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> result;

        int i =0;
        int j = 0;

        while(i<m && j<n){

            if(nums1[i][0] < nums2[j][0]){
                result.push_back(nums1[i]);
                i++;
            }

            else if(nums2[j][0] < nums1[i][0]){
                result.push_back(nums2[j]);
                j++;
            }

            else{
                result.push_back({nums1[i][0], nums1[i][1]+nums2[j][1]});
                i++;
                j++;
            }
        }

        while(i<m){
            result.push_back(nums1[i]);
            i++;
        }

        while(j<n){
            result.push_back(nums2[j]);
            j++;
        }
        return result;
    }
};