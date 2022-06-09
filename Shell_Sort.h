void shellSort(int arr[], int size, int &comparison)
{
    comparison = 0;
    // Start with a big gap, then reduce the gap
    for (int gap = size/2; gap > 0; gap /= 2)
    {
        comparison++;
        for (int i = gap; i < size; i += 1)
        {
            comparison++;
            int temp = arr[i];
            int j;           

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comparison = comparison + 2; //
                arr[j] = arr[j - gap];
            }
      
            arr[j] = temp;
        }
    }
}