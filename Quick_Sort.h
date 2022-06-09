//Biến "comparison" ban đầu sẽ được truyền giá trị là 0
void quickSort(int arr[], int first, int last, int &comparison = 0) {
    int pivot = arr[(first + last) / 2];
    int i = first, j = last;

    do {
        while (arr[i] < pivot) { //count as one comparison
            comparison++; 
            i++;
        }

        while (arr[j] > pivot) { //count as one comparison
            comparison++; 
            j--;
        }

        if (i <= j) { //count as one comparison
            comparison++; 
            swap(arr[i], arr[j]);
            i++; j--;
        }
    } while (i < j && ++comparison); //count as one comparison

    if (first < j) { //count as one comparison
        comparison++;
        QuickSort(arr, first, j, comparison);
    }

    if (i < last) { //count as one comparison
        comparison++;
        QuickSort(arr, i, last, comparison);
    }
}