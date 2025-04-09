class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(),nums.end());
        int count = 0;
        // if(n==1 and k==nums[0]){
        //     return 0;
        // }
        int x = 0;
        for(auto no:st){
            if(no>k)count++;
            else if(no<k)x++;
        }
        if(x==0)
        return count;
        else{
            return -1;
        }
    }
};