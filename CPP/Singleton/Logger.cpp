#include<iostream>

using namespace std;

class Logger{
    private:
    static Logger* logger;
    Logger(){
        cout<<"Logger created";
    }

    Logger(const Logger&) = delete;
    Logger& operator=(Logger& ) = delete;

    public:
    static Logger* getInstance(){
        if (logger == nullptr) {
            logger = new Logger();
        }
        return logger;
    }
    void log(const string& msg){
        cout<<"[LOG]: "<<msg;
    }

};

Logger* Logger::logger = nullptr;

int main(){

    Logger* log1 = Logger::getInstance();
    log1->log("Starting app");

    Logger* log2 = Logger::getInstance();
    log2->log("Still logging");

    if(log1 == log2){
        cout<<"Same loggers\n";
    }

    return 0;
}