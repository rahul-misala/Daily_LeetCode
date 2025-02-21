//Leetcode Link : https://leetcode.com/problems/find-unique-binary-string/?envType=daily-question&envId=2025-02-21


class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            int n = nums.size();
            string res;
            for(int i=0;i<n;i++){
                char ch = nums[i][i];
                if(ch=='0'){
                    res.push_back('1');
                }else{
                    res.push_back('0');
                }
            }
            return res;
        }
    };