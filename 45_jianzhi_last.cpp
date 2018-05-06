class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n <= 0 || m < 0)
            return -1;
        if(n == 1)
            return 0;
        int last = 0;
        //else return (LastRemaining_Solution(n-1,m)+m)%n;
        for(int i =2; i <=n; i++)
            last = (last+m)%i;
        return last;
    }
};