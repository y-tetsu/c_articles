#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    float average;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (n != 0)
    {
        average = (float)sum / n;
        printf("Average: %f\n", average);
    }
    else
    {
        printf("Error: Division by zero\n");
    }
    return 0;
}
