#include <cstdio>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b =temp;
}

int partition(int *arr, int low, int high)
{
    int i = low -1;
    for(int j = low; j<high; j++){
        if(arr[j]>arr[high])
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[j]);
    return i;
}

void QuickSort(int *arr, int low, int high)
{
    if( !arr || low>=high)
        return;

    int pivot = partition(arr, low, high);
    QuickSort(arr, low, pivot);
    QuickSort(arr, pivot+1, high);
}

int main()
{
    int n;
    int *arr;
    cin>>n;
    arr = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    QuickSort(arr, 0, n-1);
}