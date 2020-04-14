#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<int>> adjugateMatrix(vector<vector<int>> matrix,int i,int j)
{
	vector<vector<int>> adjugate;

	vector<int> row;
	for(int k = 0; matrix.size() > k; k++)
	{
		if(k != i)
		{
			for(int n = 0; matrix.size() > n; n++)
			{
				if(n != j)
				{
					row.push_back(matrix[k][n]);
				}
			}

			adjugate.push_back(row);

			row.clear();
		}
	}

	return adjugate;
}
int determinant(vector<vector<int>> matrix)
{
	if(matrix.size() == 1)
	{
		return matrix[0][0];
	}

	else if(matrix.size() == 2)
	{
		return matrix[0][0] * matrix[1][1] - matrix[0][1]*matrix[1][0];
	}

	int i = 0;
	int det = 0;

	int sign = 1;

	while(matrix.size() > i)
	{
		if(i%2 == 0){sign = 1;}
		else{sign = -1;}

		vector<vector<int>> adjugate;

		adjugate = adjugateMatrix(matrix,0,i);
		det += sign * matrix[0][i] * determinant(adjugate);

		i++;
	}

	return det;
}

int main()
{
	ifstream f;
	f.open("matrix.txt");

	int size = 0;
	
	f >> size;

	vector<vector<int>> matrix; 

	int num;
	int j = 0;

	vector<int> row;
	while(f >> num)
	{
		row.push_back(num);
		j++;

		if(j == size)
		{
			matrix.push_back(row);
			row.clear(); 
			j = 0;
		}
	}

	cout << "Determinant: " << determinant(matrix);

	return 0;
}