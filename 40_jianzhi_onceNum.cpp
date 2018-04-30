class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {//异或
        if(data.size() < 2)
            return;
        int yihuores = 0;
        for(auto it = data.begin(); it != data.end(); it++){
            yihuores ^= *it;
        }
        int index = findFristbit(yihuores);
        *num1 = 0;
        *num2 = 0;
        if(yihuores > -1){
            for(auto it = data.begin(); it != data.end(); it++){
                if(bitof1(*it, index)){
                    *num1 ^= *it;
                }
                else
                    *num2 ^= *it;
            }
        }

    }
    int findFristbit(int number){//获取第一个为1的位，然后区分两个集合，然后分别异或
        if(number ==0)
            return -1;
        int index = 0;
        while(!(number & 1)){
            index++;
            number >>= 1;
        }
        return index;
    }
    bool bitof1(int number, int index){
        if(number >> index & 1)
            return true;
        return false;
    }
};