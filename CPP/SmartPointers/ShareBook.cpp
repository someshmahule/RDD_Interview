#include<iostream>
#include<memory>

using namespace std;


class Book{

    public:
    string name;
    Book(){ cout<<"Book Created\n";}
    ~Book() {cout<<"Book Destroyed\n";}

};

class Student{


    public:
    string name;
    Student(string name, shared_ptr<Book> b): name(name),
    shr_book(b) { cout<<"Student created\n";}
    ~Student() { cout<<"Student Destroyed\n";}
    shared_ptr<Book> shr_book;
};


int main(){


    shared_ptr<Book> b1 = make_shared<Book>();
    unique_ptr<Student> s1 = make_unique<Student>("Somesh",b1);
    unique_ptr<Student> s2 = make_unique<Student>("Rakesh",b1);


    return 0;

}