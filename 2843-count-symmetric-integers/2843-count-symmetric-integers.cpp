class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low ; i <= high ; i++){
            string s = to_string(i);
            int n = s.length();
            if(n&1){
                continue;
            }
            int sum1 = 0;
            int sum2 = 0;
            for(int x=0;x<n/2;x++){
                sum1 += s[x]-48;
                sum2 += s[n-x-1]-48;
            }
            if(sum1==sum2){
                count++;
            }
        }
        return count;
    }
};