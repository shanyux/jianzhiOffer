class Solution {
public:
    void push(int value) {
        if(data.empty()){
            data.push(value);
            min_data.push(value);
        }
        else
        {
            if(value < min_data.top()){
                min_data.push(value);
            }
            else
                min_data.push(min_data.top());
            data.push(value);
        }
        
        
    }
    void pop() {
       // assert(data.size() > 0 && min_data.size() > 0);
        if(data.size() >0 && min_data.size() > 0){
        min_data.pop();
        data.pop();
        }
        else
           throw "error";
        
    }
    int top() {
        //assert(data.size() >0 && min_data.size() > 0);
        if(data.size() >0 && min_data.size() > 0)
            return data.top();
        throw "error";
        
    }
    int min() {
        //assert(data.size() >0 && min_data.size() > 0);
        if(data.size() >0 && min_data.size() > 0)
           return min_data.top();
        throw "error";
        
    }
    stack<int> min_data;
    stack<int> data;
};