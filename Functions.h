#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <stdlib.h>
using namespace std;
#include <SDL2/SDL.h>


struct val_anim{
    //F= Numero de frames
    //P= Tamanho em pixeis
    int ParadoF=0;
    int ParadoP=0;
    int AtaqueF=0;
    int AtaqueP=0;
    int MorteF=0;
    int MorteP=0;

};
struct Player{
    int vida = 3;
    SDL_Rect origem={0,0,0,0};
    SDL_Rect destino={0,0,0,0};
    SDL_Rect ataqueorigem{0,0,0,0};
    SDL_Rect* ataquedestino=&destino;
    SDL_Rect paradorigem{0,0,0,0};
    SDL_Rect* paradodestino =&destino;
    SDL_Rect adicional{0,0,0,0};
    SDL_Texture* Tparado;
    SDL_Texture* Tatacar;
    SDL_Texture* Tandando;
    SDL_Texture* Tmorte;
    val_anim anima ;

};






struct Mapa {

    SDL_Rect origem={0,0,0,0};
    SDL_Rect destino={0,0,0,0};

};










SDL_Texture *Carrega (const char* imgtx,SDL_Renderer* render);
void CriaCavaleiro(Player* Cavaleiro,SDL_Renderer* render);
void Criainimigo(Player *inimigo,SDL_Renderer* render);
void Paredes(Player* inimigo,SDL_Rect* camera,int x,int velocidade);
void Movimento(Player* Cavaleiro,Player* inimigo,SDL_Rect *camera ,int movimento,int morte);





#endif // FUNCTIONS_H
