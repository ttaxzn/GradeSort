#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Student
{
    public:
    Student();
    bool AcquireData(istream& in);
    bool PrintData(ostream& out) const;
    string GetFirstName() const;
    string GetLastName() const;
    float CourseAverage() const;
    bool DisplayCourseAverage(ostream& out) const;
    string LetterGrade() const;

    private:
    string firstname;
    string lastname;
    float quiz1;
    float quiz2;
    float quiz3;
    float quiz4;
    float exam1;
    float exam2;
    float finalproject;
    float courseavg;
};


Student::Student()
{
    firstname="";
    lastname="";
    quiz1=0;
    quiz2=0;
    quiz3=0;
    quiz4=0;
    exam1=0;
    exam2=0;
    finalproject=0;
}

bool Student::AcquireData(istream& in)
{
    in >> firstname;
    in >> lastname;
    in >> quiz1;
    in >> quiz2;
    in >> quiz3;
    in >> quiz4;
    in >> exam1;
    in >> exam2;
    in >> finalproject;
    return true;
}

bool Student::PrintData(ostream& out) const
{
    out << left << setw(20) << firstname << left << setw(20) << lastname
    << quiz1 << right << setw(4) << quiz2 << right << setw(4) << quiz3 
    << right << setw(4) << quiz4 << right << setw(4) << exam1 << right << setw(5)
    << right << setw(5) << exam2 << right << setw(5) << finalproject;
    return true;
}

string Student::GetFirstName() const
{
    return firstname;
}

string Student::GetLastName() const
{
    return lastname;
}

float Student::CourseAverage() const
{
    float quiztotal;
    float examtotal;
    float finaltotal;
    float average;
    quiztotal=((quiz1/10+quiz2/10+quiz3/10+quiz4/10)/4)*0.35;
    examtotal=((exam1/100+exam2/100)/2)*0.35;
    finaltotal=finalproject/100*0.30;
    average=(quiztotal+examtotal+finaltotal)*100;
    
    return average;
}

bool Student::DisplayCourseAverage(ostream& out) const
{
    out << setprecision(3) << CourseAverage() << left << LetterGrade() << endl;
    return true;
}

string Student::LetterGrade() const
{
    string letter;
    if(CourseAverage()>=93.0)
    {
        letter="A";
    }
    if(CourseAverage()<93.0 && CourseAverage()>=90.0)
    {
        letter="A-";
    }
    if(CourseAverage()<90 && CourseAverage()>=87)
    {
        letter="B+";
    }
    if(CourseAverage()<87 && CourseAverage()>=83)
    {
        letter="B";
    }
    if(CourseAverage()<83 && CourseAverage()>=80)
    {
        letter="B-";
    }
    if(CourseAverage()<80 && CourseAverage()>=77)
    {
        letter="C+";
    }
    if(CourseAverage()<77 && CourseAverage()>=73)
    {
        letter="C";
    }
    if(CourseAverage()<73 && CourseAverage()>=70)
    {
        letter="C-";
    }
    if(CourseAverage()<70 && CourseAverage()>=67)
    {
        letter="D+";
    }
    if(CourseAverage()<67 && CourseAverage()>=63)
    {
        letter="D";
    }
    if(CourseAverage()<63 && CourseAverage()>=60)
    {
        letter="D-";
    }
    if(CourseAverage()<60)
    {
        letter="F";
    }
    return letter;
}
bool operator<(const Student& lhs, const Student& rhs) {
   return lhs.CourseAverage() < rhs.CourseAverage();
}

int main()
{
    vector <Student> myStudentVector;
    Student myStudent;
    string firstname;
    string lastname;
    float quiz1;
    float quiz2;
    float quiz3;
    float quiz4;
    float exam1;
    float exam2;
    float finalproject;

    ifstream data;
    int students;
    int i;
    data.open("Program4Data.txt");
    data >> students;
    for(i=0; i<students; i++)
    {
        myStudent.AcquireData(data);
        myStudentVector.push_back(myStudent);
    }
    data.close();

    int j;
    sort(myStudentVector.begin(), myStudentVector.end());
    reverse(myStudentVector.begin(), myStudentVector.end());
    char input;
    cout << "Enter 'A' for average grades, 'E' for all assignment grades, 'Q' to quit" << endl;
    cin >> input;
    while(input!='q')
    {
    if(input=='E' || input =='e')
    {
   /*cout << left << setw(20) << "First" << left << setw(20) << "Last"
    << left << setw(4) << "Q1" << left << setw(4) << "Q2" << left << setw(4) << "Q3"
    << left << setw(4) << "Q4" << left << setw(5) << "E1" << left << setw(5) << "E2"
    << left << setw(5) << "FP" << endl;
    cout << endl;*/
    for(i=0; i<students; i++)
    {
        myStudent=myStudentVector.at(i);
        myStudentVector.at(i).PrintData(cout);
        cout << endl;
    }
    }

    if(input=='A' || input=='a')
    {
    for(i=0; i<myStudentVector.size(); ++i)
    {

        myStudent=myStudentVector.at(i);

        cout << left << setw(20) << myStudent.GetFirstName() << left << setw(20) << myStudent.GetLastName() << left << setw(10);
        myStudent.DisplayCourseAverage(cout);
        
    }
    cout << endl;
    cout << "More information can be found in output.txt file in the same directory!" << endl;
    }
    if(input=='Q' || input=='q')
    {
        break;
    }
    cout << "Enter 'A' for average grades, 'E' for all assignment grades, 'Q' to quit" << endl;
    cin >> input;
    }


    
    return 0;
}