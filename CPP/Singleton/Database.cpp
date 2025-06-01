#include<iostream>
#include<unordered_map>
using namespace std;


class ConfigManager{
    private:
    static ConfigManager* instance;
    ConfigManager(){
        cout<<"Config Created\n";
    }
    ~ConfigManager(){
        cout<<"Config Deleted\n";
    }
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager& ) = delete;
    unordered_map<string,string> setting;
    public:
    static ConfigManager* getInstance(){
        if(instance == nullptr){
            instance = new ConfigManager();
        }
        return instance;
    }
    void set(string key, string value){
        setting[key] = value;
    }
    string get(string key){
        if(setting.find(key)!=setting.end()){
            return setting[key];
        }
        else{
            return "Key not found\n";
        }
    }
    void printSettings(){
        for(auto& pair: setting){
            cout<<pair.first<<"="<<pair.second<<endl;
        }
    }
};

ConfigManager* ConfigManager::instance  = nullptr;

int main(){

    ConfigManager* conf = ConfigManager::getInstance();
    conf->set("Port","8090");
    conf->printSettings();
    return 0;

}

