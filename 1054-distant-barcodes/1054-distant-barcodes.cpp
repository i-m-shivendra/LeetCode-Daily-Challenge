class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        vector<int> ans;
        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
            mp[barcodes[i]]++;
        }

        priority_queue<pair<int, int>> pq;
        
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        
        pair<int, int> pre = {0, 0};

        while(!pq.empty()){
            int first = pq.top().first;
            int second = pq.top().second;
            pq.pop();

            ans.push_back(second);

            first = first-1;
            
            if(pre.first > 0){
                pq.push(pre);
            }

            pre.first = first;
            pre.second = second;
        }

        return ans;
    }
};