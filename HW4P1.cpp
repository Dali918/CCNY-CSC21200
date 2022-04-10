#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    string Name, line;
    const int count_len = 32;
    int count_arr[count_len]{0};
    int index = 0;

    /*****************************************/
    cout << "Student Enter Name" << endl;
    cin >> Name;
    cout << "---------  -------------------------------------" << endl;
    cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
    cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
    /*****************************************/
    string fileName = "HW4message.txt";
    ifstream read{fileName};
    if (!read)
    {
        // Print an error and exit
        std::cerr << "message could not be opened for reading!\n";
        return 1;
    }
    else
    {
        cout << "File is open" << endl;
    }

    while (getline(read, line, '.'))
    {
        int sum = 0;
        for (int i = 0; i < line.length(); i++)
        {
            sum += (line.at(i) != ' ') ? line.at(i) : 0;
        }

        if (index < count_len)
        {
            cout << "Inputting at index: " << index;
            count_arr[index++] = sum;
            ;
        }
        else
        {
            cout << "Memory Full!" << endl;
        }
    }

    cout<<endl;
    for (int i = 0; i < count_len; i++)
    {
        if (count_arr[i] == 0)
            break;
        cout << "line: " << i << " sum: " << count_arr[i]<<endl;
    }

    return 0;
}