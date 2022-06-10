void shellSort(int arr[], int size, int &comparison)
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