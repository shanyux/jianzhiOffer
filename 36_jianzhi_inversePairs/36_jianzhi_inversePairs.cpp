class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.empty()){
            return 0;
        }
        vector<int> copy(data);
        int len = data.size();
        //cout << copy.size();
        long long count = comInversePairs(data, copy, 0, len-1);
        return count%1000000007;
        
    }
    long long comInversePairs(vector<int> &data, vector<int> &copy, int start, int end){
        if(start == end){
            copy[start] = data[start];
            return 0;
        }
        int mid = (start+end)/2;
        long long leftlen = comInversePairs(copy, data, start, mid);
        long long rightlen = comInversePairs(copy, data, mid+1, end);
        int i = mid;
        int j = end;
        int copyindex = end;
        long long count = 0;
        while(i >= start && j > mid){
            if(data[i] > data[j]){
                copy[copyindex--] = data[i--];
                count += j-mid;
            }
            else
               copy[copyindex--] = data[j--];
        }
        for(;i >=start; i--){
            copy[copyindex--] = data[i];
        }
        for(;j >mid; j--){
            copy[copyindex--] = data[j];
        }
        return leftlen+rightlen+count;
    }
};