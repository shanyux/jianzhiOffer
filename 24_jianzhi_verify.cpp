class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        bool flag = false;
        if(sequence.empty())
            return flag;
        int len = sequence.size();
        flag = VerifySquenceOfBST(sequence, 0, len-1);
        return flag;
    }
    bool VerifySquenceOfBST(vector<int> sequence, int left, int right) {
        if(left >= right)
            return true;
        int i = left;
        for(; i < right; i++){
            if(sequence[i] > sequence[right]){
                break;
            }
        }
        bool leftflag = true;
        if(i > 0)
        left = VerifySquenceOfBST(sequence, left, i-1);
        int j = i;
        for(; j<right; j++)
        {
            if(sequence[right] > sequence[j])
                return false;
        }
        bool rightflag = true;
        if(right > i)
            right = VerifySquenceOfBST(sequence, i, right-1);
        return leftflag && rightflag;
    }
};