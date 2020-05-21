#ifndef DOCUMENT_H_INCLUDED
#define DOCUMENT_H_INCLUDED

#include "element.h"
#include "text_element.h"

class Document : public Element {
    private:
        Element *head;
        Element *title;
        Element *body;

    public:
        Document(string title) : Element("html") {
            head = new Element("head");
            this->title = new Element("title");
            this->title->addChild(new TextElement(title));
            body = new Element("body");

            head->addChild(this->title);

            children.push_back(head);
            children.push_back(body);
        }

        virtual void addElementToHead(Element *el) {
            head->addChild(el);
        }

        virtual void removeElementFromHead(size_t index) {
            head->removeChild(index);
        }

        virtual void addElementToBody(Element *el) {
            body->addChild(el);
        }

        virtual void removeElementFromBody(size_t index) {
            body->removeChild(index);
        }

        virtual void render(int depth = 0) {
            cout << "<!DOCTYPE html>" << endl;
            Element::render(depth);
        }
};

#endif // DOCUMENT_H_INCLUDED
