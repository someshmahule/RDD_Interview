#include<iostream>
using namespace std;

struct Student
{
    string name;
    int marks;

    Student() : name(""), marks(0) {}
    Student(string s, int m) : name(s),marks(m) {}
};



class StudentSort
{
    public:
        int SIZE;
        Student* array;
        StudentSort(): SIZE(0),array(nullptr) {}
        ~StudentSort() {delete[] array;}
        void inputData();
        void SelectionSort();
        void printData();

};

void StudentSort::inputData(){

    cout<<"Enter class size\n";
    cin>>SIZE;

    array = new Student[SIZE];

    for(int i=0;i<SIZE;i++){
        string name;
        int marks;
        cout<<"Enter Name :";
        cin>>name;
        cout<<"Enter Marks :";
        cin>>marks;
        array[i].name = name;
        array[i].marks = marks;
    }
}

void StudentSort::SelectionSort(){

    for(int i=0;i<SIZE;i++){
        int min_index = i;
        for(int j=i;j<SIZE;j++){
            if(array[j].marks < array[min_index].marks){
                min_index = j;
            }
        }
        swap(array[i],array[min_index]);
    }

}

void StudentSort::printData(){
    cout<<"Marks :";
    for(int i=SIZE-1;i>=0;i--){
        cout<<array[i].marks<<" ";
    }
}


int main(){

    StudentSort obj;
    obj.inputData();
    obj.SelectionSort();
    obj.printData();


}