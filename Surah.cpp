#include "Surah.h"
#include <iostream>
#include<iomanip>
using namespace std;

Surah::Surah() {}

Surah::Surah(const string& surahName, const string& surahType, const string& imagePath)
    : name(surahName), type(surahType), path(imagePath) {
}

Surah::Surah(string surahName) :name(surahName) {}

Surah::~Surah() {}

Surah::Surah(const Surah& other)
    : name(other.name), type(other.type), path(other.path) {
}

Surah& Surah::operator=(const Surah& other)
{
    if (this != &other) {
        name = other.name;
        type = other.type;
        path = other.path;
    }
    return *this;
}

void Surah::setAttributes(const string& surahName, const string& surahType, const string& imagePath)
{
    name = surahName;
    type = surahType;
    path = imagePath;
}


void Surah::setName(const string& surahName)
{
    name = surahName;
}

void Surah::setType(const string& surahType)
{
    type = surahType;
}

void Surah::setPath(const string& imagePath)
{
    path = imagePath;
}


string Surah::getName() const
{
    return name;
}

string Surah::getType() const
{
    return type;
}

string Surah::getPath() const
{
    return path;
}
bool Surah::operator==(Surah surah)
{
    return (this->name == surah.name);
}
ostream& operator<<(ostream& COUT, Surah surah)
{
    COUT << setw(20) << surah.name << setw(20) << surah.type << setw(20) << surah.path << endl;
    return COUT;
}
