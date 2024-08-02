#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class Logger{
private:
    static Logger *instance;
    static mutex mtx;
    ofstream logFile;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger() {
        logFile.open("log.txt");
    }
public:
    ~Logger(){
        if (logFile.is_open()) {
            logFile.close();
        } 
    }
    static Logger* getInstance() {
        lock_guard<mutex> lock(mtx);
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }
    void write(const string &msg) {
        logFile << msg << endl;
    }
};

Logger* Logger::instance = nullptr;
mutex Logger::mtx;

int main(){
    Logger* log = Logger::getInstance();
    log->write("Hello World");
}