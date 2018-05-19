class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        ++cnt[ch-'\0'];
        if(cnt[ch-'\0']==0)
            data.push(ch);
         
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!data.empty() && cnt[data.front()] > 0){
            data.pop();
        }
        if(data.empty())return '#';
        return data.front();
    
    }
    Solution(){
        for(int i = 0; i< 128; i++){
            cnt[i] = -1;
        }
    }
private:
    int cnt[128];
    queue<char> data;

};