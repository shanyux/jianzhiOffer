class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> res;
        res.push_back(1);
        for(int i =1; i < len; i++){
            res.push_back(res[i-1]*A[i-1]);
        }
        int tmp = 1;
        for(int i = len-2; i>=0; i--){
            tmp = tmp * A[i+1];
            res[i] = tmp * res[i];
        }
        return res;
    
    }
};