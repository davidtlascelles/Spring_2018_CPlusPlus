
/*  Exam 1 Program
    David Lascelles
    1/31/2018
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Student{
    string name;
    int hw1, hw2, hw3, ex1, ex2, totalhw, totalexam;
    float percent;
    char grade;
};

// input() allows one to input Student data
int input(struct Student s[], int NUMBER_OF_STUDENTS)
{
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        cout<<"\nPlease enter information for student "<<i+1<<endl<<endl;
        cout<<"Enter Last Name, First Name: "<<endl;
        getline(cin,s[i].name);
        cout<<"Enter 3 homework grades: "<<endl;
        cin>>s[i].hw1>>s[i].hw2>>s[i].hw3;
        cout<<"Enter 2 exam scores: "<<endl;
        cin>>s[i].ex1>>s[i].ex2;
        cin.ignore();
    }
    return 0;
}

// importFile() imports a file containing Student data
int importFile(struct Student s[], int NUMBER_OF_STUDENTS)
{
    ifstream f ("students.txt", ios::in);
    
    if (f.is_open())
    {
        for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
        {
            getline(f, s[i].name);
            f >> s[i].hw1 >> s[i].hw2 >> s[i].hw3 >> s[i].ex1 >> s[i].ex2;
            f.ignore();
        }
        f.close();
    }
    else
        cout << "Unable to open file - read failed";
    return 0;
}

// calc() calculates Total Homework Points, Total Exam Points, and Class Percentage for each Student
int calc(struct Student s[], int NUMBER_OF_STUDENTS)
{
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        s[i].totalhw = s[i].hw1 + s[i].hw2 + s[i].hw3;
        s[i].totalexam = s[i].ex1 + s[i].ex2;
        s[i].percent = (s[i].totalhw/1.875)+(s[i].totalexam/3.333);
    }
    return 0;
}

// grade() assigns grade based on Class Percentage to a Student
int grade(struct Student s[], int NUMBER_OF_STUDENTS)
{
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        if (s[i].percent >= 90)
            s[i].grade = 'A';
        else
            if (s[i].percent >= 80)
                s[i].grade = 'B';
            else
                if (s[i].percent >= 70)
                    s[i].grade = 'C';
                else
                    if (s[i].percent >= 60)
                        s[i].grade = 'D';
                    else
                        s[i].grade = 'F';
    }
    return 0;
}

// print() prints Student data with formatting
int print(struct Student s[], int NUMBER_OF_STUDENTS)
{
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        cout << setw(26) << left << "\nStudent Name: " << right << s[i].name << endl;
        cout << setw(25) << left << "Total Homework Points: " << right << s[i].totalhw << endl;
        cout << setw(25) << left << "Total Exam Points: " << right << s[i].totalexam << endl;
        cout << setw(25) << left << "Class Percentage: " << right << setprecision(2) << showpoint << fixed << s[i].percent << "%" << endl;
        cout << setw(25) << left << "Final Grade: " << right << s[i].grade << "\n" <<endl;
    }
    return 0;
}

// outputFile() generates a file containing result data
int outputFile(struct Student s[], int NUMBER_OF_STUDENTS)
{
    ofstream f ("students2.txt", ios::out);
    
    if (f.is_open())
    {
        for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
        {
            f << s[i].name << endl << s[i].totalhw << endl << s[i].totalexam << endl << s[i].percent << endl << s[i].grade << endl << endl;
        }
        f.close();
    }
    else
        cout << "Unable to open file - write failed";
    return 0;
}

// avg() finds the average grade for each exam score based on exam scores from students
int avg(struct Student s[], int NUMBER_OF_STUDENTS)
{
    float acc1 = 0, acc2 = 0;
    float ex1avg, ex2avg;
    
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        acc1 += s[i].ex1;
        acc2 += s[i].ex2;
    }
    
    ex1avg = acc1/NUMBER_OF_STUDENTS;
    ex2avg = acc2/NUMBER_OF_STUDENTS;
    
    cout << "\nThe class average for" << endl;
    cout << setw(25) << left << "Exam 1 Scores: " << right << setprecision(2) << showpoint << fixed << ex1avg <<  "%" <<endl;
    cout << setw(25) << left << "Exam 2 Scores: " << right << ex2avg <<  "%\n" << endl;
    
    return 0;
}

// results() accululates total number of each grade for a class of students, and outputs the results
int results(struct Student s[], int NUMBER_OF_STUDENTS)
{
    int a = 0, b = 0, c = 0, d = 0, f = 0;
    
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        if (s[i].grade == 'A')
            a++;
        else
            if (s[i].grade == 'B')
                b++;
            else
                if (s[i].grade == 'C')
                    c++;
                else
                    if (s[i].grade == 'D')
                        d++;
                    else
                        f++;
    }
    
    cout << "Grade Breakdown:" << endl;
    cout << setw(5) << left << "A: " << right << a << endl;
    cout << setw(5) << left << "B: " << right << b << endl;
    cout << setw(5) << left << "C: " << right << c << endl;
    cout << setw(5) << left << "D: " << right << d << endl;
    cout << setw(5) << left << "F: " << right << f << "\n" << endl;
    
    return 0;
}

int main()
{
    const int NUMBER_OF_STUDENTS = 5;
    
    Student s[NUMBER_OF_STUDENTS];
    
    importFile(s, NUMBER_OF_STUDENTS);  // Used for importing student data from a text file
    
    //input(s, NUMBER_OF_STUDENTS); // Ued for manually importing student data
    calc(s, NUMBER_OF_STUDENTS);
    grade(s, NUMBER_OF_STUDENTS);
    print(s, NUMBER_OF_STUDENTS);
    outputFile(s, NUMBER_OF_STUDENTS);
    avg(s, NUMBER_OF_STUDENTS);
    results(s, NUMBER_OF_STUDENTS);
    
    return 0;
}





//Student Name:            Peters, Kevin
//Total Homework Points:   62
//Total Exam Points:       164
//Class Percentage:        82.27%
//Final Grade:             B
//
//
//Student Name:            Barth, Mary
//Total Homework Points:   70
//Total Exam Points:       195
//Class Percentage:        95.84%
//Final Grade:             A
//
//
//Student Name:            James, Chris
//Total Homework Points:   51
//Total Exam Points:       133
//Class Percentage:        67.10%
//Final Grade:             D
//
//
//Student Name:            Student, Lousy
//Total Homework Points:   8
//Total Exam Points:       10
//Class Percentage:        7.27%
//Final Grade:             F
//
//
//Student Name:            Adams, Larry
//Total Homework Points:   47
//Total Exam Points:       160
//Class Percentage:        73.07%
//Final Grade:             C
//
//
//The class average for
//Exam 1 Scores:           62.20%
//Exam 2 Scores:           70.20%
//
//Grade Breakdown:
//A:   1
//B:   1
//C:   1
//D:   1
//F:   1
//
//Program ended with exit code: 0

