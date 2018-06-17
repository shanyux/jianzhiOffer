class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> index;
        for(int i =0; i< num.size(); i++){
            while(index.size() && num[i] >= num[index.back()])
                index.pop_back();
            if(index.size() && i - index.front()>= size)
                index.pop_front();
            index.push_back(i);
            if(size && i+1 >= size)
                res.push_back(num[index.front()]);
        }
        return res;
    }
};