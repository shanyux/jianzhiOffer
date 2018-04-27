class Solution {
public:
    /*int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        int num = 0;
        int s = findfirst(data, k, 0, data.size()-1);
        int e = findend(data, k, 0, data.size()-1);
        if(s > -1 && e > -1)
            num= e-s+1;
        return num;
    }
    int findfirst(vector<int> &data ,int k, int start, int end){
        if(start > end)
            return -1;
        int mid = (start+end) >> 1;
        if(k == data[mid]){
            if((mid > 0 && (data[mid-1] != k)) || (mid ==0))
                return mid;
            else
                end = mid -1;
        }
        else if(data[mid] > k)
            end = mid-1;
        else
            start = mid+1;
        return findfirst(data, k, start, end);
    }
    int findend(vector<int> &data ,int k, int start, int end){
        if(start > end)
            return -1;
        int mid = (start+end) >> 1;
        if(k == data[mid]){
            if((mid < data.size()-1 && data[mid+1] != k)|| (mid == data.size()-1))
                return mid;
            else
                start = mid +1;
        }
        else if(data[mid] > k)
            end = mid-1;
        else
            start = mid+1;
        return findend(data, k, start, end);
    }*/
    int GetNumberOfK(vector<int> data ,int k) {
        return search(data, k+0.5)-search(data, k-0.5);
    }
    int search(vector<int> &data ,double k){
        int start = 0, end = data.size()-1;
        while(start<=end){
            int mid = (start+end) >> 1;
            if(data[mid] > k)
                end = mid-1;
            else
                start = mid+1;
            
        }
        return start;
    }
};