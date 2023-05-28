#include <iostream>
#include <stdint.h>
#include <string>

struct CPU {
    std::string name{};
    uint16_t coresCount{};
    uint16_t threadsCount{};
    uint16_t frequency{};

    CPU() {
        std::cout << "Enter CPU name: ";
        std::getline(std::cin, name);
        //std::cin.ignore();
        
        std::cout << "Enter cores count: ";
        std::cin >> coresCount;
        std::cin.ignore();

        std::cout << "Enter threads count: ";
        std::cin >> threadsCount;
        std::cin.ignore();

        std::cout << "Enter frequency: ";
        std::cin >> frequency;
        std::cin.ignore();
    }

    void print() {
        std::cout
            << "CPU name: " << name << '\n'
            << "Cores count: " << coresCount << '\n'
            << "Threads count: " << threadsCount << '\n'
            << "Frequency: " << frequency << std::endl;
    }
};

struct motherboard {
    std::string name{};
    std::string socket{};
    std::string chipset{};

    motherboard() {
        std::cout << "Enter motherboard's name: ";
        std::getline(std::cin, name);
        //std::cin.ignore();

        std::cout << "Enter socket: ";
        std::getline(std::cin, socket);
        //std::cin.ignore();

        std::cout << "Enter chipset: ";
        std::getline(std::cin, chipset);
        //std::cin.ignore();
    }

    void print() {
        std::cout
            << "Motherboard name: " << name << '\n'
            << "Socket: " << socket << '\n'
            << "Chipset: " << chipset << std::endl;
    }
};

struct RAM {
    std::string name{};
    std::string type{};
    uint16_t CAS{};

    RAM() {
        std::cout << "Enter RAM name: ";
        std::getline(std::cin, name);
        //std::cin.ignore();

        std::cout << "Enter RAM type: ";
        std::getline(std::cin, type);
        //std::cin.ignore();

        std::cout << "Enter CAS latency: ";
        std::cin >> CAS;
        std::cin.ignore();
    }

    void print() {
        std::cout
            << "RAM name: " << name << '\n'
            << "RAM type: " << type << '\n'
            << "CAS latency: " << CAS << std::endl;
    }
};

struct GPU {
    std::string name{};
    std::string memoryType{};
    uint16_t coreFrequency{};
    uint16_t memoryFrequency{};

    GPU() {
        std::cout << "Enter GPU's name: ";
        std::getline(std::cin, name);
        //std::cin.ignore();

        std::cout << "Enter core frequency: ";
        std::cin >> coreFrequency;
        std::cin.ignore();

        std::cout << "Enter memory type: ";
        std::getline(std::cin, memoryType);
        //std::cin.ignore();

        std::cout << "Enter memory frequency: ";
        std::cin >> memoryFrequency;
        std::cin.ignore();
    }

    void print() {
        std::cout
            << "GPU name: " << name << '\n'
            << "Core frequency: " << coreFrequency << '\n'
            << "Memory type: " << memoryType << '\n'
            << "Memory frequency: " << memoryFrequency << std::endl;
    }
};

struct storage {
    std::string type{};
    std::string name{};
    uint16_t readSpeed{};
    uint16_t writeSpeed{};

    storage() {
        std::cout << "Enter storage type: ";
        std::getline(std::cin, type);
        //std::cin.ignore();

        std::cout << "Enter name: ";
        std::getline(std::cin, name);
        //std::cin.ignore();

        std::cout << "Enter read-speed: ";
        std::cin >> readSpeed;
        std::cin.ignore();

        std::cout << "Enter write-speed: ";
        std::cin >> writeSpeed;
        std::cin.ignore();
    }

    void print() {
        std::cout 
            << "Storage type: " << type << '\n'
            << "Manufacturer: " << name << '\n'
            << "Read-speed: " << readSpeed << '\n'
            << "Write-speed: " << writeSpeed << std::endl;
    }
};

struct PSU {
    std::string name{};
    uint16_t wattage{};

    PSU() {
        std::cout << "Enter PSU name: ";
        std::getline(std::cin, name);
        //std::cin.ignore();

        std::cout << "Enter wattage: ";
        std::cin >> wattage;
        std::cin.ignore();
    }

    void print() {
        std::cout
            << "PSU name: " << name << '\n'
            << "Wattage: " << wattage << std::endl;
    }
};

class myPC {
private:
    CPU myCPU{};
    motherboard myMB{};
    RAM myRAM{};
    GPU myGPU{};
    storage myStorage{};
    PSU myPSU{};
    std::string myCase{};
    
public:
    myPC() {
        std::cout << "Enter case name: ";
        std::getline(std::cin, myCase);
    }

    void shortPrint() {
        system("cls");
        std::cout 
            << "Motherboard: " << myMB.name << '\n'
            << "CPU: " << myCPU.name << '\n'
            << "Memory: " << myRAM.name << '\n'
            << "Graphics card: " << myGPU.name << '\n'
            << "Storage: " << myStorage.name << '\n'
            << "Power supply: " << myPSU.name << '\n'
            << "Case: " << myCase << std::endl;
    }

    void extendedPrint() {
        system("cls");
        myMB.print();
        myCPU.print();
        myRAM.print();
        myGPU.print();
        myStorage.print();
        myPSU.print();
        std::cout << "Case: " << myCase << std::endl;
    }
};

int main() {
    myPC newPC{};
    uint16_t choice{};
    
    system("cls");
    std::cout 
        << "Choose print method: " << '\n'
        << "1. Short print" << '\n'
        << "2. Extended print" << '\n'
        << "> ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            newPC.shortPrint();
            break;

        case 2:
            newPC.extendedPrint();
            break;

        default:
            std::cout << "No such case" << std::endl;
            break;
    }
        
    system("pause");
    return 0;
}
