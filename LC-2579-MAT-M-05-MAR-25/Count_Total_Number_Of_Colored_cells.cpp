//Leetcode Link : https://leetcode.com/problems/count-total-number-of-colored-cells/?envType=daily-question&envId=2025-03-05

//Pattern : n^2 + (n-1)^2

class Solution {
    public:
        long long coloredCells(int n) {
            return pow(n-1,2)+pow(n,2);
        }
};