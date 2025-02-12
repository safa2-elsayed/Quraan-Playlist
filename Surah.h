#pragma once
#pragma once
#include <string>
#include<ostream>
using namespace std;

class Surah {
private:
    string name;
    string type;
    string path;

public:

    Surah();
    Surah(const string&, const string&, const string&);
    Surah(string);
    ~Surah();
    Surah(const Surah&);
    Surah& operator=(const Surah&);
    void setAttributes(const string&, const string&, const string&);
    void setName(const string&);
    void setType(const string&);
    void setPath(const string&);
    string getName() const;
    string getType() const;
    string getPath() const;
    bool operator==(Surah);
    friend ostream& operator<<(ostream&, Surah);
};


