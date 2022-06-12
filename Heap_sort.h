void heapRebuild(int start, int arr[], int n, unsigned long long &comparison)
{
    int leftChild = 2 * start + 1;
    if ((++comparison)&&(leftChild >= n))
        return;
    int largerChild = leftChild;
    int rightChild = 2 * start + 2;
    if ((++comparison)&&(rightChild < n))
    {
        if ((++comparison)&&(arr[rightChild] > arr[largerChild]))
            largerChild = rightChild;
    }
    if ((++comparison)&&(arr[start] < arr[largerChild]))
    {
        swap(arr[largerChild], arr[start]);
        heapRebuild(largerChild, arr, n,comparison);
    }
}
void heapSort(int arr[], int n, unsigned long long &comparison)
{
    comparison=0;
    for (int index = (n - 1) / 2;(++comparison)&& (index >= 0); index--)
        heapRebuild(index, arr, n,comparison);
    swap(arr[0], arr[n - 1]);
    int heapSize = n - 1; 
    while ((++comparison)&&(heapSize > 1))
    {
        heapRebuild(0, arr, heapSize,comparison);
        heapSize--;
        swap(arr[0], arr[heapSize]);
    }
}

//-----No count

void heapRebuild(int start, int arr[], int n)
{
    int leftChild = 2 * start + 1;
    if (leftChild >= n)
        return;
    int largerChild = leftChild;
    int rightChild = 2 * start + 2;
    if (rightChild < n)
    {
        if (arr[rightChild] > arr[largerChild])
            largerChild = rightChild;
    }
    if (arr[start] < arr[largerChild])
    {
        swap(arr[largerChild], arr[start]);
        heapRebuild(largerChild, arr, n);
    }
}
void heapSort(int arr[], int n)
{
    for (int index = (n - 1) / 2; index >= 0; index--)
        heapRebuild(index, arr, n);
    swap(arr[0], arr[n - 1]);
    int heapSize = n - 1; 
    while (heapSize > 1)
    {
        heapRebuild(0, arr, heapSize);
        heapSize--;
        swap(arr[0], arr[heapSize]);
    }
}
