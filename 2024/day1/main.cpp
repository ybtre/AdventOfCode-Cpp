#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
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
    vector<string> PuzzleArray = GetPuzzleString("input.txt", false);

    vector<string> left = {};
    vector<string> right = {};
    for (auto& line : PuzzleArray)
    {
        size_t pos = line.find("   ");
        left.push_back(line.substr(0, pos));
        right.push_back(line.substr(pos+2, line.size()));
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int total_dist = 0;
    for (int i = 0; i < left.size(); i++)
    {
        auto a = left[i];
        auto b = right[i];
        
        total_dist += abs(stoi(a)-stoi(b));
    }
    cout << "Answer: " << total_dist << endl;

    // for ( auto l : left)
    // {g
    //     cout << l << endl;
    // }
    // cout << ".." << endl;
    //
    // for ( auto l : right)
    // {
    //     cout << l << endl;
    // }
}

void part2()
{
    vector<string> PuzzleArray = GetPuzzleString("input.txt");

    vector<string> left = {};
    vector<string> right = {};
    for (auto& line : PuzzleArray)
    {
        size_t pos = line.find("   ");
        left.push_back(line.substr(0, pos));
        right.push_back(line.substr(pos+2, line.size()));
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int similarity = 0;
    for (int i = 0; i < left.size(); i++)
    {
        auto a = left[i];
        int matches = 0;
        for(int j = 0; j < right.size(); j++)
        {
            auto b = right[j];

            if ( stoi(a) == stoi(b) )
            {
                matches++;
            }
        }
        
        similarity += stoi(a) * matches;
    }
    cout << "Answer: " << similarity << endl;

    // for ( auto l : left)
    // {g
    //     cout << l << endl;
    // }
    // cout << ".." << endl;
    //
    // for ( auto l : right)
    // {
    //     cout << l << endl;
    // }
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


