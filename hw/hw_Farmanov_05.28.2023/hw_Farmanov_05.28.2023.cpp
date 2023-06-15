#include <iostream>
#include <stdint.h>
#include <string>


enum components
{
    processor = 1,
    motherboard,
    memory,
    graphics,
    internalStorage,
    powerSupply,
    computerCase
};


void printComponentName(components component) {
    switch (component)
    {
    case processor:
        std::cout << "You are enterting CPU data:" << std::endl;
        break;

    case motherboard:
        std::cout << "You are enterting motherboard data:" << std::endl;
        break;

    case memory:
        std::cout << "You are enterting RAM data:" << std::endl;
        break;
    
    case graphics:
        std::cout << "You are enterting GPU data:" << std::endl;
        break;
    
    case internalStorage:
        std::cout << "You are enterting storage data:" << std::endl;
        break;
    
    case powerSupply:
        std::cout << "You are enterting PSU data:" << std::endl;
        break;
    
    case computerCase:
        std::cout << "You are enterting PC case data:" << std::endl;
        break;
    
    default:
        break;
    }
}


struct defaultClass {
    std::string manufacturer{};
    std::string model{};

    defaultClass(components component) {
        printComponentName(component);

        std::cout << "Enter manufacturer: ";
        std::getline(std::cin, manufacturer);

        std::cout << "Enter model: ";
        std::getline(std::cin, model);
    }

    std::string getManufacturer() const { return manufacturer; }
    std::string getModel() const { return model; }

    friend std::ostream& operator << (std::ostream& os, defaultClass& myClass) {
        return os << "Manufacturer: " << myClass.getManufacturer() << '\t' << "Model: " << myClass.getModel(); 
    } 
};


struct CPU : defaultClass {
    uint16_t frequency{};
    
    CPU() : defaultClass(processor) {
        std::cout << "Enter frequency: ";
        std::cin >> frequency;
        std::cin.ignore();
    }

    void print() {
        std::cout
            << "CPU data: " << '\n'
            << "\tManufacturer: " << manufacturer << '\n'
            << "\tModel: " << model << '\n'
            << "\tFrequency: " << frequency << std::endl;
    }
};


struct MB : defaultClass {
    std::string socket{};

    MB() : defaultClass(motherboard) {
        std::cout << "Enter socket: ";
        std::getline(std::cin, socket);
    }

    void print() {
        std::cout
            << "Mothervoard data: " << '\n'
            << "\tManufacturer: " << manufacturer << '\n'
            << "\tModel: " << model << '\n'
            << "\tSocket: " << socket << std::endl;
    }
};


struct RAM : defaultClass {
    uint16_t frequency{};

    RAM() : defaultClass(memory) {
        std::cout << "Enter frequency: ";
        std::cin >> frequency;
        std::cin.ignore();
    }

    void print() {
        std::cout
            << "RAM data: " << '\n'
            << "\tManufacturer: " << manufacturer << '\n'
            << "\tModel: " << model << '\n'
            << "\tFrequency: " << frequency << std::endl;
    }
};


struct GPU : defaultClass {
    components component = graphics;
    uint16_t coreFrequency{};
    uint16_t memoryFrequency{};

    GPU() : defaultClass(graphics){
        std::cout << "Enter core frequency: ";
        std::cin >> coreFrequency;
        std::cout << "Enter memory frequency: ";
        std::cin >> memoryFrequency;
        std::cin.ignore();
    }

    void print() {
        std::cout
            << "GPU data: " << '\n'
            << "\tManufacturer: " << manufacturer << '\n'
            << "\tModel: " << model << '\n'
            << "\tCore frequency: " << coreFrequency << '\t'
            << "\tMemory frequency: " << memoryFrequency << std::endl;
    }
};


struct storage : defaultClass {
    uint16_t capacity{};

    storage() : defaultClass(internalStorage) {
        std::cout << "Enter storage capacity: ";
        std::cin >> capacity;
        std::cin.ignore();
    }

    void print() {
        std::cout
            << "Storage data: " << '\n'
            << "\tManufacturer: " << manufacturer << '\n'
            << "\tModel: " << model << '\n'
            << "\tCapacity: " << capacity << std::endl;
    }
};


struct PSU : defaultClass {
    uint16_t capacity{};

    PSU() : defaultClass(powerSupply) {
        std::cout << "Enter power supply capacity: ";
        std::cin >> capacity;
        std::cin.ignore();
    }

    void print() {
        std::cout
            << "PSU data: " << '\n'
            << "\tManufacturer: " << manufacturer << '\n'
            << "\tModel: " << model << '\n'
            << "\tCapacity: " << capacity << std::endl;
    }
};


struct pcCase : defaultClass {
    pcCase() : defaultClass(computerCase) {}
}; 


struct PC {
    CPU myCPU{};
    MB myMB{};
    RAM myMemory{};
    GPU myGPU{};
    storage myStorage{};
    PSU myPSU{};
    pcCase myCase{};
};


int main() {
    PC newPC{};
    uint16_t choice = 0;
    
    std::cout
        << "Choose print method: " << '\n'
        << "1. Short" << '\n'
        << "2. Extended" << '\n'
        << "> ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            std::cout
                << "CPU: \t" << newPC.myCPU << '\n'
                << "Motherboard: \t" << newPC.myMB << '\n'
                << "Memory: " << newPC.myMemory << '\n'
                << "Graphics card: " << newPC.myGPU << '\n'
                << "Storage: " << newPC.myStorage << '\n'
                << "Power supply: " << newPC.myPSU << '\n'
                << "PC case: " << newPC.myCase << std::endl;

            break;

        case 2:
            newPC.myCPU.print();
            newPC.myMB.print();
            newPC.myMemory.print();
            newPC.myGPU.print();
            newPC.myStorage.print();
            newPC.myPSU.print();
            std::cout << "PC case data:" << '\n' << '\t' << newPC.myCase << std::endl;

            break;
    }


    return 0;
}
