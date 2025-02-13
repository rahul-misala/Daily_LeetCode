//leetcode link :https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/?envType=daily-question&envId=2025-02-13


class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long, vector<long>, greater<long>> pq(begin(nums),end(nums));
            int count = 0;
            while(!pq.empty() && pq.top() < k) {
                long min = pq.top();
                pq.pop();
                long secMin = pq.top();
                pq.pop();
                pq.push(min*2 + secMin);
                count++;
            }
            return count;
        }
    };