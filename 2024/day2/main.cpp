#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <sstream> 
using namespace std;

std::vector<string> GetPuzzleString(string input_file_name, bool printInput = true)
{
    vector<string> outputText;

    cout << "~~~~~~~~~ INPUT ~~~~~~~~~~~~" << endl;

    ifstream file(input_file_name);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            outputText.emplace_back(line);
            if (printInput)
            {
                cout << line << endl;
            }
        }
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    return outputText;
}

void part1()
{
    vector<string> PuzzleArray = GetPuzzleString("example.txt", true);

    map<int, vector<int>> line_numbers = {};
    for(int i = 0; i < PuzzleArray.size(); i++)
    {
        auto line = PuzzleArray[i];

        stringstream ss(line);
        string tmp;
        while (getline(ss, tmp, ' '))
        {
            line_numbers[i].push_back(stoi(tmp));
        }
    }

    cout << "~~~~~~~~~ Parsed Data ~~~~~~~~~~~~" << endl;
    for(int i = 0; i < line_numbers.size(); i++)
    {
        cout << i << " - ";
        for (auto n : line_numbers[i])
        {
            cout << n << " ";
        }

        cout << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;

    int safe = 0;
    for(int i = 0; i < line_numbers.size(); i++)
    {
        int prev_num = 0;
        int counter = 0;
        bool ascending = false;
        bool was_asc = false;
        for (auto n : line_numbers[i])
        {
            if (counter == 0)
            {
                prev_num = n;
                continue;
            }

            if (n > prev_num)
            {
                ascending = true;
            }
            else if (n < prev_num)
            {
                ascending = false;
            }

            counter++;
        }

        cout << endl;
    }


    // cout << "Answer: " << total_dist << endl;
}

void part2()
{

}

int main()
{
    cout << "~~~~~~~~~ Part 1 ~~~~~~~~~~~~" << endl;
    part1();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "~~~~~~~~~ Part 2 ~~~~~~~~~~~~" << endl;
    part2();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    return 0;
}


