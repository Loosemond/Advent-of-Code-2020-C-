#include <iostream>
#include <fstream>
// #include <vector>
// #include <regex>

using namespace std;

int main()
{

    freopen("input.txt", "r", stdin);
    string line;
    int place = 127;
    int upperRows, lowerRows, upperColum, lowerColum, highest, seatID;
    highest = 0;

    while (getline(cin, line))
    {
        upperRows = 127;
        lowerRows = 0;
        upperColum = 7;
        lowerColum = 0;
        for (char &c : line)
        {
            if (c == 'F')
            {
                upperRows = lowerRows + (upperRows - lowerRows) / 2;
                lowerRows = lowerRows;
            }
            else if (c == 'B')
            {
                lowerRows = lowerRows + (upperRows - lowerRows) / 2 + 1;
                upperRows = upperRows;
            }

            if (c == 'L')
            {
                upperColum = lowerColum + (upperColum - lowerColum) / 2;
                lowerColum = lowerColum;
            }
            else if (c == 'R')
            {
                lowerColum = lowerColum + (upperColum - lowerColum) / 2 + 1;
                upperColum = upperColum;
            }
        }
        seatID = upperRows * 8 + upperColum;

        if (highest < seatID)
            highest = seatID;
    }

    cout << highest << "\n";
}