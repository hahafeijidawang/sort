// ����.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include<iostream>
#include<stack>
#include<assert.h>
#include<cstdio>
using namespace std;
//-------------------------------------��������------------------------------------------
//ֱ�Ӳ�������
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
//ϣ������ ��ϣ�������������h=1����ֱ������
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
//-------------------------------------------------��������-------------------------------------------------
//ð������

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
//��������
//��������-����ָ�뷨(�ݹ�ʵ��)




int Division3(int* a,int left,int right)
{
    int begin = left;
    int end = right;
    int key = right;

    while( begin < end )
    {
        //begin�Ҵ�
        while(begin < end && a[begin] <= a[key])
        {
            ++begin;
        }
        //end��С
        while(begin < end && a[end] >= a[key])
        {
            --end;
        }
        swap(a[begin],a[end]);
    }
    swap(a[begin],a[right]);
    return begin;//���ص����м��λ�ã�swapֻ�ǽ���ֵ
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
����˼·�� ����ջ������������
1. ����������ջ�����Һ���
2. ȡջ��Ԫ�أ���ջ
3. ����
4. ��ջ�����Һ���ֱ��ջΪ�գ�ֹͣѭ����
*/
//����ָ��ǵݹ�ʵ�ַ���
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
    printf("����ǰ��\n");

    print(a,8);


    printf("�����\n");

        //InsertSort(a,7);


       // ShellSort(a, 7);

       // BubSort(a,7);

      //  QuickSort_R(a,0,7);

    QuickSortNOR(a,0,7);
    print(a,8);

    system("pause");

    return 0;
}
