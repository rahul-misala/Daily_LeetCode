//Leetcode link : https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/


class Solution {
    public:
        bool checkPunishment(int num,int curr,int target){
            if(num==0){
                return curr == target;
            }
            return checkPunishment(num/10,curr+num % 10,target)||
            checkPunishment(num/100,curr+num % 100,target)||
            checkPunishment(num/1000,curr+num % 1000,target)||
            checkPunishment(num/10000,curr+num % 10000,target);
        }
        int punishmentNumber(int n) {
            int res = 0;
            for(int i=1;i<=n;i++){
                int square = i*i;
                if(checkPunishment(square,0,i)){
                    res += square;
                }
            }
            return res;
        }
    };