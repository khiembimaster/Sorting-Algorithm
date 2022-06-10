//Biến "comparison" ban đầu sẽ được truyền giá trị là 0
void quickSort(int arr[], int first, int last, unsigned long long &comparison) {
    int pivot = arr[(first + last) / 2];
    int i = first, j = last;

    do {
        while (++comparison && arr[i] < pivot) i++;
        while (++comparison && arr[j] > pivot) j--;

        if (++comparison && i <= j) { //count as one comparison
            swap(arr[i], arr[j]);
            i++; j--;
        }
    } while (++comparison && i < j); //count as one comparison

    if (++comparison && first < j) quickSort(arr, first, j, comparison);
    if (++comparison && i < last) quickSort(arr, i, last, comparison);
}