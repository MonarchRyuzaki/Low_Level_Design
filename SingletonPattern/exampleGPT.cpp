#include <iostream>
#include <fstream>
#include <mutex>
#include <string>
using namespace std;

// Simulated configuration settings
struct Config {
    string dbConnectionString;
    string logFilePath;
};

// Singleton class
class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;
    Config config;
    ofstream logFile;

    // Private constructor to prevent instantiation
    Singleton() {
        loadConfiguration();
        connectToDatabase();
        setupLogging();
    }

    // Load configuration settings
    void loadConfiguration() {
        // Simulated configuration loading
        config.dbConnectionString = "DB_CONN_STRING";
        config.logFilePath = "logfile.txt";
    }

    // Connect to the database
    void connectToDatabase() {
        // Simulated database connection
        // In a real scenario, you would use the config.dbConnectionString to establish a connection
        // db.connect(config.dbConnectionString);
    }

    // Set up logging
    void setupLogging() {
        logFile.open(config.logFilePath, ios::app);
        if (!logFile) {
            throw runtime_error("Unable to open log file");
        }
    }

    // Deleted copy constructor and assignment operator to prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Get the Singleton instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr) {
                instance = new Singleton();
            }
        }
        return instance;
    }

    // Log a message
    void logMessage(const string& message) {
        logFile << message << endl;
    }

    // Get configuration settings
    Config getConfig() const {
        return config;
    }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    // Access the Singleton instance and use its methods
    Singleton* s1 = Singleton::getInstance();
    s1->logMessage("Application started");
    
    Config config = s1->getConfig();
    cout << "Database Connection String: " << config.dbConnectionString << endl;
    cout << "Log File Path: " << config.logFilePath << endl;

    Singleton* s2 = Singleton::getInstance();
    s2->logMessage("Another log message");

    if (s1 == s2) {
        cout << "Both pointers point to the same instance.\n";
    }

    return 0;
}
