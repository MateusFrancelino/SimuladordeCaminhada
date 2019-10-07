#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <stdlib.h>
using namespace std;
#include <SDL2/SDL.h>
struct Player{
    int vida = 3;
    SDL_Rect origem={0,0,0,0};
    SDL_Rect destino={0,0,0,0};
    SDL_Rect ataqueorigem{0,0,0,0};
    SDL_Rect ataquedestino{0,0,0,0};
    SDL_Rect paradorigem{0,0,0,0};
    SDL_Rect* paradodestino =&destino;
    SDL_Rect adicional{0,0,0,0};


};


struct Mapa {

    SDL_Rect origem={0,0,0,0};
    SDL_Rect destino={0,0,0,0};

};










SDL_Texture *Carrega (const char* imgtx,SDL_Renderer* render);
void CriaCavaleiro(Player* Cavaleiro);
void Criainimigo(Player *inimigo);





#endif // FUNCTIONS_H
