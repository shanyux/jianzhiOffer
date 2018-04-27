#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

/*int InversePairsCore(int* data, int* copy, int start, int end);

int InversePairs(int* data, int length)
{
    if(data == nullptr || length < 0)
        return 0;

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
        copy[i] = data[i];

    int count = InversePairsCore(data, copy, 0, length - 1);
    delete[] copy;

    return count;
}

int InversePairsCore(int* data, int* copy, int start, int end)
{
    if(start == end)
    {
        copy[start] = data[start];
        return 0;
    }

    int length = (end - start) / 2;

    int left = InversePairsCore(copy, data, start, start + length);
    int right = InversePairsCore(copy, data, start + length + 1, end);

    // i初始化为前半段最后一个数字的下标
    int i = start + length;
    // j初始化为后半段最后一个数字的下标
    int j = end;
    int indexCopy = end;
    int count = 0;
    while(i >= start && j >= start + length + 1)
    {
        if(data[i] > data[j])
        {
            copy[indexCopy--] = data[i--];
            count += j - start - length;
        }
        else
        {
            copy[indexCopy--] = data[j--];
        }
    }

    for(; i >= start; --i)
        copy[indexCopy--] = data[i];

    for(; j >= start + length + 1; --j)
        copy[indexCopy--] = data[j];

    return left + right + count;
}
*/
int comInversePairs(vector<int> &data, vector<int> &copy, int start, int end);
int InversePairs(vector<int> data)
{
    if(data.empty())
    {
        return 0;
    }
    vector<int> copy(data);
    int len = data.size();
    //cout << copy.size();
    int count = comInversePairs(data, copy, 0, len-1);
    return count%1000000007;

}
int comInversePairs(vector<int> &data, vector<int> &copy, int start, int end)
{
    if(start == end)
    {
        copy[start] = data[start];
        return 0;
    }
    int mid = (start+end)/2;
    int leftlen = comInversePairs(copy, data, start, mid);
    int rightlen = comInversePairs(copy, data, mid+1, end);
    int i = mid;
    int j = end;
    int copyindex = end;
    int count = 0;
    while(i >= start && j > mid)
    {
        if(data[i] > data[j])
        {
            copy[copyindex--] = data[i--];
            count += j-mid;
        }
        else
            copy[copyindex--] = data[j--];
    }
    for(; i >=start; i--)
    {
        copy[copyindex--] = data[i];
    }
    for(; j >mid; j--)
    {
        copy[copyindex--] = data[j];
    }
    return leftlen+rightlen+count;
}

// ====================测试代码====================
void Test(char* testName, vector<int> data, int expected)
{
    if(testName != nullptr)
        printf("%s", testName);
    cout << " " << InversePairs(data) << endl;

    if(InversePairs(data) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    vector<int> data = { 1, 2, 3, 4, 7, 6, 5 };
    int expected = 3;


    Test("Test1", data, expected);
}

// 递减排序数组
void Test2()
{
    vector<int> data = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, expected);
}

// 递增排序数组
void Test3()
{
    vector<int> data = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, expected);
}

// 数组中只有一个数字
void Test4()
{
    vector<int> data = { 1 };
    int expected = 0;

    Test("Test4", data, expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
    vector<int> data = { 1, 2 };
    int expected = 0;

    Test("Test5", data, expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
    vector<int> data = { 2, 1 };
    int expected = 1;

    Test("Test6", data, expected);
}

// 数组中有相等的数字
void Test7()
{
    vector<int> data = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}
