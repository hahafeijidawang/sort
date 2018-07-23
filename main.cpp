// 排序.cpp : 定义控制台应用程序的入口点。
//


#include<iostream>
#include<stack>
#include<assert.h>
#include<cstdio>
using namespace std;
//-------------------------------------插入排序------------------------------------------
//直接插入排序
void InsertSort(int *a, int len)
{
    assert(a);
    if (len < 0)
    {
        printf("len is iligel");
            return;
    }
    for (int i = 1; i < len; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;


    }

}
//希尔排序 当希尔排序的排序间隔h=1就是直接排序
void ShellSort(int *a, int len)
{
    assert(a);
    if (len < 0)
    {

        printf("len is iligel");

        return;

    }


    int h = len / 3 + 1;
    while (h > 0)
    {
        for (int i = h; i < len; i++)
        {
            int key = a[i];
            int j = i - h;
            while (j >= 0 && key < a[j])
            {

                a[i] = a[j];
                j = j - h;


            }

            a[j + h] = key;

        }

        h =h/3;

    }


}
//-------------------------------------------------交换排序-------------------------------------------------
//冒泡排序

void BubSort(int *a,int len)
{
    //assert(a);

    for (int i = 0; i < len; i++)
    {
        for (int j =i; j < len; j++)
        {
            if (a[j] > a[j + 1])
            {
                a[j] = a[j] + a[j + 1];
                a[j+1] = a[j] - a[j + 1];
                a[j] = a[j] - a[j + 1];
//                int temp;

//                temp = a[j];

//                a[j] = a[j + 1];

//                a[j + 1] = temp;

            }


        }

    }

}
//快速排序
//快速排序-左右指针法(递归实现)




int Division3(int* a,int left,int right)
{
    int begin = left;
    int end = right;
    int key = right;

    while( begin < end )
    {
        //begin找大
        while(begin < end && a[begin] <= a[key])
        {
            ++begin;
        }
        //end找小
        while(begin < end && a[end] >= a[key])
        {
            --end;
        }
        swap(a[begin],a[end]);
    }
    swap(a[begin],a[right]);
    return begin;//返回的是中间的位置，swap只是交换值
}
void QuickSort_R(int *a,int left,int right)
{
    assert(a);

    if(left<right)
    {

        int index = Division3(a,left,right);

        QuickSort_R(a,left,index-1);

        QuickSort_R(a,index+1,right);

    }

}
/*
基本思路： 利用栈保存左右区间
1. 左右区间入栈（先右后左）
2. 取栈顶元素，出栈
3. 排序
4. 入栈，先右后左（直到栈为空，停止循环）
*/
//左右指针非递归实现方法
void QuickSortNOR(int *a,int left,int right)
{
    stack<int>s;

    if(left<right)
    {

        s.push(left);
        s.push(right);

    }

    while(!s.empty())
    {
        int right = s.top();

        s.pop();

        int left = s.top();

        s.pop();

        int div = Division3(a,left,right);//




            if(left<div-1)
            {
                s.push(left);
                s.push(div-1);

            }
            if(div+1<right)
            {
                s.push(div+1);

                s.push(right);

            }

    }


}


void print(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {

        std::cout << a[i] << " ";

    }
    cout << endl;
}

int main()
{
    int a[8] = {4,8,7,10,6,9,2,5};
    printf("排序前：\n");

    print(a,8);


    printf("排序后：\n");

        //InsertSort(a,7);


       // ShellSort(a, 7);

       // BubSort(a,7);

      //  QuickSort_R(a,0,7);

    QuickSortNOR(a,0,7);
    print(a,8);

    system("pause");

    return 0;
}
