#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
    // string Name;
    // /*****************************************/
    // cout << "Student Enter Name" << endl;
    // cin >> Name;
    // cout << "---------  -------------------------------------" << endl;
    // cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
    // cout << "Student Name: " << Name << endl;
    // cout << "----------------------------------------------" << endl;
    // /*****************************************/
    ifstream stream{"Hemingway.txt"};
    string line;
    char *heap_line = NULL;
    vector<char *> c_string_array;
    int line_count = 0;
    if (!stream)
    {
        cout << "Could not open file" << endl;
        return -1;
    }

    while (!stream.eof())
    {
        getline(stream, line);
        if (!stream.fail())
        {
            // cout << line << endl;
            // line_count++;

            const char *char_line = line.c_str();
            const int len = strlen(char_line);
            heap_line = new char[len];
            for (int i = 0; i < len; i++)
            {
                heap_line[i] = char_line[i];
            }

            for (int i = 0; i < len; i++)
            {
                cout << heap_line[i];
            }
            cout << endl;
            //       cout<<myString[i]<<" ";
            //   }
            // const char* heap_line = new char;

            c_string_array.push_back(heap_line);
        }
    }

    stream.close();

    return 0;
}