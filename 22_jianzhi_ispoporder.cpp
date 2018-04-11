class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int len = pushV.size();
        int i = 0;
        int j = 0;
        bool flag = true;
        stack<int> s;
        while(i<len && j< len){
            while(pushV[i] != popV[j] && i < len){
                s.push(pushV[i]);
                i++;
            }            
            j++;
            while(!s.empty() && j < len && s.top() == popV[j]){
                j++;
                s.pop();
            }
            i++;
        }
        while(!s.empty() && s.top()== popV[j] && j <len){
            j++;
            s.pop();
        }
        if(!s.empty())
            flag = false;
        return flag;
            
        
        
    }
};