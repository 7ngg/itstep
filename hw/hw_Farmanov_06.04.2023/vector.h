#include <iostream>

template <typename T>
class vector
{
	T* arr{};
	size_t size{};
	size_t capacity{};

public:
#pragma region STRUCTURE

    vector(size_t size) {
        this->capacity = size * 2;
        this->arr = new T[capacity]{};
    }

	vector(std::initializer_list<int> list) {
		this->size = list.size();
		this->capacity = list.size() * 2;
		this->arr = new T[capacity]{};

		for (const T* i = list.begin(); i < list.end(); i++) {
			this->arr[i - list.begin()] = *i;
		}
	}

	~vector() {
		delete[] arr;
	}

#pragma endregion

#pragma region OPERATORS

	friend std::ostream& operator << (std::ostream& stream, const vector& myVector) {
		for (size_t i = 0; i < myVector.size; i++)
		{
			stream << myVector.arr[i] << ' ';
		}

		return stream;
	}

	T& operator [] (size_t index) {
		return this->arr[index];
	}

#pragma endregion

#pragma region FUNCTIONS

	bool overload() {
		if (size == capacity)
		{
			return true;
		}
		return false;
	}

	void expand() {
		T* tmp = new T[size]{};

		for (size_t i = 0; i < size; i++)
		{
			tmp[i] = arr[i];
		}

		delete[] arr;
		this->capacity = size * 2;
		arr = new T[capacity] {};

		for (size_t i = 0; i < size; i++)
		{
			arr[i] = tmp[i];
		}
		
		delete[] tmp;
	}

	bool isEmpty() {
		int32_t counter = 0;

		for (size_t i = 0; i < capacity; i++)
		{
			if (arr[i] == 0)
			{
				counter += 1;
			}
		}

		if (counter == capacity)
		{
			return true;
		}
		else
		{
			return false;
		}
				
	}

	void push_back(T newMember) {
		arr[size] = newMember;
		size += 1;

		if (this->overload())
		{
			this->expand();
		}
		
	}

	void pop_back() {
		arr[size - 1] = 0;
		this->size -= 1;

		if (this->isEmpty())
		{
			std::cout << "No elements left" << std::endl;
		}
	}

	void insert(T newMember, size_t index) {
		T* tmp = new T[size - index + 1]{};

		for (size_t i = 0, j = index; i < size; i++, j++)
		{
			tmp[i] = arr[j];
		}
		
		this->size += 1;
		if (this->overload())
		{
			this->expand();
		}

		this->arr[index] = newMember;

		for (size_t i = index + 1, j = 0; i < size; i++, j++)
		{
			arr[i] = tmp[j];
		}
				
		delete[] tmp;
	}

	size_t get_size() {
		return this->size;
	}

	void clear() {
		delete[] arr;
		arr = new T[capacity]{};
	}

	T* begin() {
		return arr;
	}

	T* end() {
		return (arr + size + 1);
	}

#pragma endregion

};