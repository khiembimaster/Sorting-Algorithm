void bubbleSort(int arr[], int n, unsigned long long &count_compare)
{
    int i, j;

    for (i = 0; (++count_compare) && i < n - 1; i++)
        for (j = 0; (++count_compare) && j < n - i - 1; j++)
            if (++count_compare && arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void bubbleSort(int arr[], int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}