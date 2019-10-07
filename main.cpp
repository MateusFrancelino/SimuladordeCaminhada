#include <iostream>
#include <SDL2/SDL.h>
#include "Functions.h"
using namespace std;


/*void Texturas(render,const char){

}*/

#undef main
int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING)<0)
        cout<< SDL_GetError();

    int movimento=0;
    const int velocidade = 10;


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Cavaleiro
    ///
    Player Cavaleiro;
    CriaCavaleiro(&Cavaleiro);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief inimigo
    ///
    Player inimigo;

    Criainimigo(&inimigo);




    SDL_Rect camera;
    camera.x=0;
    camera.y=0;
    camera.w=1277;
    camera.h=327;

    SDL_Rect cameradestino;
    cameradestino.h=327;
    cameradestino.w=1280;
    cameradestino.y=400;
    cameradestino.x=0;

    bool GameOver=false;
    bool b[2]={0,0};
    bool ataque=0;
    bool parado=1;
    int morte=14;

    SDL_Event evento;
    SDL_Window* janela = SDL_CreateWindow("Simulador de Caminhada",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,0);
    SDL_Renderer* render = SDL_CreateRenderer(janela,-1,0);
    SDL_Texture* textura = NULL;
    SDL_SetRenderDrawColor(render,0,100,0,0);




    SDL_Texture* cavparado=Carrega("cavaleiroparado.bmp",render);
    SDL_Texture* atacar=Carrega("cavaleiroataque.bmp",render);
    SDL_Texture* montain=Carrega("montain.bmp",render);
    SDL_Texture* cavaleiroanda= Carrega("cavaleiroandando.bmp",render);
    SDL_Texture* chao=Carrega("chao.bmp",render);
    SDL_Texture* sky=Carrega("sky.bmp",render);
    SDL_Texture* esqparado=Carrega("magicoparado.bmp",render);
    SDL_Texture* esqandando =Carrega("esqandando.bmp",render);
    SDL_Texture* esqhit= Carrega("esqhit.bmp",render);
    SDL_Texture* esqmorto=Carrega("esqmorto.bmp",render);



    while(!GameOver){
        movimento++;
        SDL_Event evento;
        int x=0;
        int y=0;

        Cavaleiro.origem.x=(camera.x%8)*42;
        Cavaleiro.ataqueorigem.x=(movimento%10)*80;
        Cavaleiro.paradorigem.x=(movimento%4)*42;
        if (movimento%2==0){
        Cavaleiro.paradorigem.x=(movimento%4)*42;
        inimigo.paradorigem.x=(movimento%11)*24;
        inimigo.origem.x=(camera.x%13)*22;
        inimigo.ataqueorigem.x=(movimento%8)*30;
        inimigo.adicional.x=(morte%15)*33;
        }

        while(SDL_PollEvent(&evento)){
            switch(evento.type){
            case SDL_QUIT:
                GameOver=false;
                break;
            case SDL_KEYDOWN:
                switch (evento.key.keysym.sym) {
                case SDLK_RIGHT:

                    inimigo.paradorigem.x=(camera.x%11)*24;

                    b[0]=1;
                    parado=0;

                      break;
                case SDLK_LEFT:
                    b[1]=1;
                    parado=0;

                    break;
                case SDLK_z:
                    parado=0;
                    ataque=1;
                    break;

                }
                break;
            case SDL_KEYUP:
                switch (evento.key.keysym.sym) {
                case SDLK_RIGHT:
                    b[0]=0;
                    parado=1;
                    break;
                case SDLK_LEFT:
                    b[1]=0;
                    break;
                case SDLK_z:
                    parado=1;
                    ataque=0;
                    break;

                }
                 movimento=0;
                break;

            }
        }


        if(b[0])
        {
            if(170 <inimigo.destino.x&&inimigo.vida==1){
            inimigo.paradodestino->x-=10;
            }
            else if (inimigo.vida!=1){
                    inimigo.paradodestino->x-=10;
                }

            inimigo.ataquedestino.x=inimigo.paradodestino->x;
            x+=velocidade;
            camera.x+=velocidade;
            if(camera.x>5108-1277)
                camera.x=0;

        }
        else if (b[1]){
            x-=velocidade;
            camera.x-=velocidade;
            if(camera.x<=0)
                camera.x=3831;

        }


       SDL_RenderClear (render);

       SDL_Rect Cavaleirodestino;

       SDL_RenderClear (render);
       SDL_RenderCopy(render,sky,NULL,NULL);
       //SDL_RenderCopy(render,montain,NULL,NULL);//
       SDL_RenderCopy(render,chao,&camera,&cameradestino);
       if (ataque==1){

           SDL_RenderCopy(render,atacar,&Cavaleiro.ataqueorigem,&Cavaleiro.ataquedestino);
           if (inimigo.destino.x<=180&&inimigo.vida==1){
               SDL_RenderCopy(render,esqhit,&inimigo.ataqueorigem,&inimigo.ataquedestino);
               if (Cavaleiro.ataqueorigem.x==0)
                    inimigo.vida=0;
           }
           else if (inimigo.destino.x<=180&&inimigo.vida==0){

               SDL_RenderCopy(render,esqmorto,&inimigo.adicional,&inimigo.destino);
               if (morte>0)
                   morte--;
           }
           else{
               SDL_RenderCopy(render,esqparado,&inimigo.paradorigem,inimigo.paradodestino);
           }

       }else if (parado==1){
           if (inimigo.destino.x<=180&&inimigo.vida==0){

               SDL_RenderCopy(render,esqmorto,&inimigo.adicional,&inimigo.destino);
               if (morte>0)
                   morte--;
           }
           else{
               SDL_RenderCopy(render,esqparado,&inimigo.paradorigem,inimigo.paradodestino);
           }
           SDL_RenderCopy(render,cavparado,&Cavaleiro.paradorigem,Cavaleiro.paradodestino);
       }
       else{
           movimento=0;
          // SDL_RenderCopy(render,esqandando,&inimigo.origem,&inimigo.destino);
           if (inimigo.destino.x<=180&&inimigo.vida==0){

               SDL_RenderCopy(render,esqmorto,&inimigo.adicional,&inimigo.destino);
               if (morte>0)
                   morte--;
           }
           else{
               SDL_RenderCopy(render,esqparado,&inimigo.paradorigem,inimigo.paradodestino);
           }
           SDL_RenderCopy(render,cavaleiroanda,&Cavaleiro.origem,&Cavaleiro.destino);
       }


       if(inimigo.destino.x<0){
           inimigo.destino.x=1280;
       }
       SDL_RenderPresent(render);
       SDL_Delay(1000/20);

    }


    SDL_DestroyTexture(atacar);
    SDL_DestroyTexture(cavparado);
    SDL_DestroyTexture(chao);
    SDL_DestroyTexture(cavaleiroanda);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(janela);
    SDL_Quit();
    return 0;
}
