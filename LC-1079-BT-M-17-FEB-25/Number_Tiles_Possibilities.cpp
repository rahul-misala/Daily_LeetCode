//LeetCode Link : https://leetcode.com/problems/letter-tile-possibilities/description/

class Solution {
    public:
        void solve(int n, string& tiles, vector<bool>& used,unordered_set<string>& res, string curr) {
            res.insert(curr);
            for (int i = 0; i < n; i++) {
                if (used[i])
                    continue;
                curr.push_back(tiles[i]);
                used[i] = true;
                solve(n, tiles, used, res, curr);
                used[i] = false;
                curr.pop_back();
            }
        }
        int numTilePossibilities(string tiles) {
            int n = tiles.length();
            vector<bool> used(n, false);
            unordered_set<string> res;
            solve(n, tiles, used, res,"");
            return res.size() - 1;
        }
    };