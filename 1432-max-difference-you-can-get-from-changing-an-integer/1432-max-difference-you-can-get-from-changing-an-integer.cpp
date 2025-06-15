class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        string maxi = s;
        for(char c : s){
            if(c != '9'){
                for(char &ch : maxi){
                    if(c == ch){
                        ch = '9';
                    }
                    break;
                }
            }
        }

        string mini = s;
        if(s[0] != '1'){
            char c = s[0];
            for(char &ch : mini){
                if(ch == c){
                    ch = '1';
                }
            }
        }

        else{
            for(int i=1;i<s.size();i++){
                if(s[i] != '0' && s[i] != '1'){
                    char c = s[i];
                    for(char ch : mini){
                        if(ch == c){
                            ch = '0';
                        }
                        break;
                    }
                }
            }
        }

        int x = stoi(maxi);
        int y = stoi(mini);

        return x-y;
    }
};