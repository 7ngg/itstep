#include <iostream>
#include <string>

class GPU {
private:
    std::string name;
    uint16_t coreFrequency{};
    uint16_t memoryFrequency{};
public:
    GPU() = default;

    GPU(std::string _name, uint16_t _coreFrequency, uint16_t _memoryFrequency) {
        this->name = _name;
        this->coreFrequency = _coreFrequency;
        this->memoryFrequency = _memoryFrequency;
    }

    GPU(const GPU& other) {
        this->name = other.name;
        this->coreFrequency = other.coreFrequency;
        this->memoryFrequency = other.memoryFrequency;
    }

    friend std::ostream& operator << (std::ostream&  stream, const GPU myGPU) {
        stream 
            << "GPU: " << '\n'
            << '\t' << "Name: " << myGPU.name << '\n'
            << '\t' << "Core frequency: " << myGPU.coreFrequency << '\n'
            << '\t' << "Memory frequency: " << myGPU.memoryFrequency;

        return stream;
    }
};

class Storage {
private:
    std::string name;
    uint16_t capacity{};
public:
    Storage() = default;

    Storage(std::string _name, uint16_t _capacity) {
        this->name = _name;
        this->capacity = _capacity;
    }

    Storage(const Storage& other) {
        this->name = other.name;
        this->capacity = other.capacity;
    }

    friend std::ostream& operator << (std::ostream& stream, const Storage myStorage) {
        stream 
            << "Storage: " << '\n'
            << '\t' << "Name: " << myStorage.name << '\n'
            << '\t' << "Capacity: " << myStorage.capacity;

        return stream;
    }
};

class PC_case {
private:
    enum pc_case_type {
        MINI = 1,
        MID, 
        FULL
    };

    std::string name;
    pc_case_type type;
public:
    PC_case() = default;

    PC_case(std::string _name, uint16_t caseType) {
        this->name = _name;
        this->type = pc_case_type(caseType);
    }

    PC_case (const PC_case& other) {
        this->name = other.name;
        this->type = other.type;
    }

    void printTypes() {
        std::cout
            << "1. Mini tower" << '\n'
            << "2. Mid tower" << '\n'
            << "3. Full tower" << '\n';
    }

    friend std::ostream& operator << (std::ostream& stream, const PC_case myCase) {
        stream
            << "Case: " << '\n'
            << '\t' << "Name: " << myCase.name << '\n'
            << '\t' << "Case type: ";

        if (myCase.type == MINI)
        {
            stream << "Mini tower";
        }
        else if (myCase.type == MID)
        {
            stream << "Mid tower";
        }
        else if (myCase.type == FULL)
        {
            stream << "Full tower";
        }

        return stream;
    }
};


class PC {
private:
    class CPU {
    private:
        std::string name;
        uint16_t frequency{};
        uint16_t coresCount{};
    public:
        CPU() = default;

        CPU(std::string _name, uint16_t _frequency, uint16_t _coresCount) {
            this->name = _name;
            this->frequency = _frequency;
            this->coresCount = _coresCount;
        }

        CPU(const CPU& other) {
            this->name = other.name;
            this->coresCount = other.coresCount;
            this->frequency = other.frequency;
        }

        friend std::ostream& operator << (std::ostream& stream, const CPU myCPU) {
            stream
                << "CPU:" << '\n'
                << '\t' << "Name: " << myCPU.name << '\n'
                << '\t' << "Cores count: " << myCPU.coresCount << '\n'
                << '\t' << "Cores frequency: " << myCPU.frequency; 
            
            return stream;
        }
    };

    class Motherboard {
    private:
        std::string name;
        std::string socket;
    public:
        Motherboard() = default;

        Motherboard(std::string _name, std::string _socket) {
            this->name = _name;
            this->socket = _socket;
        }

        Motherboard(const Motherboard& other) {
            this->name = other.name;
            this->socket = other.socket;
        }

        friend std::ostream& operator << (std::ostream& stream, const Motherboard myMB) {
            stream 
                << "Motherboard: " << '\n'
                << '\t' << "Name:" << myMB.name << '\n'
                << '\t' << "Socket: " << myMB.socket;

            return stream;  
        }
    };

    class RAM {
    private:
        std::string name;
        uint16_t frequency{};
    public:
        RAM() = default;

        RAM(std::string _name, uint16_t _frequency) {
            this->name = _name;
            this->frequency = _frequency;
        }

        RAM(const RAM& other) {
            this->name = other.name;
            this->frequency = other.frequency;
        }

        friend std::ostream& operator << (std::ostream& stream, const RAM myRAM) {
            stream
                << "Memory: " << '\n'
                << '\t' << "Name: " << myRAM.name << '\n'
                << '\t' << "Frequency: " << myRAM.frequency;

            return stream;
        }
    };
    
    class PSU {
    private:
        std::string name;
        uint16_t capacity{};
    public:
        PSU() = default;

        PSU(std::string _name, uint16_t _capacity) {
            this->name = _name;
            this->capacity = _capacity;
        }

        PSU(const PSU& other) {
            this->name = other.name;
            this->capacity = other.capacity;
        }

        friend std::ostream& operator << (std::ostream& stream, const PSU myPSU) {
            stream 
                << "PSU: " << '\n'
                << '\t' << "Name: " << myPSU.name << '\n'
                << '\t' << "Capacity: " << myPSU.capacity;
        
            return stream;
        }
    };

    Motherboard* motherboard{};
    CPU* cpu{};
    RAM* ram{};
    PSU* psu{};
    GPU* gpu{};
    Storage* storage{};
    PC_case* pc_case{};

public:
    PC() {
        using namespace std;

        std::string globalName, globalName_2;
        uint16_t numeric_1{}, numeric_2{};

        cout << "Enter motherboard name: ";
        getline(cin, globalName);
        cout << "Enter motherboard socket: ";
        getline(cin, globalName_2);
        this->motherboard = new Motherboard { globalName, globalName_2 };


        cout << "Enter CPU name: ";
        getline(cin, globalName);
        cout << "Enter CPU cores count: ";
        cin >> numeric_1;
        cout << "Enter core frequency: ";
        cin >> numeric_2;
        this->cpu = new CPU { globalName, numeric_2, numeric_1 }; 

        cin.ignore();

        cout << "Enter RAM name: ";
        getline(cin, globalName);
        cout << "Enter RAM frequency: ";
        cin >> numeric_1;
        this->ram = new RAM { globalName, numeric_1 };

        cin.ignore();

        cout << "Enter PSU name: ";
        getline(cin, globalName);
        cout << "Enter PSU capacity: ";
        cin >> numeric_1;
        this->psu = new PSU { globalName, numeric_1 };
        
        cin.ignore();

        cout << "Enter GPU name: ";
        getline(cin, globalName);
        cout << "Enter core frequency: ";
        cin >> numeric_1;
        cout << "Enter memory frequency: ";
        cin >> numeric_2;
        this->gpu = new GPU { globalName, numeric_1, numeric_2 };

        cin.ignore();

        cout << "Enter internal storage name: ";
        getline(cin, globalName);
        cout << "Enter storage capacity: ";
        cin >> numeric_1;
        this->storage = new Storage { globalName, numeric_1 };

        cin.ignore();

        cout << "Enter pc case name: ";
        getline(cin, globalName);
        cout << "Choose pc case type: " << '\n';
        this->pc_case->printTypes();
        cout << "> ";
        cin >> numeric_1;
        this->pc_case = new PC_case { globalName, numeric_1 };
    }

    PC(const PC& other) {
        this->cpu = new CPU(*other.cpu);
        //*this->cpu = *other.cpu;

        this->motherboard = new Motherboard(*other.motherboard);
        //this->motherboard = other.motherboard;

        this->ram = new RAM(*other.ram);
        //this->ram = other.ram;

        this->gpu = new GPU(*other.gpu);
        //this->gpu = other.gpu;

        this->storage = new Storage(*other.storage);
        //this->storage = other.storage;

        this->psu = new PSU(*other.psu);
        //this->psu = other.psu;

        this->pc_case = new PC_case(*other.pc_case);
        //this->pc_case = other.pc_case;
    }

    void f() {
        std::cout << *this->cpu << std::endl;
    }

    ~PC() {
        delete[] motherboard;
        delete[] cpu;
        delete[] ram;
        delete[] gpu;
        delete[] storage;
        delete[] psu;
        delete[] pc_case;
    }

    friend std::ostream& operator << (std::ostream& stream, const PC myPC) {
        stream
            << *myPC.motherboard << '\n'
            << *myPC.cpu << '\n'
            << *myPC.ram << '\n'
            << *myPC.gpu << '\n'
            << *myPC.storage << '\n'
            << *myPC.psu << '\n'
            << *myPC.pc_case << std::endl;

        return stream;
    }

    friend std::istream& operator >> (std::istream& stream, PC pc) {

    }
};



int main(int, char**){
    PC* newPC = new PC{};
    PC* otherPC = new PC(*newPC);

    std::cout << *otherPC << std::endl;
}
