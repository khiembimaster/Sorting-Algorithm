void shellSort(int arr[], int size, unsigned long long &comparison)
{
    comparison = 0;
    // Start with a big gap, then reduce the gap
    for (int gap = size/2; ++comparison && gap > 0; gap /= 2)
    {
        comparison++;
        for (int i = gap; ++comparison && i < size; i += 1)
        {
            int temp = arr[i];
            int j;           

            for (j = i; ++comparison && j >= gap && ++comparison && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
      
            arr[j] = temp;
        }
    }
}

void shellSort(int arr[], int size)
{
    // Start with a big gap, then reduce the gap
    for (int gap = size/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i += 1)
        {
            int temp = arr[i];
            int j;           

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
      
            arr[j] = temp;
        }
    }
}