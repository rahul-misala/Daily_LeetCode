//2570. Merge Two 2D Arrays by Summing Values
//Leetcode: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/

class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int n = nums1.size();
            int m = nums2.size();
            vector<vector<int>> res;
            int p1 = 0;
            int p2 = 0;
            while(p1<n && p2<m){
                if(nums1[p1][0]<nums2[p2][0]){
                    res.push_back({nums1[p1][0],nums1[p1][1]});
                    p1++;
                }else if(nums1[p1][0]>nums2[p2][0]){
                    res.push_back({nums2[p2][0],nums2[p2][1]});
                    p2++;
                }else{
                    res.push_back({nums2[p2][0],nums1[p1][1] + nums2[p2][1]});
                    p2++;
                    p1++;
                }
            }
            while(p1<n){
                res.push_back({nums1[p1][0],nums1[p1][1]});
                p1++;
            }
            while(p2<m){
                res.push_back({nums2[p2][0],nums2[p2][1]});
                p2++;
            }
            return res;
        }
    };