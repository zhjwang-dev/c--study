//
// Created by zhjwang on 2021/4/15.
//
#include <iostream>
void test2()
{
    int a[] = {10, 11, 12};
    int b[] = {20, 21, 34};
    int c[] = {30, 31, 56};

    int *p1 = a;
    int *p2 = b;
    int *p3 = c;

    int *arr[] = {p1, p2, p3};

    printf("%p\n", &a);
    printf("%p\n", &a + 1);
    printf("%p\n", &(a[0]));
    printf("%p\n", &(a[0]) + 1);

    printf("%p\n", &(arr[0]));
    printf("%p\n", &(arr[0]) + 1);
    printf("%p\n", &(arr[0]) + 2);

    printf("========================\n");

    int **arr1 = NULL;
    printf("%p\n", arr1);
    printf("%p\n", arr1 + 1);
    printf("arr1:%d\n", sizeof(arr1));

    int *arr2 = NULL;
    printf("%p\n", arr2);
    printf("%p\n", arr2 + 1);
    printf("arr2:%d\n", sizeof(arr2));

    void *arr3 = NULL;
    printf("arr3:%d\n", sizeof(arr3));

    printf("%d\n", arr[0][1]);     //11  技术推演 arr[0] 是第一个数组的地址，访问元素arr[1]是第一个数组的首地址
    printf("%d\n", *(arr[0] + 1)); //11
}

void test3()
{
    int arr[2][3] = {
        {2, 5, 8},
        {3, 6, 9}};
    int(*p)[3] = arr;              //二维数组名表示的是第一个一维数组的地址
    printf("%d\n", (*(p + 1))[2]); //9  p是数组指针，加1就是跳过1个一维数组，得到第二个二维数组的地址。*解引用得到第二个一维数组的首地址
    int(*p1)[2][3] = &arr;         //二维数组指针，二维数组&

    printf("%p\n", p);        //整个一维数组的地址：0x7ffee91495c0
    printf("%p\n", *p);       //一维数组的首地址：0x7ffee91495c0
    printf("%p\n", p + 1);    // 加12
    printf("%p\n", (*p) + 1); //加4
}

void test4()
{
    int a[] = {1, 2, 2};
    int *p = a;

    int(*p1)[3] = &a;

    printf("%p\n", a);
    printf("%p\n", p);
    printf("%p\n", &a);

    printf("%p\n", p + 1);
    printf("%p\n", &a + 1);
    printf("%p\n", p1 + 1);

    int arr[2][3] = {1, 2, 3, 4, 5, 6};
    printf("%p\n", arr);
    printf("%p\n", arr + 1);

    printf("%p\n", &arr);
    printf("%p\n", &arr + 1);

    printf("%p\n", arr[0]);
    printf("%p\n", arr[0] + 1);

    printf("%p\n", &(arr[0]));
    printf("%p\n", &(arr[0]) + 1);
}

int main()
{
    test2();
}