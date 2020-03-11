/*
 Exam 2 Program
 David Lascelles
 2/7/2018
 */

#include <iostream>
#include <fstream>
using namespace std;

template <class T>
void loadArray (T *a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a value: ";
        cin >> a[i];
    }
}


template <class T>
void large2 (T *a, const int n)
{
    T large = a[0];
    
    for (int i = 1; i < n; i++)             // finds index of largest value
        if (a[i] > large)
            large = a[i];
    
    T nextLarge = a[0];
    if (nextLarge == large)
        nextLarge = a[1];
    
    for (int i = 0; i < n; i++)             // finds index of second largest value
        if (a[i] != large && a[i] > nextLarge)
            nextLarge = a[i];
    
    cout << "The second largest value of the array is: " << nextLarge << endl;
}

template <class T>
void sortArray (T *a, const int n)
{
    for (int i = (a[n-1] == '\0') ? n - 2 : n - 1; i >= 0; i--)     // conditional ternary statement for i checks
    {                                                               // for char array, ensures null char stays at the end of the string
        for (int j = 1; j <= i; j++)
        {
            if (a[j-1] > a[j])
            {
                T temp = a[j-1];                // swaps values
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
}

template <class T>
void printarray (T *a, const int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;
}

class fileManip
{
    public:
        int save(int *a, const int n)
        {
            ofstream outfile("intArrayFile.txt", ios::out);
            for (int i = 0; i < n; i++)
                outfile << a[i] << " ";
            outfile.close();
            return 0;
        }
    
        int save(float *a, const int n)
        {
            ofstream outfile("floatArrayFile.txt", ios::out);
            for (int i = 0; i < n; i++)
                outfile << a[i] << " ";
            outfile.close();
            return 0;
        }
    
        int save(char *a, const int n)
        {
            ofstream outfile("charArrayFile.txt", ios::out);
            for (int i = 0; i < n; i++)
                outfile << a[i] << " ";
            outfile.close();
            return 0;
        }
    
        int retrieve(int *a, const int n)
        {
            ifstream infile("intArrayFile.txt", ios::in);
        
            for (int i = 0; i < n; i++)
                infile >> a[i];
            infile.close();
            return 0;
        }
    
        int retrieve(float *a, const int n)
        {
            ifstream infile("floatArrayFile.txt", ios::in);
            
            for (int i = 0; i < n; i++)
                infile >> a[i];
            infile.close();
            return 0;
        }
    
        int retrieve(char *a, const int n)
        {
            ifstream infile("charArrayFile.txt", ios::in);
            
            for (int i = 0; i < n; i++)
                infile >> a[i];
            infile.close();
            return 0;
        }
};

int main()
{
    const int n1 = 5, n2 = 7, n3 = 6;  // array sizes
    
    int a[n1];
    float b[n2];
    char c[n3];
    
    fileManip f;
    
    cout << endl << "Enter integer values into int array: " << endl;
    loadArray(a, n1);
    cout << endl << "Enter float values into float array: " << endl;
    loadArray(b, n2);
    cout << endl << "Enter char values into char array: " << endl;
    loadArray(c, n3);
    
    cout << endl;
    large2(a, n1);
    large2(b, n2);
    large2(c, n3);
    
    sortArray(a, n1);
	sortArray(b, n2);
	sortArray(c, n3);

    cout << endl << "The integer array before file save: " << endl;
    printarray(a, n1);
    cout << "The float array before file save: " << endl;
    printarray(b,n2);
    cout << "The string is before file save: " << endl;
    printarray(c,n3);
    
    f.save(a, n1);
    f.save(b, n2);
	f.save(c, n3);
    
    f.retrieve(a, n1);
    f.retrieve(b, n2);
    f.retrieve(c, n3);
    
    cout << endl << "The integer array after file save: " << endl;
    printarray(a, n1);
    cout << "The float array after file save: " << endl;
    printarray(b, n2);
    cout << "The string after file save: " << endl;
	printarray(c, n3);
    
    return 0;
}

/*
 Enter integer values into int array:
 Enter a value: 8
 Enter a value: 7
 Enter a value: 6
 Enter a value: 5
 Enter a value: 4
 
 Enter float values into float array:
 Enter a value: 7.7
 Enter a value: 6.6
 Enter a value: 5.5
 Enter a value: 4.4
 Enter a value: 3.3
 Enter a value: 2.2
 Enter a value: 1.1
 
 Enter char values into char array:
 Enter a value: f
 Enter a value: e
 Enter a value: d
 Enter a value: c
 Enter a value: b
 Enter a value: a
 
 The second largest value of the array is: 7
 The second largest value of the array is: 6.6
 The second largest value of the array is: e
 
 The integer array before file save:
 4  5  6  7  8
 The float array before file save:
 1.1  2.2  3.3  4.4  5.5  6.6  7.7
 The string is before file save:
 a  b  c  d  e  f
 
 The integer array after file save:
 4  5  6  7  8
 The float array after file save:
 1.1  2.2  3.3  4.4  5.5  6.6  7.7
 The string after file save:
 a  b  c  d  e  f
 Program ended with exit code: 0
*/
