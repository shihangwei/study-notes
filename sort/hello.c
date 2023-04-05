#include <stdio.h>
#include <math.h>
#define ARR_LEN 255  /* 数组长度上限 */
#define elemType int /* 元素类型 */

void bubbleSort(elemType arr[], int len);                                    /*1.冒泡排序*/
void selectionSort(elemType arr[], int len);                                 /*2.选择排序*/
void insertionSort(elemType arr[], int len);                                 /*3.插入排序*/
void shellSort(elemType arr[], int len);                                     /*4.希尔排序*/
void mergeSort(elemType arr[], int len);                                     /*5.归并排序*/
void mergeSortRecursive(elemType arr[], elemType reg[], int start, int end); /*5.归并排序-递归*/

int main()
{
    elemType arr[] = {1, 0, 9, 10, 20, -1, 81, 90, 3, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    if (len > ARR_LEN)
        return 0;

    /*bubbleSort(arr, len);*/
    /*selectionSort(arr, len);*/
    insertionSort(arr, len);
    /*shellSort(arr, len);*/

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
    int i, j;
    elemType temp;
    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
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
    int i, j, minIndex;
    elemType temp;
    for (i = 0; i < len - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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
        for (j = i - 1; j >= 0 && temp < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
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
/*是分治法的典型应用: 1.自上而下的递归;2.自下而上的迭代*/
/*稳定的*/
void mergeSort(elemType arr[], int len)
{
    // 递归
    elemType reg[len];
    mergeSortRecursive(arr, reg, 0, len - 1);
}
void mergeSortRecursive(elemType arr[], elemType reg[], int start, int end)
{
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = end;
    int start2 = mid + 1, end2 = end;
    mergeSortRecursive(arr, reg, start1, end1);
    mergeSortRecursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}
