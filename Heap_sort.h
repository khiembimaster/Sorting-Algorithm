void heapRebuild(int start, int arr[], int n, unsigned long long &comparision)
{
    int leftChild = 2 * start + 1;
    if ((++comparision)&&(leftChild >= n))
        return;
    int largerChild = leftChild;
    int rightChild = 2 * start + 2;
    if ((++comparision)&&(rightChild < n))
    {
        if ((++comparision)&&(arr[rightChild] > arr[largerChild]))
            largerChild = rightChild;
    }
    if ((++comparision)&&(arr[start] < arr[largerChild]))
    {
        swap(arr[largerChild], arr[start]);
        heapRebuild(largerChild, arr, n,comparision);
    }
}
void heapSort(int arr[], int n, unsigned long long &comparision)
{
    comparision=0;
    for (int index = (n - 1) / 2;(++comparision)&& (index >= 0); index--)
        heapRebuild(index, arr, n,comparision);
    swap(arr[0], arr[n - 1]);
    int heapSize = n - 1; 
    while ((++comparision)&&(heapSize > 1))
    {
        heapRebuild(0, arr, heapSize,comparision);
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