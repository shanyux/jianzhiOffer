class Solution {
public:
    string ReverseSentence(string str) {
        ReverseWord(str, 0 ,str.size()-1);
        int start = 0, end = 0;
        while(start < str.size()){
            if(str[start] == ' ')
            {
                start++;
                end++;
            }
            else if(str[end] == ' ' || end == str.size()){
                ReverseWord(str, start, end-1);
                start = ++end;
            }
            else
                end++;
        }
        return str;
    }
    void ReverseWord(string &str, int start, int end){
        while(start < end){
            char c = str[start];
            str[start] = str[end];
            str[end] = c;
            start++;
            end--;
        }
        
    }
};


无力吐槽你们的做法了，这种AC，你们觉得面试能过吗？这道题考的核心是应聘者是不是可以灵活利用字符串翻转。假设字符串abcdef，n=3，设X=abc，Y=def，所以字符串可以表示成XY，如题干，问如何求得YX。假设X的翻转为XT，XT=cba，同理YT=fed，那么YX=(XTYT)T，三次翻转后可得结果。

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.empty() || n == 0)
            return str;
        ReverseWord(str, 0, n-1);
        ReverseWord(str, n, str.size()-1);
        ReverseWord(str, 0, str.size()-1);
        return str;
    }
    void ReverseWord(string &str, int start, int end){
        while(start < end){
            char c = str[start];
            str[start] = str[end];
            str[end] = c;
            start++;
            end--;
        }
    }
};
 