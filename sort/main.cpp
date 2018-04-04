#include <iostream>
#include <fstream>
#include<climits>
#include <algorithm>
using namespace std;
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void bubbleSort(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        bool flag = true;
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j],a[j+1]);
                flag = false;
            }
        }
        if(flag)
            return;
    }
}
void jiweijiuSort(int a[], int n)//鸡尾酒排序，定向冒泡排序 时间复杂度和空间复杂度和冒泡排序一样
{
    int left =0;
    int right = n - 1;
    while(left < right)
    {
        bool flag = true;
        for(int i = left; i < right; i++)
        {
            if(a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
                flag = false;
            }
        }
        right--;
        for(int j = right; j > left; j--)
        {
            if(a[j] < a[j-1])
            {
                swap(a[j],a[j-1]);
                flag = false;
            }
        }
        left++;
        if(flag)
            return;
    }
}
void insertSort(int a[], int n)
{
    for(int i = 0; i< n; i++)
    {
        for(int j = i+1; j > 0; j--)
        {
            if(a[j] < a[j-1])
            {
                swap(a[j],a[j-1]);
            }
            else
                break;
        }
    }

}
void selectSort(int a[], int n)
{
    int min;
    for(int i = 0; i< n; i++)
    {
        min = i;
        for(int j = i+1; j < n; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        if(min !=i )
            swap(a[min],a[i]);
    }
}
int partition1(int a[], int left, int right)//数据结构严蔚敏版
{
    int flag = a[left];
    while(left < right)
    {
        while(left < right && flag <= a[right])
            right--;
        a[left] = a[right];//也可以用swap，但是效率太低
        while(left < right && a[left] <= flag)
            left++;
        a[right] = a[left];
    }
    a[left] = flag;
    return left;

}
int partition2(int a[], int left, int right)//算法导论版
{
    int flag = a[right];
    int i = left -1;
    int j =left;
    for(; j < right; j++)
    {
        if(a[j] <= flag)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[right]);

    return i+1;;

}
void quickSort(int a[], int left, int right)//
{
    if(left < right)
    {
        int mid = partition2(a,left,right);
        quickSort(a,left,mid-1);
        quickSort(a,mid+1,right);
    }
}
void shellSort(int a[], int n)
{
    int gap = n;
    while(gap > 1)
    {
        gap = gap / 3 +1;
        for(int i = gap; i < n; i++)
        {
            for(int j = i; j >= gap; j -= gap)
            {
                if(a[j] < a[j-gap])
                    swap(a[j], a[j-gap]);
            }
        }

    }
}
void adjustHeap(int a[], int i,int n)
{
    int max = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < n && a[max] < a[left])
        max = left;
    if(right < n && a[max] < a[right])
        max = right;
    if(i != max)
    {
        swap(a[i],a[max]);
        adjustHeap(a,max,n);
    }

}
void buildHeap(int a[], int n)
{
    for(int i = (n-2)/2; i>= 0; i--)
    {
        adjustHeap(a,i,n);
    }
}
void heapSort(int a[], int n)
{
    buildHeap(a,n);
    int index = n;
    while(index > 1)
    {
        swap(a[0],a[--index]);
        adjustHeap(a,0,index);
    }
}
void merge(int a[], int left, int mid,int right)
{
    int leftlen = mid - left+1;
    int rightlen = right - mid;
    int *l = new int[leftlen+1];
    int *r = new int[rightlen+1];
    l[leftlen] = INT_MAX;
    r[rightlen] = INT_MAX;
    for(int i = 0; i< leftlen; i++)
    {
        l[i] = a[left+i];
    }

    for(int i = 0; i< rightlen; i++)
    {
        r[i] = a[mid+1+i];
    }
    int i = 0, j = 0;
    for(int k = left; k<= right; k++)
    {
        if(l[i] <= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
    }
    delete[] l;
    l=NULL;
    delete[] r;
    r = NULL;


}
void mergeSort(int a[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }

}
void countSort1(int a[], int n)
{
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        min = min<a[i]? min:a[i];
        max = max>a[i]? max:a[i];
    }
    int len = max-min+1;
    int *help = new int[len];
    for(int i = 0; i < len; i++)
    {
        help[a[i]-min]=0;
    }

    for(int i = 0; i < n; i++)
    {
        help[a[i]-min]++;
    }
    int j = 0;
    for(int i = len-1; i >= 0; i--)
    {
        while(help[i]>0)
        {
            a[j] = j+min;
            j++;
            help[i]--;
        }
    }
    delete []help;
    help = NULL;
}
void countSort2(int a[], int n)
{
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        min = min<a[i]? min:a[i];
        max = max>a[i]? max:a[i];
    }
    int len = max-min+1;
    int *help = new int[len];
    int *res = new int[n];
    for(int i = 0; i < len; i++)
    {
        help[i]=0;
    }

    for(int i = 0; i < n; i++)
    {
        help[a[i]-min]++;
    }
    for(int i = 1; i < len; i++)
    {
        help[i]=help[i]+help[i-1];//比他小的数包括他自己有多少个
    }
    for(int i = n-1; i >= 0; i--)// 当再遇到重复元素时会被放在当前元素的前一个位置上保证计数排序的稳定性
    {
        int pos = --help[a[i] - min];
        res[pos] = a[i];
    }
    for(int i = 0; i < n; i++)
    {

        cout << res[i] << " ";
    }
    delete []help;
    help = NULL;
    delete []res;
    res = NULL;
}
void radixSort(int a[], int n)
{
    int maxnum = *max_element(a, a+n);// INT_MIN;
    int max_size = 10;
    //int minnum = *min_element(a, a+n);
    //cout << maxnum;
    /*for(int i = 0; i < n; i++)
    {
        maxnum = maxnum > a[i]? maxnum:a[i];
    }*/

    int chushu = 1;
    while(maxnum / chushu > 0)
    {
        int *bucket = new int[n]();
        int *help = new int[max_size]();

        for(int i = 0; i < n; i++)
        {
            help[a[i]/chushu %10]++;
        }
        for(int i = 1; i < max_size; i++)
        {
            help[i] += help[i-1];
        }
        for(int i = n-1; i >=0 ; i--)//保证稳定性
        {
            bucket[--help[a[i]/chushu %10]] =a[i];

        }
        for(int i = 0; i < n; i++)
        {
            a[i] = bucket[i];
        }
        for(int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
        chushu *= 10;
        delete []help;
        help = NULL;
        delete []bucket;
        bucket = NULL;
    }

}
void bucketSort(int a[], int n, int bucket_num)
{
    int max = *max_element(a,a+n);
    int min = *min_element(a,a+n);
    int num = (max-min+1+bucket_num-1)/bucket_num;
    int *help = new int[bucket_num]();
    int *bucket = new int[n]();
    for(int i = 0; i < n; i++)
    {
        help[(a[i]-min)/num%num]++;
    }
    for(int i = 0; i < bucket_num; i++)
    {
        cout << help[i] << " ";
    }
    cout <<endl;
    for(int i = 1; i < bucket_num; i++)
    {
        help[i] = help[i] + help[i-1];
    }
    for(int i = 0; i < bucket_num; i++)
    {
        cout << help[i] << " ";
    }
    cout <<endl;
    for(int i = n-1; i >=0 ; i--)
    {
        bucket[--help[(a[i]-min)/num%num]] =a[i];
    }
    for(int i = 0; i < bucket_num; i++)
    {
        cout << help[i] << " ";
    }
    cout <<endl;
    for(int i = 0; i < n; i++)
    {
        a[i] = bucket[i];
    }
    for(int i =0; i < bucket_num-1; i++)//help改变成了指向第一位置了
    {
        quickSort(a,help[i],help[i+1]-1);
    }
    quickSort(a,help[bucket_num-1],n-1);


    delete []help;
    help = NULL;
    delete []bucket;
    bucket = NULL;
}

int main()
{
    fstream fin("data.txt");
    int n = 15;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        fin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cout <<a[i] <<" ";
    }
    cout <<endl;
    //bubbleSort(a,n);
    //jiweijiuSort(a,n);
    //insertSort(a,n);
    //selectSort(a,n);
    //quickSort(a,0,n-1);
    //shellSort(a,n);
    //heapSort(a,n);
    //mergeSort(a,0,n-1);
    //countSort2(a,n);
    //radixSort(a,n);
    bucketSort(a,n,8);
    for(int i = 0; i < n; i++)
    {
        cout <<a[i] <<" ";
    }
    ////cout << "Hello world!" << endl;
    return 0;
}
