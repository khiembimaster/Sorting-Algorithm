void merge(int arr[], int l, int m, int r, unsigned long long &comparision) {
    comparision=0;
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L;
    L = new int[n1];
    int* R;
    R = new int[n2];
    for (i = 0;(++comparision)&&( i < n1); i++) {
        L[i] = arr[l + i];
    }
    for (j = 0;(++comparision)&&( j < n2); j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while ((++comparision)&&(i < n1)&&(++comparision)&&( j < n2)) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while ((++comparision)&&(i < n1)) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while ((++comparision)&&(j < n2)) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r, unsigned long long &comparision) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m,comparision);
        mergeSort(a, m + 1, r,comparision);
        merge(a, l, m, r,comparision);
    }
}