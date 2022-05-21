#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <map>
#include <sstream>
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

    while (!stream.eof() && line_count++ <= 40)
    {
        getline(stream, line);
        if (!stream.fail())
        {

            // // const char *c_string = line.c_str();
            // const int len = strlen(c_string);
            const int len = line.length();
            heap_line = new char[len + 1];

            for (int i = 0; i < len; i++)
            {
                heap_line[i] = line.at(i);
                // heap_line[i] = c_string[i];
            }

            heap_line[len] = '\0';

            c_string_array.push_back(heap_line);
        }
    }

    int count = 1;
    for (vector<char *>::iterator iter = c_string_array.begin(); iter != c_string_array.end(); iter++)
    {

        cout << count++ << ": " << *iter << endl;
    }

    cout << "\n**********Updated Version (Moved line 10-13)*********" << endl;
    int first = 9;
    int last = 13;
    for (int i = first; i < last; i++)
    {
        c_string_array.push_back(c_string_array.at(i));
    }
    c_string_array.erase(c_string_array.begin() + first, c_string_array.begin() + last);

    count = 1;
    for (vector<char *>::iterator iter = c_string_array.begin(); iter != c_string_array.end(); iter++)
    {

        cout << count++ << ": " << *iter << endl;
    }

    // cout << "Line count is: " << line_count << endl;
    stream.close();

    cout << "\n*****************" << endl;
    // stringstream string_stream;
    map<string, int> word_map;

    int word_count = 0;
    for (vector<char *>::iterator iter = c_string_array.begin(); iter != c_string_array.end(); iter++)
    {
        stringstream string_stream;
        string sample(*iter), word("");
        size_t pos = sample.find(" ");

        string_stream << sample;
        while (string_stream >> word)
        {
            if ((word.at(word.length() - 1) == '.') || (word.at(word.length() - 1) == ','))
            {
                word.erase(word.length() - 1, 1);
            }
            word_count++;
            word_map[word] = word.length();
        }
    }

    cout << "\n***********UNIQUE WORDS AND TOTAL NUMBER OF WORDS************" << endl;
    int map_count = 0;
    for (map<string, int>::iterator iter = word_map.begin(); iter != word_map.end(); iter++)
    {
        cout << "\"" << iter->first << "\", length: " << iter->second << endl;
        cout << "------------" << endl;
        map_count++;
    }
    cout << "Total Number of Words: " << word_count << endl;
    cout << "Total Number of Unique Words: " << map_count << endl;

    const int len = 8;
    cout << "\n***********WORDS WITH LENGTH LESS THAN 8************" << endl;
    for (map<string, int>::iterator iter = word_map.begin(); iter != word_map.end(); iter++)
    {
        if (iter->first.length() < len)
        {
            cout << "\"" << iter->first << "\", length: " << iter->second << endl;
            cout << "------------" << endl;
        }
    }

    for (vector<char *>::iterator iter = c_string_array.begin(); iter != c_string_array.end(); iter++)
    {
        delete *iter;
    }

    return 0;
}