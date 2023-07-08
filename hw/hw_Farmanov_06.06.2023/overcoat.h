#include <iostream>

enum coatType {
    COVERT = 1,
    POLO,
    TRENCH
};

class Overcoat {
private:
    coatType type;
    int32_t price{};

public:
    Overcoat() = default;


    friend std::istream& operator >> (std::istream& stream, Overcoat& newCoat) {
        int16_t inputType{};

        std::cout
            << "Choose overcoat type: " << '\n'
            << "1. Covert" << '\n'
            << "2. Polo" << '\n'
            << "3. Trench" << '\n'
            << "> ";
        stream >> inputType;
        newCoat.type = coatType(inputType);

        std::cout << "Enter price: ";
        stream >> newCoat.price;

        return stream;
    }

    Overcoat operator = (Overcoat otherCoat) {
        this->price = otherCoat.price;
        this->type = otherCoat.type;
    }

    friend std::ostream& operator << (std::ostream& stream, const Overcoat& newCoat) {
        if (newCoat.type == COVERT)
            stream << "Type: Covert";

        else if (newCoat.type == POLO)
            stream << "Type: Polo";
        
        else if (newCoat.type == TRENCH)
            stream << "Type: Trench";

        stream << '\t';

        stream << "Price: " << newCoat.price;

        return stream;
    }

    friend bool operator == (Overcoat& coat_1, Overcoat& coat_2) {
        return coat_1.price == coat_2.price;
    }

    friend bool operator > (Overcoat& coat_1, Overcoat& coat_2) {
        if (coat_1.type == coat_2.type)
        {
            return coat_1.price > coat_2.price;
        }
        else
        {
            std::cout << "Error";
        }
           
    }

    friend bool operator < (Overcoat& coat_1, Overcoat& coat_2) {
        if (coat_1.type == coat_2.type)
        {
            return coat_1.price < coat_2.price;
        }
        else
        {
            std::cout << "Error";
        }
    }


    std::string get_type() {
        if (type == COVERT)
            return "Covert";

        else if (type == POLO)
            return "Polo";
        
        else if (type == TRENCH)
            return "Trench";
    }

};