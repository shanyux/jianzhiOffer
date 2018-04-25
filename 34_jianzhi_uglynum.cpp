class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7)
            return index;
        else{
            vector<int> res(index);
            res[0] = 1;
            int r2 = 0, r3 = 0, r5 = 0;
            for(int i = 1; i < index; i++){
                res[i]= min(res[r2]*2, min(res[r3]*3, res[r5]*5));
                if(res[r2]*2==res[i])
                    r2++;
                if(res[r3]*3==res[i])
                    r3++;
                if(res[r5]*5==res[i])
                    r5++;
            }
            return res[index-1];
        }
    
    }
   
};