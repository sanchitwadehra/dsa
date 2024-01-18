#include <iostream>
#include <string>
#include <algorithm> // For sorting

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

label:

    cout << "\nAge se oopar ke bachon ke data dekhna chahte hain? (yes/no): ";
    string ageChoice;
    cin >> ageChoice;

    int ageLimit = -1; 
    if (ageChoice == "yes" || ageChoice == "y" || ageChoice == "Y")
    {
        cout << "Age limit enter karein: ";
        cin >> ageLimit;
    }

    cout << "\nKya aap data ko sorted way mein dekhna chahte hain? (y/n): ";
    string sortChoice;
    cin >> sortChoice;

    if (sortChoice == "y" || sortChoice == "Y")
    {
        for (int i = 0; i < maxStudents - 1; i++)
        {
            for (int j = 0; j < maxStudents - i - 1; j++)
            {
                if (marksPercent[j] > marksPercent[j + 1])
                {
                    // Swap the elements
                    swap(uids[j], uids[j + 1]);
                    swap(names[j], names[j + 1]);
                    swap(ages[j], ages[j + 1]);
                    swap(marksPercent[j], marksPercent[j + 1]);
                }
            }
        }

        cout << "\nStudent data marks-wise sorted form mein:\n";
        for (int i = 0; i < maxStudents; i++)
        {
            if (ageLimit == -1 || ages[i] >= ageLimit)
            {
                cout << "UID: " << uids[i] << ", Name: " << names[i] << ", Age: " << ages[i] << ", Marks Percentage: " << marksPercent[i] << "%" << endl;
            }
        }
    }
    else
    {
        cout << "\nStudent data:\n";
        for (int i = 0; i < maxStudents; i++)
        {
            if (ageLimit == -1 || ages[i] >= ageLimit)
            {
                cout << "UID: " << uids[i] << ", Name: " << names[i] << ", Age: " << ages[i] << ", Marks Percentage: " << marksPercent[i] << "%" << endl;
            }
        }
    }

    string tryAgain;
    cout << "\nKya aap phir se try karna chahte hain? (y/n): ";
    cin >> tryAgain;

    if (tryAgain == "y" || tryAgain == "Y")
    {
        goto label;
    }
    else
    {
        cout << "Dhanyavaad! Program samapt ho gaya." << endl;
    }

    return 0;
}
