#include <iostream>
#include <ctime>

const int start = 0;
const int end = 10;

template <typename T>
T* createArr(const int len);
template <typename T>
void initArr(T* arr, const int len);
template <typename T>
void printArr(T* arr, const int len);


template <typename T>
T findMin(T* arr, const int len){
	T min = *arr;

	for (size_t i = 0; i < len; i++) {
		min = (*(arr + i) < min) ? *(arr + i) : min;
	}

	return min;
}


template <typename T>
T average(T* arr, const int len){
	T sum = 0;

	for (size_t i = 0; i < len; i++){
		sum += *(arr + i);
	}

	return sum / len;
}


template <typename T>
T findMax(T* arr, const int len){
	T max = *arr;

	for (size_t i = 0; i < len; i++) {
		max = (*(arr + i) > max) ? *(arr + i) : max;
	}

	return max;
}


template <typename T>
int factorial(T element, const int len){
	int result = 1;
	int i = static_cast<int>(element);

	while (i > 0){
		result *= i;
		i -= 1;
	}

	return result;
}


template <typename T>
int factorialSum(T* arr, const int len){
	int result = 0;

	for (size_t i = 0; i < len; i++) {
		result += factorial(*(arr + i), len);
	}

	return result;
}


int main(){
	using namespace std;
	srand(time(NULL));
	

	int length = 0;
	cout << "Enter array length: ";
	cin >> length;

	double* A = createArr<double>(length);
	initArr<double>(A, length);
	cout << "Array - ";
	printArr<double>(A, length);

	cout << "Task 1: " << endl;
	cout
		<< '\t' << "Min = "
		<< '\t' << findMin<double>(A, length)
		<< endl;
	
	cout 
		<< '\t' << "Max = "
		<< '\t' << findMax<double>(A, length)
		<< endl;

	cout << "Task 2: " << endl;
	cout << '\t' << "Average = " << average<double>(A, length) << endl; 

	cout << "Task 3: " << endl;
	for (size_t i = 0; i < length; i++){
		cout << '\t' << *(A + i) << "! = " << factorial<double>(*(A + i), length) << endl;
	}

	cout 
		<< "Task 5: " << endl
		<< '\t' << "Sum of all factorials = " << factorialSum<double>(A, length)
		<< endl;

	system("pause");
	delete[] A;
	return 0;
}


template <typename T>
T* createArr(const int len){
	T* arr = new T[len];
	return arr;
}


template <typename T>
void initArr(T* arr, const int len){
	for (size_t t = 0; t < len; t++) {
		*(arr + t) = start + std::rand() % (start - end);
	}
}


template <typename T>
void printArr(T* arr, const int len){
	for (size_t t = 0; t < len; t++) {
		std::cout << *(arr + t) << ' ';
	}
	std::cout << std::endl;
}

