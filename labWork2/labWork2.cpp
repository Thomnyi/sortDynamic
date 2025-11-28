#include <iostream>

void pointerFiller(int **arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
}
void arrayFiller(int **arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int e = 0; e < n; e++) {
			arr[i][e] = rand() % (2 * n + 1) - n;
		}
	}
}
void sortingAlg(int** arr, int n) {
	int* sumArr = new int[n];
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int e = 0; e < n; e++) {
			sum += arr[i][e];
		}
		sumArr[i] = sum;
	}
	for (int i = 1; i < n; i++) {
		int key = sumArr[i];
		int* pointKey = arr[i];
		int j = i - 1;
		while (j >= 0 && sumArr[j] > key) {
			sumArr[j + 1] = sumArr[j];
			arr[j + 1] = arr[j];
			j--;
		}
		sumArr[j + 1] = key;
		arr[j + 1] = pointKey;

	}
	delete[] sumArr;
}
void displayMatrix(int** arr, int num) {
	for (int i = 0; i < num; i++) {
		std::cout << std::endl;
		for (int e = 0; e < num; e++) {
			std::cout << arr[i][e] << " ";
		}
	}
}
int main()
{
	int userNumber;
	std::cout << "Please enter a number of elements in the array: ";
	std::cin >> userNumber;
	std::cout << std::endl;
	while (userNumber < -15) {
		std::cout << std::endl;
		std::cout << "The number cannot be < -15. Please, try one more time: ";
		std::cin >> userNumber;
	}
	userNumber += 15;
	int** arr = new int*[userNumber];
	pointerFiller(arr, userNumber);
	arrayFiller(arr, userNumber);
	std::cout << "Unordered array: " << std::endl;
	displayMatrix(arr, userNumber);
	std::cout << std::endl;
	sortingAlg(arr, userNumber);
	std::cout << std::endl;
	std::cout << "Ordered array: " << std::endl;
	displayMatrix(arr, userNumber);
	std::cout << std::endl;
	for (int i = 0; i < userNumber; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}