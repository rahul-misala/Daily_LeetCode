//leetcode link : https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/


// T.C : O(n*no_of_digits)
// S.C : O(n)

class Solution {
    public:
        int digitSum(int n){
            int sum = 0;
            while(n>0){
                sum += n%10;
                n/=10;
            }
            return sum;
        }
        int maximumSum(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int,int> mp;
            // digitsum ---> number
            int maxi = -1;
            for(int i=0;i<n;i++){
                int numSum = digitSum(nums[i]);
                if(mp.count(numSum)){
                    maxi = max(maxi,nums[i]+mp[numSum]);
                    //if we have a number with same digit sum we add current number
                }
                mp[numSum] = max(mp[numSum],nums[i]);
                // store the maximum number with that digit sum (in case we find another number with same digit sum)
            }
            return maxi;
        }
    };