#include <iostream>

#include "attribute.h"
#include "element.h"
#include "document.h"
#include "empty_element.h"
#include "text_element.h"

using namespace std;

int main()
{
    Document *doc = new Document("Test document");
    Element *content = new Element("div");
    content->addAttribute(new Attribute("class", "container"));

    Element *paragraph = new Element("p");
    paragraph->addChild(new TextElement("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec sit amet metus varius, pellentesque erat a, rhoncus sapien."));

    Element *img = new EmptyElement("img");
    img->addAttribute(new Attribute("src", "image.jpg"));
    img->addAttribute(new Attribute("alt", "image"));
    img->addAttribute(new Attribute("width", "100"));

    content->addChild(paragraph);
    content->addChild(img);

    doc->addElementToBody(content);
    doc->render();
    return 0;
}
