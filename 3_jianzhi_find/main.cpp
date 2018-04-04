#include <iostream>
#include <fstream>

using namespace std;
bool Find(int a[], int rows, int cols,int num)
{
    bool flag = false;
    if(a != 0 && rows >0 && cols >0)
    {
        int row = 0;
        int col = num-1;
        while(row <rows && cols >0)
        {
            if(a[row*cols+col] == num)
            {
                flag = true;
                break;
            }
            if(a[row*cols+col] > num)
                col--;
            else
                row++;
        }

    }
    return flag;
}
int main()
{
    int row = 0, col =0,num =0;
    fstream fin("data.txt");
    fin >> row >> col;
    int *a = new int[row*col]();
    for(int i = 0; i< row; i++)
        for(int j = 0; j <col; j++)
            fin >> a[i*col+j];
    cin >> num;
    bool res = Find(a,row,col,num);
    if(res)
        cout << "yes" <<endl;
    else
        cout << "false" <<endl;
    return 0;
}
