#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Passaport
{

public:
    int birthYear = -1;
    int issueYear = -1;
    int expirationYear = -1;
    int height = -1;
    string hairColor = "Null";
    string eyeColor = "Null";
    string passportID = "Null";
    int countryID = -1;

    Passaport(string line)
    {
        int tknS, tknE;
        string parameterName;

        while (line.length() != 0)
        {
            tknS = line.find(":");
            parameterName = line.substr(tknS - 3, 3);
            tknE = line.find(" ", tknS);
            dataStore(parameterName, line.substr(tknS + 1, tknE - tknS - 1));
            line = line.substr(tknE + 1, line.length());
        }
    }

    int checkIfValidP1()
    {
        if (
            birthYear != -1 &&
            issueYear != -1 &&
            expirationYear != -1 &&
            height != -1 &&
            hairColor != "Null" &&
            eyeColor != "Null" &&
            passportID != "Null"
            // countryID != -1 &&
        )
        {
            return 1;
        }
        else
            return 0;
    }

private:
    void dataStore(string parameterName, string parameter)
    {

        if (parameterName == "byr")
            birthYear = stoi(parameter);
        if (parameterName == "iyr")
            issueYear = stoi(parameter);
        if (parameterName == "eyr")
            expirationYear = stoi(parameter);
        if (parameterName == "hgt")
        {
            // TODO parse hgt cm and in
            height = stoi(parameter);
        }

        if (parameterName == "hcl")
            hairColor = parameter;
        if (parameterName == "ecl")
            eyeColor = parameter;
        if (parameterName == "pid")
        {
            passportID = parameter;
            // cout << parameter << "\n";
        }
        if (parameterName == "cid")
            countryID = stoi(parameter);
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    string line;
    string fullMessage = "";
    vector<Passaport> database{};
    // !!WARNING!! needs a \n\n at the end of the data!!!
    while (getline(cin, line))
    {

        if (line != "")
        {
            // cout << line << "\n";
            fullMessage.append(" ");
            fullMessage.append(line.substr(0, line.length()));
        }
        else
        {

            // cout.precision(10);
            // cout << "\n"
            //      << fullMessage << "\n";

            fullMessage.append(" ");
            // validate on creation!!
            // if you cant create you dont add
            // all you need to do is count the total!
            Passaport pass(fullMessage);
            database.push_back(pass);

            // cout << database.size() << "\n";
            fullMessage = "";

            // cout << "birth = " << pass.birthYear;
            // cout << " countryID = " << fixed << pass.countryID;
            // cout << " expirationYear = " << pass.expirationYear;
            // cout << " eyeColor = " << pass.eyeColor;
            // cout << " passportID = " << pass.passportID;
            // cout << " hairColor = " << pass.hairColor;
            // cout << " issueYear = " << pass.issueYear;
            // cout << " height = " << pass.height << "\n";
        }
    }
    int validPassports = 0;
    for (Passaport &passaport : database)
    {
        validPassports = validPassports + passaport.checkIfValidP1();
    }

    cout << validPassports << "\n";
}
