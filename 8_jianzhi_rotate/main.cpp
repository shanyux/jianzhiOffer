#include <iostream>

using namespace std;
int minorder(int a[], int left, int right)
{
    int mid = left;
    for(int i = left+1; i<=right; i++)
    {
        if(a[i] < a[mid])
            mid = i;
    }
    return mid;
}
int Min(int a[], int length)
{
    int left = 0;
    int right = length-1;
    int mid = (left+right)/2;
    if(right==left || a[left] < a[right])//很多特殊情况
        return a[left];
    while(a[left] >= a[right])
    {
        //cout << "1111" << endl;
        if(left == right)
        {
            mid = left;
            break;
        }
        if(a[mid] > a[left])
        {
            left = mid;
            mid = (left+right)/2;
        }
        else if(a[mid] < a[right])
        {
            right = mid;
            mid = (left+right)/2;
        }
        else
        {
            mid = minorder(a,left,right);
            break;
        }
    }
    if(a[left] >= a[right])
    return a[mid];
}
void Test(int* numbers, int length, int expected)
{
    int result = 0;
    result = Min(numbers, length);

    for(int i = 0; i < length; ++i)
        cout << numbers[i] << " ";
    cout << endl;

    if(result == expected)
        cout << "passed";
    else
        cout << "failed";
    cout << endl;


}
int main()
{
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    return 0;
}
