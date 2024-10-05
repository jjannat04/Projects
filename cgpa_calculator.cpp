#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, roll;
    string s;
    
    cout << "Enter your name: ";
    
    getline(cin, s);
    
    cout << "Hello " << s << "! Welcome to CGPA Calculator" << endl;
    cout << "Enter your student ID: ";
    cin >> roll;


    cout << "Enter the number of subjects you took this semester: ";
    cin >> n;

    double sum_of_weighted_grade_points = 0;
    double total_credits = 0;
    
    vector <string> subject(n);
    vector <double> credit(n);
    vector <double> gpa(n);
    cout << "Enter each subject's name, total credits and GPA one by one\n" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of Subject number " << i+1 << ": ";
        cin >> subject[i];
        cout << "Enter total credits for " << subject[i] << ": ";
        cin >> credit[i];
        while (credit[i] < 0)
        {
            cout << "Invalid Credit.\nEnter total credits for " << subject[i] << ": ";
            cin >> credit[i];
        }
        cout << "Enter your GPA for " << subject[i] << ": ";
        cin >> gpa[i];
        while (gpa[i] > 4.00 || gpa[i] < 0)
        {
            cout << "Invalid GPA.\nEnter your GPA for " << subject[i] << ": ";
            cin >> gpa[i];
        }

        sum_of_weighted_grade_points += (credit[i] * gpa[i]);
        total_credits += credit[i];
        cout << endl;
    }
    double cgpa = sum_of_weighted_grade_points/total_credits;

    cout << "Student Name: " << s << "\n" << "Student ID: " << roll << endl;

    // Formatting output using setw
    cout << "----------------------------------------------------\n";
    cout << setw(15) << "Subject" << setw(15) << "Credits" << setw(15) << "GPA" << endl;
    cout << "----------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << setw(15) << subject[i] << setw(15) << credit[i] << setw(15) << gpa[i] << endl;
    }

    cout << "----------------------------------------------------\n";
    cout << fixed << setprecision(2) << "Your CGPA is: " << cgpa << endl;
    
}