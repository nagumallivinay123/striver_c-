#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{

    // water lo bubble evidanga ayithe kinda nunchi paiki velli pelutundo adhe vidanga
    // pedda element ni sort chesi paiki paiki pampistamu
    // example kavali ante log2 base lo chudu okasari
    // swaping chestamu pedda number ni last ki pampinchestamu
    int arr[7] = {78, 3, 4, 66, 45, 67, 67};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)//actual second loop manaki main important entate compare cheyadaniki kani first loop deniki ante okasari 1st time compare chesaka pedda element last ki velipothundi malli dani compare cheyakunda undadaniki ala chestunammu
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}