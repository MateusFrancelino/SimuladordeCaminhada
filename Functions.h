#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <stdlib.h>
using namespace std;
#include <SDL2/SDL.h>

struct val_info{
    int vida = 3;
    bool ataque=0;
    bool defesa=0;

};
struct val_anim{
    //F= Numero de frames
    //P= Tamanho em pixeis
    int ParadoF=0;
    int ParadoP=0;
    int AtaqueF=0;
    int AtaqueP=0;
    int MorteF=0;
    int MorteP=0;
    int DanoF=0;
    int DanoP=0;
    int AndandoF=0;
    int AndandoP=0;
    int BloqF=0;
    int BloqP=0;


};
struct Player{
    SDL_Rect  origem={0,0,0,0};
    SDL_Rect  destino={0,0,0,0};
    SDL_Rect  ataqueorigem{0,0,0,0};
    SDL_Rect* ataquedestino=&destino;
    SDL_Rect  danorigem={0,0,0,0};
    SDL_Rect* danodestino=&destino;
    SDL_Rect  paradorigem{0,0,0,0};
    SDL_Rect* paradodestino =&destino;
    SDL_Rect  morte{0,0,0,0};
    SDL_Rect bloqorigem{0,0,0,0};

    SDL_Texture* Tparado;
    SDL_Texture* Tatacar;
    SDL_Texture* TDano;
    SDL_Texture* Tandando;
    SDL_Texture* Tmorte;
    SDL_Texture* TBloqueio;
    val_anim anima ;
    val_info info;
};
SDL_Texture *Carrega (const char* imgtx,SDL_Renderer* render);
void CriaCavaleiro(Player* Cavaleiro,SDL_Renderer* render);
void Criainimigo(Player *inimigo,SDL_Renderer* render);
void Paredes(Player* inimigo,SDL_Rect* camera,int x,int velocidade);
void Movimento(Player* Cavaleiro,Player* inimigo,SDL_Rect *camera ,int movimento);
void backup_anima(val_anim *auxanima);
void animation_principal(SDL_Renderer *render,Player* inimigo,Player* Cavaleiro,SDL_Texture* sky,SDL_Texture* chao,SDL_Rect *camera,SDL_Rect *cameradestino,bool parado);



#endif // FUNCTIONS_H
