#include <iostream>
#include <fstream>

using namespace std;

int isTree(char c);

class PosTracker
{
public:
    int _current;
    int _lineLen;
    int _step;

    PosTracker() {}

    PosTracker(int lineLen, int step)
    // : _current(step), _lineLen(lineLen), _step(step)
    {
        // user needs to count from 1
        // considers that we move x + 1 positions in the 1s step
        _current = step;
        _lineLen = lineLen - 1;
        _step = step;
    }
    int next()
    {

        if (_current + _step > _lineLen)
        {
            _current = _current + _step - _lineLen - 1;
        }
        else
        {
            _current = _current + _step;
        }
        return _current;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    string line;
    int lineNumber;
    int trees = 0;
    getline(cin, line);
    PosTracker posTracker(line.length(), 3);
    // cout << trees << " - " << line.substr(0, posTracker._current) << line.at(posTracker._current) << "\n";
    while (getline(cin, line))
    {
        trees = trees + isTree(line.at(posTracker._current));
        // cout << trees << " - " << line.substr(0, posTracker._current) << line.at(posTracker._current) << "\n";
        posTracker.next();
    }

    cout << trees << "\n";
}

int isTree(char c)
{
    if (c == '#')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
