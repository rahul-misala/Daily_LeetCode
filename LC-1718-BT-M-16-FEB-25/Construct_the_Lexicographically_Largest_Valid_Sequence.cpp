//leetcode link : https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/

class Solution {
    public:
        bool solve(int i,int n,vector<int>& res,vector<bool>& used){
            if(i>=res.size()){
                return true;
            }
            if(res[i]!=-1){
                return solve(i+1,n,res,used);
            }
    
            for(int x=n;x>=1;x--){
                if(!used[x]){ 
                    used[x] = true;
                    res[i] = x;
                    if(x==1){
                        if(solve(i+1,n,res,used)){
                            return true;
                        }
                    }else{
                        int j=res[i]+i;
                        if(j<res.size()&& res[j]==-1){
                            res[j]=x;
                            if(solve(i+1,n,res,used)){
                                return true;
                            }
                            res[j]=-1;
                        }
                    }
                    used[x] = false;
                    res[i] = -1;
                
                }
    
            }
            return false;
        }
        vector<int> constructDistancedSequence(int n) {
            vector<int> res(2*n-1,-1);
            vector<bool> used(n+1,false);
            solve(0,n,res,used);
            return res;
        }
    };