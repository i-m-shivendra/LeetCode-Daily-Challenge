class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();

        sort(answers.begin(), answers.end());
        int ans = 0;
        int count = 0;

        for(int i=0;i<n;i++){
            if(answers[i] == 0){
                ans += 1;
            }

            else if(i==0 || answers[i] != answers[i-1] || count==0){
                ans += answers[i] + 1;
                count = answers[i];
            }

            else {
                count--;
            }
        }
        return ans;
    }
};