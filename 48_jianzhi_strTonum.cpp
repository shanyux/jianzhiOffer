class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())
            return 0;
        int len = str.size();
        long long res = 0;
        int s = 1;
        if(str[0] == '-')  s = -1;
        for(int i = (str[0] == '-' || str[0] == '+')? 1 :0; i < len; i++)
        {
            if(str[i] < '0' || str[i] >'9'){
                return 0;
            }
            else
                res = (res <<1) + (res << 3) + (str[i] - '0');
        }
        return s*res;
        
    }
};