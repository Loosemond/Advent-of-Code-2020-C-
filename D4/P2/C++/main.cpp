#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

using namespace std;

class Passaport
{

public:
    // TODO Make the params private and create getters
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

    bool setBirthYear(int _birthYear)
    {
        if (_birthYear >= 1920 && _birthYear <= 2002)
        {
            birthYear = _birthYear;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool setIssueYear(int _issueYear)
    {
        if (_issueYear >= 2010 && _issueYear <= 2020)
        {
            issueYear = _issueYear;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool setExpirationYear(int _expirationYear)
    {
        if (_expirationYear >= 2020 && _expirationYear <= 2030)
        {
            expirationYear = _expirationYear;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool setHight(string _height)
    {
        int cache;
        if (_height.find("cm") != -1)
        {
            cache = stoi(_height.substr(0, _height.find("cm")));
            if (cache >= 150 && cache <= 193)
            {
                height = cache;
                return true;
            }
        }
        else if (_height.find("in") != -1)
        {
            cache = stoi(_height.substr(0, _height.find("in")));
            if (cache >= 59 && cache <= 76)
            {
                height = cache;
                return true;
            }
        }
        // cout << _height << "\n";
        return false;
    }

    bool setHairColor(string _hairColor)
    {
        regex regex(R"(\#[A-Fa-f0-9]{6})");
        cmatch match;
        regex_match(_hairColor.c_str(), match, regex);

        for (auto &hexColor : match)
        {
            if (hexColor != "")
            {
                hairColor = hexColor;
                return true;
            }
            else
            {
                // cout << _hairColor << "\n";
                return false;
            }
        }
        return false;
    }

    bool setEyeColor(string _eyeColor)
    {
        if (_eyeColor == "amb" ||
            _eyeColor == "blu" ||
            _eyeColor == "brn" ||
            _eyeColor == "gry" ||
            _eyeColor == "grn" ||
            _eyeColor == "hzl" ||
            _eyeColor == "oth"

        )
        {
            eyeColor = _eyeColor;
            return true;
        }
        return false;
    }

    bool setPassportID(string _passportID)
    {

        regex regex(R"([0-9]{9})");
        cmatch match;
        regex_match(_passportID.c_str(), match, regex);

        for (auto &pNumber : match)
        {
            if (pNumber != "")
            {
                passportID = pNumber;
                // cout << _passportID << " len: " << _passportID.length() << "\n";

                return true;
            }
            else
            {
                // cout << _passportID << " len: " << _passportID.length() << "\n";
                return false;
            }
        }
        return false;
    }

private:
    void
    dataStore(string parameterName, string parameter)
    {

        if (parameterName == "byr")
            setBirthYear(stoi(parameter));
        if (parameterName == "iyr")
            setIssueYear(stoi(parameter));
        if (parameterName == "eyr")
            setExpirationYear(stoi(parameter));
        if (parameterName == "hgt")
            setHight(parameter);
        if (parameterName == "hcl")
            setHairColor(parameter);
        if (parameterName == "ecl")
            setEyeColor(parameter);
        if (parameterName == "pid")
        {
            setPassportID(parameter);
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
            // if (pass.checkIfValidP1() == 0)
            // {
            //     cout << fullMessage;
            //     cout << " valid: " << pass.checkIfValidP1() << "\n";

            //     cout << "birth = " << pass.birthYear;
            //     cout << " countryID = " << fixed << pass.countryID;
            //     cout << " expirationYear = " << pass.expirationYear;
            //     cout << " eyeColor = " << pass.eyeColor;
            //     cout << " passportID = " << pass.passportID;
            //     cout << " hairColor = " << pass.hairColor;
            //     cout << " issueYear = " << pass.issueYear;
            //     cout << " height = " << pass.height << "\n\n";
            // }
            fullMessage = "";
        }
    }
    int validPassports = 0;
    for (Passaport &passaport : database)
    {
        validPassports = validPassports + passaport.checkIfValidP1();
    }

    cout << validPassports << "\n";
}
