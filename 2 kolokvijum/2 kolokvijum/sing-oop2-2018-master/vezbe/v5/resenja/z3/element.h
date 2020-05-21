#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#include <iostream>
#include <vector>

#include "attribute.h"

using namespace std;

class Element {
    protected:
        string name;
        vector<Attribute*> attributes;
        vector<Element*> children;

    public:
        Element(string name) : name(name) {};
        virtual void addAttribute(Attribute *attr) {
            attributes.push_back(attr);
        }
        virtual void removeAttribute(size_t index) {
            attributes.erase(attributes.begin()+index);
        }
        virtual void addChild(Element *el) {
            children.push_back(el);
        }
        virtual void removeChild(size_t index) {
            children.erase(children.begin()+index);
        }

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

            cout << ">" << endl;

            for(size_t i = 0; i < children.size(); i++) {
                for(int j = 0; j < depth+1; j++) {
                    cout << "   ";
                }
                children[i]->render(depth+1);
            }

            for(int i = 0; i < depth; i++) {
                cout << "   ";
            }
            cout << "</" << name << ">" << endl;
        }
};

#endif // ELEMENT_H_INCLUDED
