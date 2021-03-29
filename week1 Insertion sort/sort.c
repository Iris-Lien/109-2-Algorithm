#include <math.h>
#include <stdio.h>

//進行插入排序
void insertionSort(int arr[], int n)
{
    int i, value, j;
    for (i = 1; i < n; i++)
    {
        value = arr[i];
        j = i - 1;

        /*若元素arr[0..i-1]比value大
          將元素移至(插入)當前位置的前一個*/
        while (j >= 0 && arr[j] > value)
        {
            arr[j + 1] = arr[j];    //移動陣列內的元素
            j = j - 1;
        }
        arr[j + 1] = value; //找到正確位置插入
    }
}

// 輸出排序後的數字
void printArray(int arr[], int n)
{
    int i;
    printf("Sorted:");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("How many numbers you want to sort:",n);
    scanf("%d",&n); //輸入要進行排序的數字有多少

    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);    //輸入要進行排序的數字

    insertionSort(arr, n);  //進行排序
    printArray(arr, n); //輸出排序後的數字
    return 0;
}
