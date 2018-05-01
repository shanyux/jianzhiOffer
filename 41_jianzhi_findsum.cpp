class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if(sum < 3){
            return res;
        }        
        int small = 1;
        int big = 2;
        int middle = (sum+1) >> 1;
        int tmpsum = small + big;
        while(small < middle){
            if(tmpsum == sum){
                addVector(res, small, big);
                /*vector<int> v;
                for(int i = small; i <= big; i++){
                    v.push_back(i);
                }
                res.push_back(v);*/
                big++;
                tmpsum += big;
            }
            else if(tmpsum > sum){
                tmpsum -= small;
                small++;
            }
            else{
                big++;
                tmpsum += big;
            }
        }
        return res;
        
    }
    void addVector(vector<vector<int> > &res, int small, int big){
         vector<int> v;
         for(int i = small; i <= big; i++){
             v.push_back(i);
         }
         res.push_back(v);
    }
};




class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if(!array.empty()){
            int i = 0;
            int j = array.size() -1;
            while(i<j){
                if(array[i] + array[j] == sum){
                    res.push_back(array[i]);
                    res.push_back(array[j]);
                    break;
                }
                else if(array[i] + array[j] > sum){
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return res;
        
    }
};