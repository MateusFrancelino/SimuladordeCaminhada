#include "Functions.h"
#include <SDL2/SDL.h>

SDL_Texture*Carrega(const char* imgtx,SDL_Renderer* render){
    cout<<imgtx<<endl;
    SDL_Surface* img=SDL_LoadBMP(imgtx);
    SDL_Texture* textura=SDL_CreateTextureFromSurface(render,img);
    SDL_FreeSurface(img);
    return textura;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Cavaleiro
///
void CriaCavaleiro(Player* Cavaleiro,SDL_Renderer* render){
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
    Cavaleiro->bloqorigem.y=0;
    Cavaleiro->bloqorigem.w=42;
    Cavaleiro->bloqorigem.h=42;
    Cavaleiro->morte.y=0;
    Cavaleiro->morte.w=32;
    Cavaleiro->morte.h=32;
    Cavaleiro->info.vida=1;


    Cavaleiro->Tparado=Carrega("cavaleiroparado.bmp",render);
    Cavaleiro->Tatacar=Carrega("cavaleiroataque.bmp",render);
    Cavaleiro->Tandando=Carrega("cavaleiroandando.bmp",render);
    Cavaleiro->TBloqueio=Carrega("cavaleiro-bloqueio.bmp",render);
    Cavaleiro->Tmorte=Carrega("cavaleiro-morte.bmp",render);


    Cavaleiro->anima.AndandoF=8;
    Cavaleiro->anima.AndandoP=42;
    Cavaleiro->anima.AtaqueF=10;
    Cavaleiro->anima.AtaqueP=80;
    Cavaleiro->anima.AndandoF=4;
    Cavaleiro->anima.AndandoP=42;
    Cavaleiro->anima.BloqF=7;
    Cavaleiro->anima.BloqP=42;
    Cavaleiro->anima.MorteF=8;
    Cavaleiro->anima.MorteP=32;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Criainimigo
///
void Criainimigo(Player *inimigo,SDL_Renderer* render){
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    inimigo[0].danorigem.y=0;
    inimigo[0].danorigem.w=24;
    inimigo[0].danorigem.h=32;
    inimigo[0].morte.y=0;
    inimigo[0].morte.h=32;
    inimigo[0].morte.w=33;
    inimigo[0].ataqueorigem.y=6;
    inimigo[0].ataqueorigem.w=38;
    inimigo[0].ataqueorigem.h=37;

    inimigo[0].info.vida=3;



    inimigo[0].Tparado=Carrega("magicoparado.bmp",render);
    inimigo[0].TDano=Carrega("esqhit.bmp",render);
    inimigo[0].Tandando=Carrega("esqandando.bmp",render);
    inimigo[0].Tmorte=Carrega("esqmorto.bmp",render);
    inimigo[0].Tatacar=Carrega("esqataque.bmp",render);

    inimigo[0].anima.ParadoF=11;
    inimigo[0].anima.ParadoP=24;
    inimigo[0].anima.MorteF=15;
    inimigo[0].anima.MorteP=32;
    inimigo[0].anima.DanoF=8;
    inimigo[0].anima.DanoP=30;
    inimigo[0].anima.AtaqueF=18;
    inimigo[0].anima.AtaqueP=43;


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    inimigo[1].paradorigem.y=0;
    inimigo[1].paradorigem.w=64;
    inimigo[1].paradorigem.h=80;
    inimigo[1].origem.y=0;
    inimigo[1].origem.w=22;
    inimigo[1].origem.h=33;
    inimigo[1].destino.w=150;
    inimigo[1].destino.h=200;
    inimigo[1].destino.x=300;
    inimigo[1].destino.y=500;
    inimigo[1].danorigem.y=0;
    inimigo[1].danorigem.w=64;
    inimigo[1].danorigem.h=64;
    inimigo[1].morte.y=0;
    inimigo[1].morte.h=48;
    inimigo[1].morte.w=64;
    inimigo[1].ataqueorigem.y=0;
    inimigo[1].ataqueorigem.w=64;
    inimigo[1].ataqueorigem.h=80;

    inimigo[1].info.vida=3;


    inimigo[1].Tparado=Carrega("ghost-parado.bmp",render);
    inimigo[1].TDano=Carrega("ghost-hit.bmp",render);
    inimigo[1].Tandando=Carrega("esqandando.bmp",render);
    inimigo[1].Tmorte=Carrega("ghost-morte.bmp",render);
    inimigo[1].Tatacar=Carrega("ghost-ataque.bmp",render);



    inimigo[1].anima.ParadoF=7;
    inimigo[1].anima.ParadoP=64;
    inimigo[1].anima.MorteF=6;
    inimigo[1].anima.MorteP=64;
    inimigo[1].anima.DanoF=7;
    inimigo[1].anima.DanoP=64;
    inimigo[1].anima.AtaqueF=4;
    inimigo[1].anima.AtaqueP=64;


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    inimigo[2].paradorigem.y=0;
    inimigo[2].paradorigem.w=48;
    inimigo[2].paradorigem.h=54;
    inimigo[2].origem.y=0;
    inimigo[2].origem.w=22;
    inimigo[2].origem.h=33;
    inimigo[2].destino.w=150;
    inimigo[2].destino.h=140;
    inimigo[2].destino.x=300;
    inimigo[2].destino.y=600;
    inimigo[2].danorigem.y=156;
    inimigo[2].danorigem.w=48;
    inimigo[2].danorigem.h=42;
    inimigo[2].morte.y=156;
    inimigo[2].morte.h=40;
    inimigo[2].morte.w=48;
    inimigo[2].ataqueorigem.y=98;
    inimigo[2].ataqueorigem.w=48;
    inimigo[2].ataqueorigem.h=50;


    inimigo[2].info.vida=3;

    inimigo[2].Tparado=Carrega("bandidopack.bmp",render);
    inimigo[2].TDano=Carrega("bandidopack.bmp",render);
    inimigo[2].Tandando=Carrega("bandidopack.bmp",render);
    inimigo[2].Tmorte=Carrega("bandidopack.bmp",render);
    inimigo[2].Tatacar=Carrega("bandidopack.bmp",render);


    inimigo[2].anima.ParadoF=3;
    inimigo[2].anima.ParadoP=48;
    inimigo[2].anima.MorteF=8;
    inimigo[2].anima.MorteP=48;
    inimigo[2].anima.DanoF=8;
    inimigo[2].anima.DanoP=48;
    inimigo[2].anima.AtaqueF=7;
    inimigo[2].anima.AtaqueP=48;



    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inimigo[3].paradorigem.y=0;
    inimigo[3].paradorigem.w=160;
    inimigo[3].paradorigem.h=144;
    inimigo[3].origem.y=0;
    inimigo[3].origem.w=22;
    inimigo[3].origem.h=33;
    inimigo[3].destino.w=200;
    inimigo[3].destino.h=220;
    inimigo[3].destino.x=300;
    inimigo[3].destino.y=510;
    inimigo[3].danorigem.y=0;
    inimigo[3].danorigem.w=192;
    inimigo[3].danorigem.h=176;
    inimigo[3].ataqueorigem.y=0;
    inimigo[3].ataqueorigem.w=150;
    inimigo[3].ataqueorigem.h=245;
    inimigo[3].morte.y=0;
    inimigo[3].morte.h=128;
    inimigo[3].morte.w=128;



    inimigo[3].info.vida=12;

    inimigo[3].Tparado=Carrega("demonparado.bmp",render);
    inimigo[3].TDano=Carrega("demon-hit.bmp",render);
    inimigo[3].Tandando=Carrega("esqandando.bmp",render);
    inimigo[3].Tmorte=Carrega("demon-morte.bmp",render);
    inimigo[3].Tatacar=Carrega("demon-ataque.bmp",render);

    inimigo[3].anima.ParadoF=6;
    inimigo[3].anima.ParadoP=160;
    inimigo[3].anima.MorteF=12;
    inimigo[3].anima.MorteP=128;
    inimigo[3].anima.DanoF=8;
    inimigo[3].anima.DanoP=192;
    inimigo[3].anima.AtaqueF=11;
    inimigo[3].anima.AtaqueP=245;



    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void backup_anima(val_anim *auxanima){

    auxanima[0].ParadoF=11;
    auxanima[0].ParadoP=24;
    auxanima[0].MorteF=15;
    auxanima[0].MorteP=32;
    auxanima[0].DanoF=8;
    auxanima[0].DanoP=30;
    auxanima[0].AtaqueF=17;
    auxanima[0].AtaqueP=43;



    auxanima[1].ParadoF=11;
    auxanima[1].ParadoP=24;
    auxanima[1].MorteF=15;
    auxanima[1].MorteP=32;
    auxanima[1].DanoF=8;
    auxanima[1].DanoP=30;
    auxanima[1].AtaqueF=4;
    auxanima[1].AtaqueP=64;



    auxanima[2].ParadoF=11;
    auxanima[2].ParadoP=24;
    auxanima[2].MorteF=15;
    auxanima[2].MorteP=32;
    auxanima[2].DanoF=8;
    auxanima[2].DanoP=30;
    auxanima[2].AtaqueF=7;
    auxanima[2].AtaqueP=48;



    auxanima[3].ParadoF=11;
    auxanima[3].ParadoP=24;
    auxanima[3].MorteF=12;
    auxanima[3].MorteP=128;
    auxanima[3].DanoF=8;
    auxanima[3].DanoP=192;
    auxanima[3].AtaqueF=11;
    auxanima[3].AtaqueP=245;



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

void Movimento(Player* Cavaleiro,Player* inimigo,SDL_Rect *camera ,int movimento){

    Cavaleiro->origem.x=(camera->x%Cavaleiro->anima.AndandoF)*Cavaleiro->anima.AtaqueP;
    Cavaleiro->morte.x=(Cavaleiro->anima.MorteF)*Cavaleiro->anima.MorteP;

    inimigo->danorigem.x=(movimento%inimigo->anima.DanoF)*inimigo->anima.DanoP;

    Cavaleiro->bloqorigem.x=(6)*Cavaleiro->anima.BloqP;

    if (movimento%2==0){


        inimigo->ataqueorigem.x=(inimigo->anima.AtaqueF)*inimigo->anima.AtaqueP;
        Cavaleiro->ataqueorigem.x=(movimento%Cavaleiro->anima.AtaqueF)*Cavaleiro->anima.AtaqueP;

        Cavaleiro->paradorigem.x=(movimento%Cavaleiro->anima.AndandoF)*Cavaleiro->anima.AndandoP;

        inimigo->paradorigem.x=(movimento%inimigo->anima.ParadoF)*inimigo->anima.ParadoP;

        inimigo->origem.x=(camera->x%inimigo->anima.ParadoF)*inimigo->anima.ParadoP;

        inimigo->morte.x=(inimigo->anima.MorteF)*inimigo->anima.MorteP;
    }
}
