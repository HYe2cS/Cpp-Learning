void sort(STU* s, int n)
{
    STU t;
    int i, j, max;
    for (i = 0; i < n - 1; i++)
    {
        max = i;
        for (j = i + 1; j < n; j++)
        {
            if (s[j].total > s[max].total)max = j;
        }
        if (max != i)
        {
            t = s[max];
            s[max] = s[i];
            s[i] = t;
        }
    }
}
for (i = 0; i < 9; i++)
{
    min = i;
    for (j = i + 1; j < 10; j++)
    {
        if (a[j] < a[min])min = j;
    }
    if (min != i)
    {
        t = a[i];
        a[i] = a[min];
        a[min] = t;
    }
}