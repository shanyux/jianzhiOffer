class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5)
            return false;
        sort(numbers.begin(), numbers.end());
        int num0 = 0;
        for(int i = 0; i < numbers.size(); i++){
            if(numbers[i] == 0)
                num0++;
        }
        int cha = 0;
        for(int i = num0+1; i < numbers.size(); i++){
            if(numbers[i] == numbers[i-1])
                return false;
            cha += numbers[i] - numbers[i-1]-1;
        }
        if(cha > num0)
            return false;
        return true;
    }
};