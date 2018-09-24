#include <iostream>

using namespace std;

int getSize() {
	int size;
	cout << "Enter size of Matrix (2 or 3): ";
	cin >> size;

	return size;
}

int** createArr(int size) {
	int** arr = new int*[size];
	for (int i = 0; i < size; ++i)
		arr[i] = new int[size];

	return arr;
}

void deleteArr(int** arr, int size) {
	for(int i = 0; i < size; ++i)
		delete [] arr[i];
	delete [] arr;
}

void readMatrix(int** arr, int size) {
	int input;
	cout << "Enter the numbers for the matrix:" << endl;
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			cin >> input;
			arr[i][j] = input;
		}
	}
}

void printArr(int** arr, int size) {
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int determinant(int** arr, int size) {
	if(size == 2)
		return arr[0][0]*arr[1][1] - arr[0][1]*arr[1][0];
	else
		return  ( arr[0][0] *
				(arr[1][1]*arr[2][2] - arr[1][2]*arr[2][1]) ) -
				( arr[0][1] *
				(arr[1][0]*arr[2][2] - arr[2][0]*arr[1][2]) ) +
				( arr[0][2] *
				(arr[1][0]*arr[2][1] - arr[2][0]*arr[1][1]) );
}

void printDet(int det) {
	cout << "determinant is " << det << endl;
}

void lab1() {
	int size = getSize();
	int **arr = createArr(size);

	readMatrix(arr, size);
	printArr(arr, size);
	printDet(determinant(arr, size));
	deleteArr(arr, size);
}

int main() {

	lab1();

	return 0;
}