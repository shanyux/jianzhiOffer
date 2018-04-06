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
    if(right==left || a[left] < a[right])//�ܶ��������
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

    // ���ظ����֣������ظ������ָպõ���С������
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // ������ֻ��һ������
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    return 0;
}
