#pragma once

#include <iostream>
#include <vector>
#include <cstdint>

struct TestResult
{
    uint16_t correctAnswers = 0;
    double mark = 0.;
    double persentage = 0.;

    friend std::ostream& operator << (std::ostream& stream, const TestResult result) {
        stream
            << "Correct answers: " << result.correctAnswers << '\n'
            << "Mark: " << result.mark << '\n'
            << "Persentage: " << result.persentage << '\n';

        return stream;
    }
};

class Subject {
    class Task {
    public:
        std::string statement;
        std::string answer;

        Task() = default;

        Task(std::string statement, std::string answer) {
            this->statement = statement;
            this->answer = answer;
        }
    };

    std::string subjectName;
    std::vector<Task*> tasksList;

public:
    void addTask() {
        std::string taskStatement, taskAnswer;
        
        std::cout << "Enter statement: ";
        getline(std::cin, taskStatement);
        std::cout << "Enter answer: ";
        getline(std::cin, taskAnswer);

        tasksList.push_back(new Task { taskStatement, taskAnswer });
    }

    TestResult beginTest() {
        TestResult result;
        std::cout << tasksList.size();
        for (size_t i = 0; i < tasksList.size(); i++)
        {
            std::string tmpAnswer;

            std::cout << tasksList[i]->statement << std::endl;
            std::cout << "Answer: ";
            getline(std::cin, tmpAnswer);

            if (tmpAnswer == tasksList[i]->answer)
            {
                result.correctAnswers += 1;
            }
        }
        
        result.persentage = (double(result.correctAnswers) / tasksList.size()) * 100;
        result.mark = (double(result.correctAnswers) / tasksList.size()) * 12;
    
        return result;
    }
};