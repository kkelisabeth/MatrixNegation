/**
* \brief	This program does several manipulations with matrices.
* \details	This program is used to:
*									1) Enter data to the matrix in the range (-10.5, 7.5);
*									2) Negate all elements of the matrix;
*									3) Print the matrix.
* \author	Kozlova Elizabeth Paula
* \version	0.1
* \date		01/06/2022
*/

#include <iostream>
#include <cassert>
using namespace std;
//constant values
const int MAX1 = 4;
const int MAX2 = 3;
//function prototypes
void menu();
void EnterData(double[MAX2][MAX1]);
void Negation(double[MAX2][MAX1]);
void PrintMatrix(const double[MAX2][MAX1]);
int Counter(const double[MAX2][MAX1], int);
/**
* Function <code>main</code> calls different functions according to the user's choice.
* <BR>
* @return Returns <code>0</code> if the the program runs successfully.
*/
int main()
{
	int choice;
	int counter = 0;
	double matrix[MAX2][MAX1];
	menu();
	cout << "Enter your choice: ";
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			EnterData(matrix);
			break;
		case 2:
			Negation(matrix);
			break;
		case 3:
			PrintMatrix(matrix);
			break;
		case 4:
			cout << "There are " << Counter(matrix, counter) << " elements with value 2.5." << endl;
			break;
		default:
			cout << "Invalid choice." << endl;
			break;
		}
		menu();
		cout << "Enter your choice: ";
		cin >> choice;
	}

	return 0;
}
/**
* Function <code>menu</code> prints the menu of the program.
* <BR>
*/
void menu()
{
	cout << "\tMENU" << endl
		<< "1) Enter data in matrix " << endl
		<< "2) Negate all elements " << endl
		<< "3) Show data in matrix" << endl
		<< "4) Count number of elements with value 2.5" << endl
		<< "5) Exit" << endl;
}
/**
* Function <code>EnterData</code> asks the user to input all the values of the matrix.
* <BR>
* @param matrix The array to be filled with values.
*/
void EnterData(double matrix[MAX2][MAX1])
{
	for (int i = 0; i < MAX2; i++)
	{
		for (int j = 0; j < MAX1; j++)
		{
			cout << "Enter value: ";
			cin >> matrix[i][j];
			while (matrix[i][j] < -10.5 || matrix[i][j] > 7.5)
			{
				cout << "Invalid value. Please, enter again: ";
				cin >> matrix[i][j];
			}
		}
	}
}
/**
* Function <code>Negation</code> negates all the elements of the matrix.
* <BR>
* @param matrix The array which elements will be negotiated.
*/
void Negation(double matrix[MAX2][MAX1])
{
	for (int i = 0; i < MAX2; i++)
	{
		for (int j = 0; j < MAX1; j++)
		{
			matrix[i][j] *= -1;
		}
	}
}
/**
* Function <code>PrintMatrix</code> prints the matrix.
* <BR>
* @param matrix The array which elements will be displayed.
*/
void PrintMatrix(const double matrix[MAX2][MAX1])
{
	for (int i = 0; i < MAX2; i++)
	{
		for (int j = 0; j < MAX1; j++)
		{
			cout << matrix[i][j] << "   ";
		}
		cout << endl;
	}
}
/**
* Function <code>Counter</code> counts number of elements with value 2.5 in the matrix.
* <BR>
* @param matrix The array to be scanned.
* @param counter An integer value which will count the elements with value 2.5.
* @return Returns counter.
*/
int Counter(const double matrix[MAX2][MAX1], int counter)
{
	assert(counter == 0); //testing pre-condition
	for (int i = 0; i < MAX2; i++)
	{
		for (int j = 0; j < MAX1; j++)
		{
			if (matrix[i][j] == 2.5)
				counter++;
		}
	}

	return counter;
}