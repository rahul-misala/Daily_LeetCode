//leetcode link : https://leetcode.com/problems/apply-operations-to-an-array/description

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
            int p2 = 0;
            for(int p1 = 0; p1 < n; p1++) {
                if(p1+1 < n && nums[p1] == nums[p1+1] && nums[p1] != 0) {
                    nums[p1] *= 2;
                    nums[p1+1] = 0;
                }
                if(nums[p1] != 0) {
                    if(p1 != p2) {
                        swap(nums[p1], nums[p2]);
                    }
                    p2++;
                }
            }
            return nums;
        }
    };