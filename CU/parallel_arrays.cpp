#include <iostream>
#include <string>

using namespace std;

int main()
{
    int maxStudents;
    cout << "Kitne students ke data store karna chahte hain? ";
    cin >> maxStudents;

    string uids[maxStudents];
    string names[maxStudents];
    int ages[maxStudents];
    double marksPercent[maxStudents];

    for (int i = 0; i < maxStudents; i++)
    {
        cout << "Enter student " << i + 1 << " ka UID: ";
        cin >> uids[i];

        cout << "Enter student " << i + 1 << " ka naam: ";
        cin >> names[i];

        cout << "Enter student " << i + 1 << " ki umar: ";
        cin >> ages[i];

        cout << "Enter student " << i + 1 << " ke marks percentage: ";
        cin >> marksPercent[i];
    }

    cout << "\nStudent data:\n";
    for (int i = 0; i < maxStudents; i++)
    {
        cout << "UID: " << uids[i] << ", Name: " << names[i] << ", Age: " << ages[i] << ", Marks Percentage: " << marksPercent[i] << "%" << endl;
    }

    string tryAgain;
    cout << "Kya aap phir se try karna chahte hain? (yes/no): ";
    cin >> tryAgain;

    if (tryAgain == "y" || tryAgain == "Y")
    {
        main();
    }
    else
    {
        cout << "Dhanyavaad! Program samapt ho gaya." << endl;
    }

    return 0;
}
