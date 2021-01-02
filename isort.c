#include <stdio.h>
#define N 50

void shift_element(int* arr, int i){
 while (i)
 {
     *(arr+i)=*(arr+i-1);
     i--;
 }
}
void insertion_sort(int* arr , int len){
    int temp=0,j=1;
    for (size_t i = 1; i <len ; i++)
    { 
        temp=*(arr+i);
        while(*(arr+i-j)>temp){
            j++;
            if(j>i){
            break;
            }
        }
            j--;
            shift_element((arr+i-j),j);
            *(arr+i-j)=temp;
            j=1;
    }
}
int main(){
    int arr[N]={0};
    for (size_t i = 0; i < N; i++)
    {
        scanf("%d",(arr+i));
    }
    insertion_sort(arr,N);
    for (size_t i = 0; i < N; i++)
    {
        if(i<N-1){
        printf("%d,",*(arr+i));
        }else{
        printf("%d\n",*(arr+i));
        }
    }
    return 0;
}