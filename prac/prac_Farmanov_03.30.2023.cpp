#include <iostream>

using namespace std;

const int getLength(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}


void append(char *&oldStr, char *newStr) {
    int oldLength = getLength(oldStr);
    int newLength = getLength(newStr);
    int totalLength = oldLength + newLength + 1;

    char *tmp = new char[oldLength]{};

    for (int i = 0; i < oldLength; ++i) {
        tmp[i] = oldStr[i];
    }

    delete[] oldStr;

    oldStr = new char[totalLength]{};

    for (int i = 0; i < oldLength; ++i) {
        oldStr[i] = tmp[i];
    }

    for (int i{oldLength}, j{}; i < totalLength - 1; ++i, ++j) {
        oldStr[i] = newStr[j];
    }
}


void edit(char *&oldStr, char *newStr){
	int newLength = getLength(newStr);

	delete[] oldStr;
	oldStr = new char[newLength]{};

	for (size_t i = 0; i < getLength(newStr); ++i) {
		*(oldStr + i) = *(newStr + i);
	}
}


void prepend(char *&oldStr, char *newStr) {
	int newLength = getLength(newStr);
	int oldLength = getLength(oldStr);
	int totalLength = getLength(oldStr) + getLength(newStr) + 1;

	char* tmp = new char[oldLength];
	for (size_t i = 0; i < oldLength; ++i)
		*(tmp + i) = *(oldStr + i);

	delete[] oldStr;
	oldStr = new char[totalLength]{};

	for (size_t i = 0; i < newLength; ++i) {
		*(oldStr + i) = *(newStr + i);
	}
	for (size_t j = newLength, k = 0; j < totalLength - 1; ++j, ++k) {
		*(oldStr + j) = *(tmp + k);
	}
}


int main() {
	char *name = new char[20]{};
    char *surName = new char[20]{};

    bool isExit = false;
    int choice{};

    cout << "Enter your name: ";
    cin.getline(name, 20);

    cout << "Enter your surname: ";
    cin.getline(surName, 20);

    cout << "Hello, " << name << " " << surName << endl;

    while (!isExit) {
        char *newString{};

		cout << "Enter choice: \n"
                "1. Append\n"
                "2. Edit\n"
                "3. Prepend\n"
                "4. Exit\n"
                "> ";

        cin >> choice;

        switch (choice) {
            case 1:

                cin.ignore();
                newString = new char[20]{};

                cout << "Enter new string: ";
                cin.getline(newString, 20);
                append(name, newString);

                cout << "New string: " << name << endl;
                break;

            case 2:
				cin.ignore();
				newString = new char[20]{};

				cout << "Enter string to replace: ";
				cin.getline(newString, 20);
				edit(name, newString);

				cout << "New string: " << name << endl;

                break;

            case 3:
				cin.ignore();
				newString = new char[20]{};

				cout << "Enter new string: ";
				cin.getline(newString, 20);
				prepend((name), newString);

				cout << "New string: " << name << endl;

                break;

            case 4:
                isExit = true;
                break;
        }

    }


    return 0;
}
