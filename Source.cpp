#include <iostream>
#include <fstream>


int sum(int num)
{
	int sum = 0;
	while (num != 0)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}


int min(int** matrix, int n) 
{
	int min = INT_MAX;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (min > matrix[i][j]) 
			{
				min = matrix[i][j];
			}
		}
	}
	return min;
}


int max(int** matrix, int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max < matrix[i][j])
			{
				max = matrix[i][j];
			}
		}
	}
	return max;
}


void sort(int** matrix, int n) 
{
	for (int k = 0; k < n; k++) 
	{
		for (int i = 1; i < n; i++)
		{
			int str1 = 0;
			int str2 = 0;
			for (int j = 0; j < n; j++) 
			{
				str1 += matrix[i][j];
				str2 += matrix[i - 1][j];
			}
			if (str1 < str2) 
			{
				int* tmp = matrix[i - 1];
				matrix[i - 1] = matrix[i];
				matrix[i] = tmp;
			}
		}
	}
}


int** input(int* n) 
{
	std::ifstream file("file.txt", std::ios::in);
	int** matrix;
	file >> (*n);
	matrix = new int* [(*n)];
	for (int i = 0; i < (*n); i++) 
	{
		matrix[i] = new int[(*n)];
	}
	for (int i = 0; i < (*n); i++) 
	{
		for (int j = 0; j < (*n); j++) 
		{
			file >> matrix[i][j];
		}
	}
	file.close();
	return matrix;
}


void output(int** matrix, int n) 
{
	std::ofstream output("output.txt", std::ios::out);
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			output << matrix[i][j] << " ";
		}
		output << std::endl;
	}
	output.close();
}