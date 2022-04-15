#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    /*Write a short program that reads phrases from the input stream and stores each new
    line into an array of C++ strings. For each new line, the program computes the
    numeric sum value of each phrase terminated with ‘\n’. For the following section of
    the Gettysburg Address store the numeric values of each phrase into a int cnt[32]
    array.*/
    
    string Name;
    /*****************************************/
    cout << "Student Enter Name" << endl;
    cin >> Name;
    cout << "---------  -------------------------------------" << endl;
    cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
    cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
    /*****************************************/

    string fileName = "HW4message.txt";
    ifstream read{fileName}; // read lines form text file

    if (!read)
    {
        // print an error and exit if file could not be opened in the stream
        std::cerr << "message could not be opened for reading!\n";
        read.close(); // close file stream
        return 1;
    }
    else
    {
        cout << "File is open" << endl;
    }
    // read phrases delimited by '.' and get their sum
    string line;
    string line_array[32];
    const int count_len = 32; // array length
    int count_arr[count_len]{0};
    int index = 0; // index of array
    while (getline(read, line, '.'))
    {
        int sum = 0;
        for (int i = 0; i < line.length(); i++)
        {
            sum += (line.at(i) != ' ') ? line.at(i) : 0; // ignore spaces
        }

        if (index < count_len)
        {
            cout << "Inputting at index: " << index << endl;
            line_array[index] = line; // insert phrase in string array
            count_arr[index++] = sum; // insert sum of phrase in sum array and increment index
        }
        else
        {
            cout << "Memory Full!" << endl; // stop insertion if array is full
            break;
        }
    }

    cout << endl;
    // print sums
    for (int i = 0; i < count_len; i++)
    {
        if (count_arr[i] == 0) // stop when sum is empty
            break;
        cout << "line: " << i + 1 << " sum: " << count_arr[i] << endl;
        cout << "Phrase: " << line_array[i] << endl;
        cout << "----------------------------------------------" << endl;
    }

    read.close(); // close file stream

    return 0;
}