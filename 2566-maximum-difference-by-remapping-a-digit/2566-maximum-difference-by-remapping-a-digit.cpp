class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        int n = str.size();

        string maxi = "";
        string mini = "";

        char ch;

        for(int i=0;i<n;i++){
            if(str[i] != '9'){
                ch = str[i];
            }
        }

        for(int i=0;i<n;i++){
            if(ch == str[i]){
                maxi += '9';
            }
            else{
                maxi += str[i];
            }
        }

        for(int i=0;i<n;i++){
            if(str[0] == str[i]){
                mini += '0';
            }
            else {
                mini += str[i];
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};