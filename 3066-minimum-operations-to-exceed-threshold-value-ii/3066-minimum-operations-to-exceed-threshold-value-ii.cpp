class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //Heapify - O(log n)
        priority_queue <long, vector<long>, greater<long>> pq(begin(nums),end(nums));

        int count = 0;

        while(!pq.empty() && pq.top() < k)
        {
            long smallest = pq.top();   //minimum element ko nikal lo
            pq.pop();

            long secondSmallest = pq.top(); //second minimum element ko nikal lo
            pq.pop();

            pq.push(smallest*2 + secondSmallest);

            count++;
        }
        return count;;
    }
};