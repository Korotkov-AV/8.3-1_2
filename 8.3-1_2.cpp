// 8.3-1_2.cpp : 


#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print() const = 0;
};

class printToFile : public LogCommand {
private:
    std::string pay_load_;
public:
    explicit printToFile(const std::string& message) : pay_load_(message) {};
    void print() const override {
        std::ofstream file("text.txt");
        file << pay_load_ << std::endl;
        file.close();
    }
};

class printToConsole : public LogCommand {
private:
    std::string pay_load_;
public:
    explicit printToConsole(const std::string& message) : pay_load_(message) {};
    void print() const override {
        std::cout << pay_load_ << std::endl;
    }
};

void print(LogCommand* com) {
    com->print();
}

int main() {
    printToFile f("say to file");
    printToConsole c("say to console");

    print(&f);
    print(&c);
}