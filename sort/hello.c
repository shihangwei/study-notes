#include <stdio.h>
#include <math.h>
#define ARR_LEN 255  /* 数组长度上限 */
#define elemType int /* 元素类型 */

void bubbleSort(elemType arr[], int len);    /*1.冒泡排序*/
void selectionSort(elemType arr[], int len); /*2.选择排序*/
void insertionSort(elemType arr[], int len); /*3.插入排序*/
void shellSort(elemType arr[], int len);     /*4.希尔排序*/
void mergeSort(elemType arr[], int len);     /*5.归并排序*/

int main()
{
    elemType arr[] = {1, 0, 9, 10, 20, -1, 81, 90, 3, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    if (len > ARR_LEN)
        return 0;

    /*bubbleSort(arr, len);*/
    /*selectionSort(arr, len);*/
    /*insertionSort(arr, len);*/
    shellSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}

/*1.冒泡排序*/
/*大的数，往后移。*/
/*稳定的*/
void bubbleSort(elemType arr[], int len)
{
    printf("start bubbleSort...\n");
    elemType temp;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*2.选择排序*/
/*选择最小的数，放在最前。*/
/*不稳定的，如：5 8 5 2 9*/
void selectionSort(elemType arr[], int len)
{
    printf("start selectionSort...\n");
    for (int i = 0; i < len - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        elemType jTemp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = jTemp;
    }
}

/*3.插入排序(直接插入排序)*/
/*第二个数开始，把之前的当作有序队列。之后的是无序数，把无序数插入到有序队列中。*/
/*稳定的*/
void insertionSort(elemType arr[], int len)
{
    printf("start insertionSort...\n");
    int i, j;
    elemType temp;
    for (i = 1; i < len; i++)
    {
        temp = arr[i];
        for (j = i; j > 0 && temp < arr[j - 1]; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

/*4.希尔排序(直接插入排序的改进版本)*/
/*分组进行直接插入排序*/
/*不稳定的*/
void shellSort(elemType arr[], int len)
{
    printf("start shellSort...\n");
    int gap, i, j;
    elemType temp;
    for (gap = len / 2; gap > 0; gap = gap / 2)
    {
        for (i = gap; i < len; i++)
        {
            temp = arr[i];
            for (j = i - gap; j >= 0 && temp < arr[j]; j = j - gap)
            {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
    }
}

/*5.归并排序*/
void mergeSort(elemType arr[], int len)
{
}
