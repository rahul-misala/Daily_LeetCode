//leetcode Link : https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/?envType=daily-question&envId=2025-02-21


class Solution {
    public:
        int count = 0;
        void solve(int n, string &curr, int k, string &res) {
            if (curr.length() == n) {
                count++;
                if (count == k) {
                    res = curr;
                }
                return;
            }
            for (char ch = 'a'; ch <= 'c'; ch++) {
                if (!curr.empty() && curr.back() == ch){
                    continue;
                }
                curr.push_back(ch);
                solve(n, curr, k, res);
                if (!res.empty()){
                    return;
                }
                curr.pop_back();
            }
        }
        string getHappyString(int n, int k) {
            string curr = "";
            string res = "";
            int count = 0;
            solve(n, curr, k, res);
            return res;
        }
    };