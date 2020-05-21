#ifndef EMPTY_ELEMENT_H_INCLUDED
#define EMPTY_ELEMENT_H_INCLUDED

#include "element.h"

class EmptyElement : public Element {
    public:
        EmptyElement(string name) : Element(name) {};
        virtual void render(int depth=0) {
            cout << "<" << name;

            if(attributes.size() > 0) {
                cout << " ";
            }

            for(size_t i = 0; i < attributes.size(); i++) {
                cout << attributes[i]->str();
                if(i != attributes.size()-1) {
                    cout << " ";
                }
            }

            cout << "/>" << endl;
        }
};

#endif // EMPTY_ELEMENT_H_INCLUDED
