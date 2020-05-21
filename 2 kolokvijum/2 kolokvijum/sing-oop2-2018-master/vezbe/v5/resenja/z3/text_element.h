#ifndef TEXT_ELEMENT_H_INCLUDED
#define TEXT_ELEMENT_H_INCLUDED

#include "element.h"

class TextElement : public Element {
    private:
        string content;
    public:
        TextElement(string content) : Element(""), content(content) {};
        virtual void render(int depth=0) {
            cout << content << endl;
        }
};

#endif // TEXT_ELEMENT_H_INCLUDED
