//Ã°ÅÝ
for (i = 0; i < n - 1; i++)
	for (j = 0; j < n - 1 - i; j++)
		if (a[j] > a[j + 1])
		{
			t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
		}
//Ñ¡Ôñ
for (i = 0; i < n - 1; i++)
{
	min = i;
	for (j = i + 1; j < n; j++)
		if (a[j] < a[min])min = j;
	if (min != i)
	{
		t = a[i];
		a[i] = a[min];
		a[min] = t;
	}
}