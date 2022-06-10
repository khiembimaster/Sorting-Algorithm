void selectionSort(int arr[], int n, unsigned long long &count_compare)
{
    int i, j, min_idx;

    for (i = 0; ++count_compare && i < n - 1; i++)
    {

        min_idx = i;

        for (j = i + 1; ++count_compare && j < n; j++)
            if ((++count_compare) && (arr[j] < arr[min_idx]))
                min_idx = j;

        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}