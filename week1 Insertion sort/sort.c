#include <math.h>
#include <stdio.h>

//�i�洡�J�Ƨ�
void insertionSort(int arr[], int n)
{
    int i, value, j;
    for (i = 1; i < n; i++)
    {
        value = arr[i];
        j = i - 1;

        /*�Y����arr[0..i-1]��value�j
          �N��������(���J)��e��m���e�@��*/
        while (j >= 0 && arr[j] > value)
        {
            arr[j + 1] = arr[j];    //���ʰ}�C��������
            j = j - 1;
        }
        arr[j + 1] = value; //��쥿�T��m���J
    }
}

// ��X�Ƨǫ᪺�Ʀr
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
    scanf("%d",&n); //��J�n�i��ƧǪ��Ʀr���h��

    int arr[n];
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);    //��J�n�i��ƧǪ��Ʀr

    insertionSort(arr, n);  //�i��Ƨ�
    printArray(arr, n); //��X�Ƨǫ᪺�Ʀr
    return 0;
}
