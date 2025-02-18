//leetcode link : https://leetcode.com/problems/construct-smallest-number-from-di-string/description/


class Solution {
    public:
        string smallestNumber(string pattern) {
            int n = pattern.size();
            stack<int> st;
            string res;
            int count = 1;
            for(int i=0;i<n;i++){
                st.push(count);
                if(pattern[i]=='I'){
                    while(!st.empty()){
                        char num = st.top();
                        res.push_back(num+'0');
                        st.pop();
                    }
                }
                count++;
            }
            st.push(count);
            while(!st.empty()){
                char num = st.top();
                res.push_back(num+'0');
                st.pop();
            }
            return res;
        }
    };