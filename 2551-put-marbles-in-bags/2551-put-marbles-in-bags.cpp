class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
      if(k == 1 || k == weights.size()) return 0;
         
        
          long long int ans = 0;
        
         long long int ans1 = 0;
          k--;
        
         vector<long long int>res1;
        
          for(long long int i = 0;i<weights.size()-1;i++){res1.push_back(weights[i]+weights[i+1]);}

        
             vector<long long int>res;
        
          for(long long int i = 0;i<weights.size()-1;i++){res.push_back(weights[i]+weights[i+1]);}
        
         sort(res1.begin() , res1.end() , greater<long long int>());
          sort(res.begin() , res.end());
        
        
            for(long long int i =0;i<k;i++) ans1 += res1[i];
        for(long long int i =0;i<k;i++) ans += res[i];
        
        
        return (ans1 - ans);
    }
};