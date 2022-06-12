void merge(int arr[], int l, int m, int r, unsigned long long &comparison) {
    comparison=0;
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L;
    L = new int[n1];
    int* R;
    R = new int[n2];
    for (i = 0;(++comparison)&&( i < n1); i++) {
        L[i] = arr[l + i];
    }
    for (j = 0;(++comparison)&&( j < n2); j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while ((++comparison)&&(i < n1)&&(++comparison)&&( j < n2)) {
        if (++comparison && L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
           
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while ((++comparison)&&(i < n1)) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while ((++comparison)&&(j < n2)) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r, unsigned long long &comparison) {
    if (++comparison && l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m,comparison);
        mergeSort(a, m + 1, r,comparison);
        merge(a, l, m, r,comparison);
    }
}

// No count
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L;
    L = new int[n1];
    int* R;
    R = new int[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while ((i < n1) && (j < n2)) {
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
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
