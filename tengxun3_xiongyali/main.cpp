//��֪���Բ��ԣ��Ͼ�û�в��Ի���
//��һ�������Լ���ģ��Ÿ���Ȼ��ƥ��
//�ڶ������ҿ����д������ģ��Ҹ����Լ��ķ����д��һ��
//��һ��
/*#include <iostream>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> p1,pair<int,int> p2)
{
    int value1 = p1.first * 200 + 3 * p1.second;
    int value2 = p2.first * 200 + 3 * p2.second;
    if(value1 == value2)
        return p1.first >= p2.first;
    else
        return value1 > value2;

}
bool comm(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.first == p2.first)
        return p1.second > p2.second;
    else
        return p1.first > p2.first;
}
int main()
{
    int n, m,a,b;
    int sum = 0;
    int value = 0;
    cin >> n >> m;
    pair<int,int> na;
    pair<int,int> ma;

    vector<pair<int,int>> maczw;//����
    vector<pair<int,int>> proxy;//����
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        na= make_pair(a,b);
        maczw.push_back(na);

    }
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        ma= make_pair(a,b);
        proxy.push_back(ma);
    }
    sort(proxy.begin(),proxy.end(),comp);
    sort(maczw.begin(),maczw.end(),comm);
    for(int i = 0; i < m; i++)
    {
        cout << proxy[i].first << " " << proxy[i].second << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << maczw[i].first << " " << maczw[i].second << " ";
    }
    cout << endl;
    int j = 0;
    for(int i = 0; i < m; i++)
    {
        while(j < n)
        {
            if(maczw[i].first >= proxy[j].first && maczw[i].second >= proxy[j].second)
            {
                value +=  proxy[j].first * 200 + 3 * proxy[j].second;
                sum++;
                j++;
            }
            else j++;
        }
    }
    cout << sum << " " << value << endl;
    return 0;
}
*/
//�ڶ��� �������㷨�����ţ���һ��������ڶ����ǻ�����һ��һ���Աȣ��������������������������Ч��

#include <iostream>
#include <vector>
using namespace std;
int add(vector<int> &useP)
{
    int size = 0;
    for(size_t i = 0; i<useP.size(); i++)
    {
        if(useP[i])
            size++;
    }
    return size;
}
void solution(vector<pair<int,int>>& maczw, vector<pair<int,int>>&proxy,vector<int>& useM, vector<int>& useP,vector<int> &res,int tmpvalue,int index)
{
    if((add(useP) > res[0]) || ((add(useP) == res[0]) && (tmpvalue > res[1])))
    {
        res[0] = add(useP);
        res[1] = tmpvalue;
    }
    for(size_t i = index; i<proxy.size(); i++)
    {
        if(useP[i] == 1)
                continue;
        for(size_t j = 0; j < maczw.size(); j++)
        {
            if(useM[j] == 1)
                continue;
            else
            {
                if(proxy[i].first <= maczw[j].first && proxy[i].first <= maczw[j].first)
                {
                    useP[i] = 1;
                    useM[j] = 1;
                    solution(maczw,proxy,useM,useP,res,tmpvalue+proxy[i].first*200+proxy[i].second*3,index+1);
                    useP[i] = 0;
                    useM[j] = 0;

                }
            }
        }
    }

}
int main()
{
    int n, m,a,b;
    cin >> n >> m;
    pair<int,int> na;
    pair<int,int> ma;

    vector<pair<int,int>> maczw;//����
    vector<pair<int,int>> proxy;//����
    vector<int> useM(n,0);
    vector<int> useP(m,0);
    vector<int> res(2,0);

    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        na= make_pair(a,b);
        maczw.push_back(na);

    }
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        ma= make_pair(a,b);
        proxy.push_back(ma);
    }
    solution(maczw,proxy,useM,useP,res,0,0);


    cout << res[0] << " " << res[1] << endl;
    return 0;
}
