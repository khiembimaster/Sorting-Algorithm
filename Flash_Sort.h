void flashSort(int arr[], int n, int &count_comp){
//CLASSIFICATION
    int m = 0.45 * float(n);
    //Create vector l
    int *l = new int[m];
    for(int i = 0;(++count_comp) && (i < m); i++){
        l[i] = 0;
    }
    //Find max and min
    int max = arr[0], min = arr[0]; 
    for(int i = 1;(++count_comp) && (i < n); i++){
        if((++count_comp) && (arr[i] < min)) min = arr[i];
        if((++count_comp) && (arr[i] > max)) max = arr[i];
    }
    //Store numbers of elements in each class l[k]
    for(int i = 0;(++count_comp) && (i < n); i++){
        int k = (m-1)*(arr[i]-min)/(max-min);
        l[k]++;
    }
    //// accumulate sum of l[k]
    for(int k = 1;(++count_comp) && (k < m); k++)
        l[k] = l[k] + l[k-1];
    
//PERMUTATION
    int hold = arr[0];
    int move = 0;
    int flash = 0;
    int k = 0;
    int t = 0;
    int j = 0;

    while((++count_comp) && (move < n-1)){
        while((++count_comp) && (j > (l[k] - 1))){
            j++;
            k = (m-1)*(arr[j]-min)/(max-min);
        }
        flash = arr[j];
        while((++count_comp) && (j != l[k])){
            k = (m-1)*(arr[j]-min)/(max-min);
            hold = arr[t = --l[k]];
            arr[t] = flash;
            flash = hold;
            move++;
        }
    }

//INSERTION SORT
    for(int i = 1;(++count_comp) && (i < n); i++){
        int p = arr[i];
        int j = i-1;
        while(((++count_comp) && (j >= 0)) && ((++count_comp) && (arr[j] > p))){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = p;
    }
    delete l;
}