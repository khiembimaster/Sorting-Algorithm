void insertionSort(int arr[], int n, unsigned long long &count_compare)
{
    int i, key, j;
    for (i = 1; (++count_compare) && (i < n); i++)
    {
        key = arr[i];
        j = i - 1;

                while ((++count_compare) && (j >= 0) && (++count_compare) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}