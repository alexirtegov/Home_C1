//массив сортировка пузырьком varian 1

#include <stdio.h>
#include <inttypes.h>

#define SIZE 5

void Input(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    return;
}

void Print(int *arr,int len)
{
    int i;
    for (i = 0; i < len; i++){
        printf("%d ",arr[i]);
	}
    printf("\n");
    


    for (i = 0; i < len; i++){
    printf("adress ar[%d]  %p\n", i, &arr[i]);
}
}

void SwapArr(int arr[],int i,int j) //например arr[3] =5 i=5, а arr[4]=4 j=4
{
    int temp = arr[i];// temp заносится значение 5
    arr[i] = arr[j];// на место arr[3] записывается arr[4]  то есть 4
    arr[j] = temp; //на место arr[4] записывается значение 5
    //получаем замену 5 4 на 4 5
}

void BubbleSort(int arr[],int n)
/*
Общее поведение
Внешний цикл по i от 0 до n–1 задаёт «уровень» уже отсортированной (минимальной) части в начале массива. 
Внутренний цикл по j от n–1 вниз до i+1 сравнивает соседние элементы arr[j-1] и arr[j] и, 
если они идут не в порядке, меняет их местами. 
Переменная noSwap отслеживает, делались ли перестановки на данной «ступени»; 
если за целый проход ни одной перестановки не случилось, цикл прерывается, поскольку массив уже упорядочен.

Шаг за шагом на примере [5, 4, 3, 2, 1] (n = 5)
i = 0, до этого noSwap = 1.
— j = 4: сравниваем arr[3]=2 и arr[4]=1. Так как 2>1, меняем местами → [5, 4, 3, 1, 2], noSwap = 0.
— j = 3: сравниваем arr[2]=3 и arr[3]=1. 3>1 → [5, 4, 1, 3, 2].
— j = 2: сравниваем arr[1]=4 и arr[2]=1. 4>1 → [5, 1, 4, 3, 2].
— j = 1: сравниваем arr[0]=5 и arr[1]=1. 5>1 → [1, 5, 4, 3, 2].
После первого внешнего прохода самый маленький элемент «вспух пузырьком» в начало. Массив стал [1, 5, 4, 3, 2].
повторяем для i=1

i = 1, внутренний цикл j от 4 до 2:
— j = 4: arr[3]=3, arr[4]=2 → [1, 5, 4, 2, 3]
— j = 3: arr[2]=4, arr[3]=2 → [1, 5, 2, 4, 3]
— j = 2: arr[1]=5, arr[2]=2 → [1, 2, 5, 4, 3]

i = 2, j = 4…3:
— j = 4: arr[3]=4, arr[4]=3 → [1, 2, 5, 3, 4]
— j = 3: arr[2]=5, arr[3]=3 → [1, 2, 3, 5, 4]

i = 3, j = 4:
— j = 4: arr[3]=5, arr[4]=4 → [1, 2, 3, 4, 5]
*/

{
    int noSwap =1;
    for (int i = 0; i < n; i++) // во внешнем цикле мы переключае уровень массива он начало до конца
    {
        
        for (int j = n-1; j > i; j--) // n-1 потому что это и есть верхний уровень массива, так как счет идет с ноля
        {
            if(arr[j-1]>arr[j])
            {
                SwapArr(arr,j-1,j);
                noSwap = 0;
            }
        }
        if(noSwap==1) //провперка если перестановок не было niSwap останется единицой- выход
            return;
    }
}

int main(int argc, char **argv)
{
    int arr[SIZE]={0};
    printf("adress arr[0] is %p\n", &arr[0]);
    Input(arr,SIZE);
    BubbleSort(arr,SIZE);
    Print(arr,SIZE);
    return 0;
}


//varian 2

//~ #include <stdio.h>
//~ #include <inttypes.h>

//~ #define SIZE 5

//~ int Input(int* arr, int n)
//~ {
    //~ int i;
    //~ for(i=0;i<n;i++)
        //~ scanf("%d",&arr[i]);
    //~ return i;
//~ }

//~ void Print(int *arr,int len)
//~ {
    //~ int i;
    //~ for (i = 0; i < len; i++)
        //~ printf("%d ",arr[i]);
    //~ printf("\n");
//~ }

//~ void SwapArr(int *arr,int i,int j) // i=5 j=4
//~ {
    //~ int temp = arr[i]; //=5
    //~ arr[i] = arr[j];// was 5 became 4
    //~ arr[j] = temp;// was 4 became 5
    //~ //was 5 4 became 4 5
//~ }

//~ void BubbleSort(int* arr, int n)
//~ {
    //~ int noSwap,i,j; 
    //~ for(i=n-1; i>=0; i--)//massive for example  5 4 3 2 1
    //~ {
        //~ noSwap = 1;
        //~ for(j=0; j<i; j++) //for i=[4]=1 
        //~ {
            //~ if(arr[j]>arr[j+1])//arr[0]=5 and arr[1]=4
            //~ {
                //~ SwapArr(arr,i,j); //5>4  //4 5 3 2 1// 4 3 5 2 1// 4 3 2 5 1 // 4 3 2 1 5
                //~ noSwap = 0;
            //~ }
        //~ }
        //~ if(noSwap)
            //~ break;
    //~ }
//~ }

//~ int main(int argc, char **argv)
//~ {
    //~ int arr[SIZE]={0};
    //~ Input(arr,SIZE);
    //~ BubbleSort(arr,SIZE);
    //~ Print(arr,SIZE);
    //~ return 0;
//~ }
