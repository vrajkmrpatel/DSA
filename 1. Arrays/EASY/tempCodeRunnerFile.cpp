 d = d % n;
    int temp[d];
    for (int i = 0; i < d; i++) // O(D) TIME
    {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++) // O(N - D) TIME
    {
        arr[i - d] = arr[i];
    }

    for (int i = n - d; i < n; i++) // O(D) time
    {
        arr[i] = temp[i - (n - d)];
    }