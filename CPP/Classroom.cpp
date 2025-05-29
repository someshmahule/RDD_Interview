#include<iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


struct Student{

    string name;
    int marks;

    Student():name(""),marks(0){}
    Student(string s, int m): name(s), marks(m) {}
};

class Classroom{

    public:
    vector<Student> stu_vec;
    unordered_map<string,Student> stu_map;
    Classroom() {}
    ~Classroom() {}
    void addStudent(const Student& s);
    void printTopper();
    bool findStudent(const string& name);

};

bool compareStudent(const Student& a, const Student& b){
    return a.marks > b.marks;
}

void Classroom::addStudent(const Student& s){

    stu_vec.push_back(s);
    stu_map[s.name] = s;
}

void Classroom::printTopper(){

    std::sort(stu_vec.begin(),stu_vec.end(),compareStudent);
    cout<<"Topper:\n";
    cout<<"Name: "<<stu_vec[0].name<<" "<<"Marks"<<stu_vec[0].marks<<"\n";
}

bool Classroom::findStudent(const string& name){

    if (stu_map.find(name) != stu_map.end()){ // found
        return true;
    }
    return false;
}

int main(){

    Classroom obj;
    obj.addStudent(Student("somesh",100));
    obj.addStudent(Student("gudiya",22));
    obj.addStudent(Student("suwarna",10));

    obj.printTopper();

    cout<<"Find Student:\n";
    string name;
    cin>>name;
    if (obj.findStudent(name)){
        cout<<"Student Exist";
    }
    else{
        cout<<"Student Doesnt exist\n";
    }
}