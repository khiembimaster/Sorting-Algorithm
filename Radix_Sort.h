void radixSort(int arr[], int n, unsigned long long &count_comp){
    count_comp = 0;
    int max_val = arr[0]; // get maximum value in the array
    for (int i = 1; (++count_comp)&&(i < n); ++i)
        if ((++count_comp)&&(arr[i] > max_val)) max_val = arr[i];

    int digits = 0, div; // find the maximum number of digits
    do{
        digits++;
        div = max_val / pow(10, digits);
    } while ((++count_comp)&&(div > 0));

    int **tempArr = new int*[10]; // declare variables for temp store
    for (int i = 0;(++count_comp)&&(i < 10); ++i)
        tempArr[i] = new int[n];
    int tempCount[10];

    // form groups of numbers and combine groups
    for (int i = 0;(++count_comp)&&( i < digits) ; ++i) {
        int exp = pow(10, i);
        for (int j = 0; (++count_comp)&&(j < 10); ++j) // reset the counting
            tempCount[j] = 0;
        for (int j = 0; (++count_comp)&&(j < n); ++j) { // form groups
            int idx = (arr[j] / exp) % 10;
            tempArr[idx][tempCount[idx]++] = arr[j];
        }
        int idx = 0; // combine groups
        for (int j = 0; (++count_comp)&&(j < 10); ++j)
            for (int k = 0; (++count_comp)&&(k < tempCount[j]); ++k)
                arr[idx++] = tempArr[j][k];
    }
}