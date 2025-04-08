class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int i = 0;
        int start = 0;
        int ans = 0;
        while(i<n){
            if(st.count(nums[i])){
                start += 3;
                i = start;
                ans++;
                st.clear();
            }else{
                st.insert(nums[i]);
                i++;
            }
        }
        return ans;
    }
};