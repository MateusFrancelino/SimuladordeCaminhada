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
    Cavaleiro->paradorigem.y=0;
    Cavaleiro->paradorigem.w=42;
    Cavaleiro->paradorigem.h=42;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Criainimigo
///
void Criainimigo(Player *inimigo){
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inimigo[0].vida=3;
    inimigo[0].paradorigem.y=0;
    inimigo[0].paradorigem.w=24;
    inimigo[0].paradorigem.h=32;
    inimigo[0].origem.y=0;
    inimigo[0].origem.w=22;
    inimigo[0].origem.h=33;
    inimigo[0].destino.w=100;
    inimigo[0].destino.h=120;
    inimigo[0].destino.x=300;
    inimigo[0].destino.y=600;
    inimigo[0].ataqueorigem.y=0;
    inimigo[0].ataqueorigem.w=24;
    inimigo[0].ataqueorigem.h=32;
    inimigo[0].adicional.y=0;
    inimigo[0].adicional.h=32;
    inimigo[0].adicional.w=33;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inimigo[1].vida=3;
    inimigo[1].paradorigem.y=0;
    inimigo[1].paradorigem.w=24;
    inimigo[1].paradorigem.h=32;
    inimigo[1].origem.y=0;
    inimigo[1].origem.w=22;
    inimigo[1].origem.h=33;
    inimigo[1].destino.w=100;
    inimigo[1].destino.h=120;
    inimigo[1].destino.x=300;
    inimigo[1].destino.y=600;
    inimigo[1].ataqueorigem.y=0;
    inimigo[1].ataqueorigem.w=24;
    inimigo[1].ataqueorigem.h=32;
    inimigo[1].adicional.y=0;
    inimigo[1].adicional.h=32;
    inimigo[1].adicional.w=33;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inimigo[2].vida=3;
    inimigo[2].paradorigem.y=0;
    inimigo[2].paradorigem.w=24;
    inimigo[2].paradorigem.h=32;
    inimigo[2].origem.y=0;
    inimigo[2].origem.w=22;
    inimigo[2].origem.h=33;
    inimigo[2].destino.w=100;
    inimigo[2].destino.h=120;
    inimigo[2].destino.x=300;
    inimigo[2].destino.y=600;
    inimigo[2].ataqueorigem.y=0;
    inimigo[2].ataqueorigem.w=24;
    inimigo[2].ataqueorigem.h=32;
    inimigo[2].adicional.y=0;
    inimigo[2].adicional.h=32;
    inimigo[2].adicional.w=33;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inimigo[3].vida=3;
    inimigo[3].paradorigem.y=0;
    inimigo[3].paradorigem.w=24;
    inimigo[3].paradorigem.h=32;
    inimigo[3].origem.y=0;
    inimigo[3].origem.w=22;
    inimigo[3].origem.h=33;
    inimigo[3].destino.w=100;
    inimigo[3].destino.h=120;
    inimigo[3].destino.x=300;
    inimigo[3].destino.y=600;
    inimigo[3].ataqueorigem.y=0;
    inimigo[3].ataqueorigem.w=24;
    inimigo[3].ataqueorigem.h=32;
    inimigo[3].adicional.y=0;
    inimigo[3].adicional.h=32;
    inimigo[3].adicional.w=33;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Paredes
///
void Paredes(Player* inimigo,SDL_Rect* camera,int x,int velocidade){
    inimigo->paradodestino->x-=10;
    inimigo->ataquedestino->x=inimigo->paradodestino->x;
    x+=velocidade;
    camera->x+=velocidade;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Movimento
///
void Movimento(Player* Cavaleiro,Player* inimigo,SDL_Rect *camera ,int movimento,int morte){

    Cavaleiro->origem.x=(camera->x%8)*42;

    inimigo->ataqueorigem.x=(movimento%8)*30;

    if (movimento%3==0){
        Cavaleiro->ataqueorigem.x=(movimento%10)*80;

        Cavaleiro->paradorigem.x=(movimento%4)*42;
        inimigo->paradorigem.x=(movimento%11)*24;
        inimigo->origem.x=(camera->x%13)*22;

        inimigo->adicional.x=(morte%15)*33;
    }

}

