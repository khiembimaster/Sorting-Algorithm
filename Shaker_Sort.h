void shakerSort(int a[], int n, unsigned long long &comparison) {
	int first = 0; //First element in the array
	int last = n - 1; //Last element in the array
	int k = 0;

	while (++comparison && first < last)
	{
        //Bring the largest value to the rightside of the array
		for (int i = first; ++comparison && i < last; i++)
		{
			if (++comparison && a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		last = k;

        //Bring the smallest value to the leftside of the array
		for (int i = last; ++comparison && i > first; i--)
		{
			if (++comparison && a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		first = k;
	}
}