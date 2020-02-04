class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() == 0) return 0;
        sort(A.begin(),A.end());
        int ans=0;
        for(int i=0; i < A.size()-1; i++) {
            if(A[i] < A[i+1]) continue;
            ans+=A[i]+1-A[i+1];
            A[i+1]=A[i]+1;
        }
        return ans;
    }
};