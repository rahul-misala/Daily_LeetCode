// Cpp Solution
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.length();
        int pos = s.find(part);
        while(pos<s.length()){
            if(s.length()>=m){
                s.erase(pos,m);
            }
            pos = s.find(part);
        }
        return s;
    }
};