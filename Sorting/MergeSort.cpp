#include <iostream>

using namespcae std;

void merge(int *arr, int low, int mid, int high)
{
    int ar[high-low +1];
    int i = low, j=mid+1, k=0;

    while(i<mid+1 && j<=high)
    {
        if(arr[i] < arr[j])
            ar[k++] = arr[i++];
        else
            ar[k++] = arr[j++];
    }
    while(i<mid+1)
        ar[k++] = arr[i++];
    while(j<=high)
        ar[k++] = arr[j++];

    for( i=0; i<k; i++)
        arr[low+i] = ar[i];
}

void mergeSort(int *arr, int low, int high)
{
    if(low>=high)
        return;

    int mid = low+(high-low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);

    merge(arr, low, mid, high);
}

int main()
{
    int n;
    int *arr;
    cin>>n;
    arr = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    mergeSort(arr, 0, n-1);
    return 0;
}