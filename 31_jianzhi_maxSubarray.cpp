class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size()==0)
            return 0;
        int maxnum = 0X80000000, curnum = 0;
        for(int i = 0; i<array.size();i++){
            if(curnum <=0){
                curnum = array[i];
            }
            else{
                curnum += array[i];                
            }
            if(curnum > maxnum) 
                maxnum = curnum;
        }
        return maxnum;
    
    }
};
