#pragma once

#include <iostream>
#include <vector>


struct TestResult
{
    std::string subjectName;
    uint16_t correctAnswers = 0;
    double mark = 0.;
    double persentage = 0.;

    friend std::ostream& operator << (std::ostream& stream, const TestResult result) {
        stream
            << result.subjectName << '\n'
            << '\t' << "Correct answers: " << result.correctAnswers << '\n'
            << '\t' << "Mark: " << result.mark << '\n'
            << '\t' << "Persentage: " << result.persentage << '\n';

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

public:
    std::vector<Task*> tasksList;
    
    Subject(std::string subjectName) {
        this->subjectName = subjectName;
    }


    std::string getSubjectName() {
        return this->subjectName;
    }


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
        result.subjectName = this->subjectName;
    
        return result;
    }
};