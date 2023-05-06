#include <iostream>
#include <stdint.h>
#include <iso646.h>

struct finalPC {
    const char* PCcase = new char[32] {};
    const char* cpu = new char[32] {};
    const char* motherboard = new char[32] {};
    const char* memory = new char[32] {};
    const char* storage = new char[32] {};
    const char* gpu = new char[32] {};
    const char* psu = new char[32] {};

    void showPC() {
        std::cout
            << "Case: " << PCcase << '\n'
            << "CPU: " << cpu << '\n'
            << "Motherboard: " << motherboard << '\n'
            << "Memory: " << memory << '\n'
            << "Storage: " << storage << '\n'
            << "GPU: " << gpu << '\n'
            << "PSU: " << psu << '\n';
    }
};


bool checkStep(uint16_t currentStep, uint16_t requiredStep) {
    if (requiredStep <= currentStep)
    {
        return true;
    }
    return false;
}


int main() {
    using namespace std;

    finalPC newPC;
    uint16_t step = 1;
    uint16_t choice = 0;
    bool flag = true;

    const char* PCcases[2] = { "Zalman R2 White", "Zalman R2 Black" };
    const char* CPUs[2] = { "Intel Core i7-13700k", "Ryzen 7 7700x" };
    const char* motherboards[2] = { "GIGABYTE Z790 AORUS ELITE AX", "ASUS ROG Strix B650E-F Gaming" };
    const char* memory[2] = { "Trident Z DDR5 6000 cl36", "Trident Z ddr 4000 cl16" };
    const char* storage[2] = {"Samsum 970 EVO 2tb", "Samsum 980 EVO 1tb"};
    const char* GPUS[2] = { "Geforce RTX 4070ti", "Radeon 7800XT" };
    const char* PSUS[2] = { "Seasonic 1200w 80plus PLAT", "Cooler Master 1000w 80plus GOLD" };


    while (flag)
    {
        uint16_t inCaseChoice = 0;

        if (step == 8)
        {
            cout << "PC is set" << '\n';
            newPC.showPC();
            break;
        }

        cout
            << "You are building a PC. Choose a step: " << '\n'
            << "1. Case" << '\n'
            << "2. CPU" << '\n'
            << "3. Motherboard" << '\n'
            << "4. Memory" << '\n'
            << "5. Storage" << '\n'
            << "6. GPU" << '\n'
            << "7. PSU" << '\n'
            << "8. Show the pc\n"
            << "0. Exit" << '\n'
            << "> ";
        cin >> choice;

        if (choice != 8 and not checkStep(step, choice)) {
            cout << "You must complete previous steps first" << '\n';
            continue;
        }

        step += 1;

        switch (choice) 
        {
            case 0:
                flag = false;
                break;

            case 1:
                cout << "Choose a pc-case: \n";
                for (size_t i = 0; i < 2; ++i) 
                {
                    cout << i + 1 << ". " << PCcases[i] << '\n';
                }
                cout << "> ";
                cin >> inCaseChoice;
                newPC.PCcase = PCcases[inCaseChoice - 1];

                break;
            
            case 2:
                cout << "Choose a CPU: \n";
                for (size_t i = 0; i < 2; ++i)
                {
                    cout << i + 1 << ". " << CPUs[i] << '\n';
                }
                cout << "> ";
                cin >> inCaseChoice;
                newPC.cpu = CPUs[inCaseChoice - 1];

                break;

            case 3:
                cout << "Choose a motherboard: \n";
                for (size_t i = 0; i < 2; ++i)
                {
                    cout << i + 1 << ". " << motherboards[i] << '\n';
                }
                cout << "> ";
                cin >> inCaseChoice;
                newPC.motherboard = motherboards[inCaseChoice - 1];

                break;

            case 4:
                cout << "Choose a memory kit: \n";
                for (size_t i = 0; i < 2; ++i)
                {
                    cout << i + 1 << ". " << memory[i] << '\n';
                }
                cout << "> ";
                cin >> inCaseChoice;
                newPC.memory = memory[inCaseChoice - 1];

                break;

            case 5:
                cout << "Choose storage: \n";
                for (size_t i = 0; i < 2; ++i)
                {
                    cout << i + 1 << ". " << storage[i] << '\n';
                }
                cout << "> ";
                cin >> inCaseChoice;
                newPC.storage = storage[inCaseChoice - 1];

                break;

            case 6:
                cout << "Choose a GPU: \n";
                for (size_t i = 0; i < 2; ++i)
                {
                    cout << i + 1 << ". " << GPUS[i] << '\n';
                }
                cout << "> ";
                cin >> inCaseChoice;
                newPC.gpu = GPUS[inCaseChoice - 1];

                break;

            case 7:
                cout << "Choose a PSU: \n";
                for (size_t i = 0; i < 2; ++i)
                {
                    cout << i + 1 << ". " << PSUS[i] << '\n';
                }
                cout << "> ";
                cin >> inCaseChoice;
                newPC.psu = PSUS[inCaseChoice - 1];

                break;

            case 8:
                newPC.showPC();
        }
    }
    

    return 0;
}
