//5. Обчислити значення AD - DA, де A, D – квадратні матриці розмірності n * n

#include <iostream>
using namespace std;
const int N = 2;

int multiplay_arrays(int A[N][N], int D[N][N], int C[N][N]);
int generate_arrays(int n, int);
void output_array(const char*, int A[N][N]);
int difference(int C[N][N], int F[N][N], int H[N][N]);

int main()
{
	int n = N;
	int A[N][N], D[N][N], H[N][N];
	int C[2][2] = { {0, 0}, {0, 0} };
	int F[2][2] = { {0, 0}, {0, 0} };
	generate_arrays(n, A[n][n]);
	output_array("Generated array ", A);
	generate_arrays(n, D[n][n]);
	output_array("Generated array ", D);
	multiplay_arrays(A, D, C);
	multiplay_arrays(D, A, F);
	difference(A, D, H);

	return 0;
}

int generate_arrays(int n, int A[N][N])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand() % 100 - 50;
		}
	}
	return 0;
}

int multiplay_arrays(int A[N][N], int D[N][N], int C[N][N])
{

	cout << "\nArray of multiplay " << A << " * " << D << "\n";
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int f = 0; f < N; f++)
			{
				C[i][j] += A[i][f] * D[f][j];
			}
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

int difference(int C[N][N], int F[N][N], int H[N][N])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; j++)
		{
			H[i][j] = C[i][j] - F[i][j];
			output_array("Array of subtraction", H);
		}
	}
	return 0;
}

void output_array(const char* msg, int A[N][N])
{
	cout << msg << ": ";
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}