#include "Functions.h"
#include <SDL2/SDL.h>

SDL_Texture*Carrega(const char* imgtx,SDL_Renderer* render){
    SDL_Surface* img=SDL_LoadBMP(imgtx);
    SDL_Texture* textura=SDL_CreateTextureFromSurface(render,img);
    SDL_FreeSurface(img);
    return textura;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Cavaleiro
///
    void CriaCavaleiro(Player* Cavaleiro){
    Cavaleiro->origem.y=0;
    Cavaleiro->origem.w=42;
    Cavaleiro->origem.h=42;
    Cavaleiro->destino.w=150;
    Cavaleiro->destino.h=150;
    Cavaleiro->destino.x=100;
    Cavaleiro->destino.y=600;
    Cavaleiro->ataqueorigem.y=40;
    Cavaleiro->ataqueorigem.w=42;
    Cavaleiro->ataqueorigem.h=42;
    Cavaleiro->ataquedestino.w=150;
    Cavaleiro->ataquedestino.h=150;
    Cavaleiro->ataquedestino.x=100;
    Cavaleiro->ataquedestino.y=600;
    Cavaleiro->paradorigem.y=0;
    Cavaleiro->paradorigem.w=42;
    Cavaleiro->paradorigem.h=42;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \param inimigo
///
void Criainimigo(Player *inimigo){
    inimigo->vida=1;
    inimigo->paradorigem.y=0;
    inimigo->paradorigem.w=24;
    inimigo->paradorigem.h=32;
    inimigo->origem.y=0;
    inimigo->origem.w=22;
    inimigo->origem.h=33;
    inimigo->destino.w=100;
    inimigo->destino.h=120;
    inimigo->destino.x=300;
    inimigo->destino.y=600;
    inimigo->ataqueorigem.y=0;
    inimigo->ataqueorigem.w=24;
    inimigo->ataqueorigem.h=32;
    inimigo->ataquedestino.h=120;
    inimigo->ataquedestino.w=120;
    inimigo->ataquedestino.x=inimigo->paradodestino->x;
    inimigo->ataquedestino.y=inimigo->paradodestino->y;
    inimigo->adicional.y=0;
    inimigo->adicional.h=32;
    inimigo->adicional.w=33;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

