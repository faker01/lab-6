#include <iostream>
#include "Header.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    int** matrix;
    int n;
    matrix = input(&n);

    int minn = min(matrix, n);
    int maxx = max(matrix, n);

    int sum_min = sum(minn);
    int sum_max = sum(maxx);

    if (sum_min == sum_max) 
    {
        sort(matrix, n);
    }
    output(matrix, n);

    return 0;
}
