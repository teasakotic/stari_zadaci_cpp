#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <iostream>
#include <vector>

#include "drawable.h"
#include "tileset.h"

using namespace std;

/** \brief Klasa kojom se opisuje jedan nivo igre.
 */
class Level : public Drawable {
private:
    Tileset *tileset;
    vector<vector<char>> level;
public:
    /** \brief Konstruktor klase Level.
     *
     * Popunjava atribute na osnovu zadatog toka i pokazivača na instancu klase Tileset.
     *
     * \param inputStream Ulazni tok sa kojeg će biti učitan sadržaj nivoa.
     * \param tileset Pokazivač na instancu klase Tileset.
     *
     */
    Level(istream &inputStream, Tileset *tileset);
    /** \brief Implementacija draw metode iz apstraktne klase Drawable.
     *
     * \param renderer Renderer koji vrši iscrtavanje.
     * \return virtual void
     *
     */
    virtual void draw(SDL_Renderer * renderer);
    ~Level();
};

#endif // LEVEL_H_INCLUDED
