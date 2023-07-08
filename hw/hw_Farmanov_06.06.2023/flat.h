#include <iostream>

class Flat {
    int32_t area{};
    int32_t price{};

public:
    Flat() = default;

    friend std::istream& operator >> (std::istream& stream, Flat& newFlat) {
        std::cout << "Area: ";
        stream >> newFlat.area;
        std::cout << "Price: ";
        stream >> newFlat.price;

        return stream;
    }

    friend std::ostream& operator << (std::ostream& stream, const Flat& newFlat) {
        return stream << "Area: " << newFlat.area << '\t' << "Price: " << newFlat.price;
    }

    Flat operator = (Flat otherFlat) {
        this->area = otherFlat.area;
        this->price = otherFlat.price;
    }

    friend bool operator == (Flat& flat_1, Flat& flat_2) {
        return flat_1.area == flat_2.area;
    }

    friend bool operator > (Flat& flat_1, Flat& flat_2) {
        return flat_1.price > flat_2.price;
    }
    
    friend bool operator < (Flat& flat_1, Flat& flat_2) {
        return flat_1.price < flat_2.price;
    }
};