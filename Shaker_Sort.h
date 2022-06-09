void shakerSort(int a[], int n, int &comparison) {
	int first = 0; //First element in the array
	int last = n - 1; //Last element in the array
	int k = 0;

	while (first < last && ++comparison)
	{
        //Bring the largest value to the rightside of the array
		for (int i = first; i < last; i++)
		{
            comparison++;
			if (a[i] > a[i + 1])
			{
                comparison++;
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		last = k;

        //Bring the smallest value to the leftside of the array
		for (int i = last; i > first; i--)
		{
            comparison++;
			if (a[i] < a[i - 1])
			{
                comparison++;
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		first = k;
	}
}