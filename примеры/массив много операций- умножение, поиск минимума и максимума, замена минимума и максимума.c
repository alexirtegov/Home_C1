#include <stdio.h>
#include <inttypes.h>

#define SIZE 5
#define COEF 3

int Input(int arr[], int n)
{
    //~ static int test[3] = {0};
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    return i;
}

void Print(int *arr,int len)// выводим наш массив с первого по последний член
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void Mult(int *arr,int len,int k)
{
    int i;
    for (i = 0; i < len; i++)
        arr[i]*=k;
}

int Min(int *arr,int len)
{
    int min=arr[0],i;
    for (i = 0; i < len; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    return min;
}

int PosMin(int *arr,int len)
{
    int min=arr[0],i,pos=0;
    for (i = 1; i < len; i++)
        if (min > arr[i])
        {
            min = arr[i];
            pos = i;
        }
    return pos;
}

int PosMax(int *arr,int len)
{
    int max=arr[0],i,pos=0;
    for (i = 1; i < len; i++)
        if (max < arr[i])
        {
            max = arr[i];
            pos = i;
        }
    return pos;
}

void SwapArr(int *arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void BubbleSort(int* arr,int n)
{
    int noSwap;
    for (int i = 0; i < n; i++)
    {
        noSwap = 1;
        for (int j = n-1; j > i; j--)
        {
            if(arr[j-1]>arr[j])
            {
                SwapArr(arr,j-1,j);
                noSwap = 0;
            }
        }
        if(noSwap)
            break;
    }
}


int main(void)
{
    int arr[SIZE]; 
    Input(arr,SIZE); //вызывваем функцию, где присваиваем каждому члену массива значение
    Mult(arr,SIZE,COEF); // перемножаем все знчания каждого члена на coef
    Print(arr,SIZE); // выводим наш массив по членам начиная сначала
    printf("Min = %d\n",Min(arr,SIZE)); //выводим значение минимума, которое получает вызов от функции в виде результата
    SwapArr(arr, PosMin(arr,SIZE), PosMax(arr,SIZE)); //замена миниммума и максимума
    Print(arr,SIZE); // опять выводим наш массив последовательно после операции умножения и замены минимума и максимума
    BubbleSort(arr,SIZE); //сортировка 
    Print(arr,SIZE); // очередной вывод
    return 0;
}
