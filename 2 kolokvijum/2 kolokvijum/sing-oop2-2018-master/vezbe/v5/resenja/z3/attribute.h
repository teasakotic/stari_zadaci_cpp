#ifndef ATTRIBUTE_H_INCLUDED
#define ATTRIBUTE_H_INCLUDED

#include <string>

using namespace std;

class Attribute {
    public:
        string name;
        string value;
        Attribute(string name, string value) : name(name), value(value) {};
        string str() {
            return name + "=\"" + value + "\"";
        }
};

#endif // ATTRIBUTE_H_INCLUDED
