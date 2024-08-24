#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    float average;
    int i = 0;

start:
    if (i >= n)
    {
        goto end;
    }
    sum += arr[i];
    i++;
    goto start;

end:
    if (n != 0)
    {
        average = (float)sum / n;
    }
    else
    {
        goto error;
    }
    printf("Average: %f\n", average);
    return 0;

error:
    printf("Error: Division by zero\n");
    return 1;
}
