#include <iostream>

using namespace std;

class Matrix
{
public:
	Matrix(int n, int m)
	{
		m_n = n;
		m_m = m;
		m_mat = new double* [m_n];
		for (int i = 0; i < m_n; i++)
		{
			m_mat[i] = new double[m_m];
		}
	}

	// Copy constructor
	Matrix(const Matrix& mat)
	{
		m_n = mat.m_n;
		m_m = mat.m_m;
		m_mat = new double* [m_n];
		for (int i = 0; i < m_n; i++)
		{
			m_mat[i] = new double[m_m];
		}
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				m_mat[i][j] = mat.m_mat[i][j];
			}
		}
	}
	// Assignment
	Matrix& operator=(const Matrix& mat)
	{
		m_n = mat.m_n;
		m_m = mat.m_m;

		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				m_mat[i][j] = mat.m_mat[i][j];
			}
		}
		return *this;
	}
	// Addition operator
	Matrix operator+(const Matrix& mat)
	{
		Matrix tmp(2, 3);
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
			}
		}
		return tmp;
	}
	// Subtraction operator
	Matrix operator-(const Matrix& mat)
	{
		Matrix tmp(2, 3);
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
			}
		}
		return tmp;
	}
	// Multiplication operator
	Matrix operator*(const Matrix& mat)
	{
		Matrix tmp(m_n, mat.m_m);

		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < mat.m_m; j++)
			{
				tmp.m_mat[i][j] = 0;
				for (int k = 0; k < mat.m_n; k++)
				{
					tmp.m_mat[i][j] += m_mat[i][k] * mat.m_mat[k][j];
				}
			}
		}
		return tmp;
	}

	~Matrix()
	{
		for (int i = 0; i < m_n; i++)
		{
			delete[] m_mat[i];
		}
		delete m_mat;
	}

	double DET()
	{
		if ((m_n != m_m) && (m_n != 2) && (m_n != 3))
		{
			cout << "This format is not supported. " << endl;
		}

		else if (m_n == 2)
		{
			double det = 0;
			det = m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
			return det;
		}

		else if (m_n == 3)
		{
			double det = 0;
			det = m_mat[0][0] * m_mat[1][1] * m_mat[2][2] + m_mat[0][1] * m_mat[1][2] * m_mat[2][0]
				+ m_mat[1][0] * m_mat[2][1] * m_mat[0][2] - m_mat[2][0] * m_mat[1][1] * m_mat[0][2] -
				m_mat[2][1] * m_mat[1][2] * m_mat[0][0] - m_mat[1][0] * m_mat[0][1] * m_mat[2][2];
			return  det;
		}
	}

	Matrix reverse()
	{
		int Det = DET();
		Matrix tmp(m_n, m_m);
		if ((m_n == m_m && m_n == 2) || (m_n == m_m && m_n == 3))
		{
			if (Det == 0)
			{
				cout << "DET = 0. Inverse Matrix does not exist. " << endl;
			}
			else
			{
				if (m_n == 2)
				{
					tmp.m_mat[0][0] = m_mat[1][1] / Det;
					tmp.m_mat[0][1] = -m_mat[0][1] / Det;
					tmp.m_mat[1][0] = -m_mat[1][0] / Det;
					tmp.m_mat[1][1] = m_mat[0][0] / Det;
					return tmp;
				}
				else if (m_n == 3)
				{
					tmp.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) / Det;
					tmp.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2]) / Det;
					tmp.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[2][0] * m_mat[1][1]) / Det;
					tmp.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[2][1] * m_mat[0][2]) / Det;
					tmp.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[2][0] * m_mat[0][2]) / Det;
					tmp.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[2][0] * m_mat[0][1]) / Det;
					tmp.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[1][1] * m_mat[0][2]) / Det;
					tmp.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[1][0] * m_mat[0][2]) / Det;
					tmp.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]) / Det;
					return tmp;
				}
			}
		}
		else
			std::cout << "This format is not supported. " << std::endl;
	}

	Matrix transposition()
	{
		Matrix tmp(m_m, m_n);
		for (int i = 0; i < m_m; i++)
		{
			for (int j = 0; j < m_n; j++)
			{
				tmp.m_mat[i][j] = m_mat[j][i];
			}            

		}
		return tmp;
		
	}

	friend istream& operator>>(istream& in, Matrix& mat);
	friend ostream& operator<<(ostream& out, const Matrix& mat);
private:
	int m_n, m_m;
	double** m_mat;
};
istream& operator>>(istream& in, Matrix& mat)
{
	for (int i = 0; i < mat.m_n; i++)
	{
		for (int j = 0; j < mat.m_m; j++)
		{
			in >> mat.m_mat[i][j];
		}
	}
	return in;
}
std::ostream& operator<<(std::ostream& out, const Matrix& mat)
{
	out << "Matrix " << mat.m_n << "x" << mat.m_m << std::endl;
	for (int i = 0; i < mat.m_n; i++)
	{
		for (int j = 0; j < mat.m_m; j++)
		{
 			out << mat.m_mat[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}

int main()
{

	int n, m = 0;
	cout << "Enter the number of rows and columns" << endl;
	cin >> n >> m;

	Matrix A(n, m);
	cout << "Enter Matrix" << endl;
	cin >> A;
	cout << "A: " << endl << A << endl;
	cout << "Det A: " << endl << A.DET() << endl;
	cout << "Reverse A: " << endl << A.reverse() << endl;
	cout << "Enter the number of rows and columns for transposition" << endl;
	cin >> n >> m;
	Matrix B(n, m);
	cout << "Enter Matrix" << endl;
	cin >> B; 
	cout << " Transpositions Matrix B: " << endl << B.transposition() << endl;

	cout << "A * B : " << endl << A * B << endl;
	
	return 0;
}