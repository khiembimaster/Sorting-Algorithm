void countingSort(int arr[], int n, unsigned long long& count_comp){ 
    count_comp = 0;
    // u is the maximum value
    int u = 0;
    for(int i = 0;(++count_comp) && (i < n); i++)
        if((++count_comp) && (u < arr[i])) u = arr[i];
    
    // perform distribution counting
    int *f = new int[u+1] {0};
    for (int i = 0;(++count_comp) && (i < n); i++)
        f[arr[i]] ++;
    // accumulate sum of frequencies
    for (int i = 1;(++count_comp) && (i <= u); i++)
        f[i] = f[i - 1] + f[i];
    // distribute values to their final positions
    int *b = new int[n];
    for (int i = n - 1;(++count_comp) && (i >= 0); i--) {
        b[f[arr[i]]-1] = arr[i];
        f[arr[i]]--;
    }
    for (int i = 0;(++count_comp) && (i < n); i++)
        arr[i] = b[i];
}