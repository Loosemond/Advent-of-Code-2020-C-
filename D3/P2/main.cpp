#include <iostream>
#include <fstream>

using namespace std;

int isTree(char c);

class TreeTracker
{
public:
    int _current;
    int _lineLen;
    int _step;
    double _trees = 0;
    int _lineCount = 1;
    int _lineStep;

    TreeTracker() {}

    TreeTracker(int lineLen, int step, int lineStep)
    {
        // user needs to count from 1
        // considers that we move x + 1 positions in the 1s step
        _current = step;
        _lineLen = lineLen - 1;
        _step = step;
        _lineStep = lineStep;
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

    void CheckLineAddTree(string line)
    {

        if (_lineCount + 1 > _lineStep)
        {
            _trees = _trees + isTree(line.at(getCurrentSetNext()));
            _lineCount = 1;
        }
        else
        {
            _lineCount++;
        }
    }

    int getCurrentSetNext()
    {
        int current = _current;
        next();
        return current;
    }

    int addTree(string line)
    {
        _trees = _trees + isTree(line.at(getCurrentSetNext()));
        return 0;
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
};

int main()
{
    freopen("input.txt", "r", stdin);
    string line;
    int lineNumber;
    getline(cin, line);
    TreeTracker r1d1(line.length(), 1, 1);
    TreeTracker r3d1(line.length(), 3, 1);
    TreeTracker r5d1(line.length(), 5, 1);
    TreeTracker r7d1(line.length(), 7, 1);
    TreeTracker r1d2(line.length(), 1, 2);

    while (getline(cin, line))
    {
        //r1d1._trees = r1d1._trees + isTree(line.at(r1d1.getCurrentSetNext()));
        r1d1.CheckLineAddTree(line);
        r3d1.CheckLineAddTree(line);
        r5d1.CheckLineAddTree(line);
        r7d1.CheckLineAddTree(line);
        r1d2.CheckLineAddTree(line);
    }

    printf("%.0f\n", r1d1._trees * r3d1._trees * r5d1._trees * r7d1._trees * r1d2._trees);
}
