
//Leetcode Link : https://leetcode.com/problems/partition-array-according-to-given-pivot/?envType=daily-question&envId=2025-03-04

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
           int n = nums.size();
            vector<int> lesser;
            vector<int> equal;
            vector<int> greater;
            for(int i = 0; i < n; i++) {
                if(nums[i] < pivot) {
                    lesser.push_back(nums[i]);
                } else if(nums[i] == pivot) {
                    equal.push_back(nums[i]);
                } else {
                    greater.push_back(nums[i]);
                }
            }
            for(int &num : equal) {
                lesser.push_back(num);
            }
            for(int &num : greater) {
                lesser.push_back(num);
            }
            return lesser; 
        }
    };