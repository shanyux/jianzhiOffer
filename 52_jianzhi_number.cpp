class Solution {
public:
    bool isNumeric(char* string)//可以先从每个字符判断分析开始，然后判断他的各种条件，不要乱
    {
        bool sign = false, decimal = false, hase = false;//符号，小数点，有e
        for(int i = 0; i < strlen(string); i++){
            if(string[i] == '+' || string[i] == '-'){
                //第二次出现+-符号，则必须紧接在e之后
                if(sign && string[i-1]!= 'E' && string[i-1] != 'e')
                    return false;
                //第一次出现+-符号，不是在字符串开头，则也必须紧接在e之后
                if(!sign && i>0 && string[i-1]!= 'E' && string[i-1] != 'e')
                    return false;
                sign = true;
            }
            else if(string[i] == 'E' || string[i] == 'e'){
                if(hase || i == 0 || i == strlen(string)-1)
                    return false;
                hase = true;
            }
            else if(string[i] == '.')
            {
                if(decimal || i==0 || hase)
                    return false;
                decimal = true;
            }
            else if(string[i] > '9' || string[i] < '0')
                return false;
        }
        return true;
        
    }

};