#include <iostream>
#include <SDL2/SDL.h>
#include "Functions.h"
using namespace std;


#undef main
int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING)<0)
        cout<< SDL_GetError();

    SDL_Window* janela = SDL_CreateWindow("Simulador de Caminhada",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1280,720,0);
    SDL_Renderer* render = SDL_CreateRenderer(janela,-1,0);
    SDL_SetRenderDrawColor(render,0,100,0,0);

    SDL_Texture* chao=Carrega("chao.bmp",render);
    SDL_Texture* sky=Carrega("sky.bmp",render);


    Menu menu;
    menu.imagemenu=Carrega("menu.bmp",render);
    menu.caveiramenu=Carrega("caveira_fogo.bmp",render);
    menu.origem.y=0;
    menu.origem.h=112;
    menu.origem.w=96;
    menu.Destino.x=680;
    menu.Destino.y=232;
    menu.Destino.w=100;
    menu.Destino.h=100;
    menu.origemZ.h=100;
    menu.origemZ.w=100;
    menu.destinoZ.x=163;
    menu.destinoZ.y=560;
    menu.destinoZ.h=42;
    menu.destinoZ.w=42;
    menu.Z=Carrega("Z.bmp",render);

    menu.X=Carrega("X.bmp",render);
    menu.origemX.h=100;
    menu.origemX.w=100;
    menu.destinoX.h=42;
    menu.destinoX.w=42;
    menu.destinoX.x=260;
    menu.destinoX.y=560;
    menu.destinobloq.w=150;
    menu.destinobloq.h=150;
    menu.destinobloq.x=210;
    menu.destinobloq.y=600;











    int x=0;
    int enemy=0;
    int escolha=0;
    int movimento=0;
    int pulotempo=0;
    const int velocidade = 10;
    val_anim auxanima[4];
    backup_anima(auxanima);
    Player Cavaleiro;
    CriaCavaleiro(&Cavaleiro,render);
    Player inimigo[4];
    Criainimigo(inimigo,render);


    SDL_Event evento;

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

    bool Inicio=true;
    bool Final=false;
    bool parado=1;
    bool pulo=true;
    bool b[2]={0,0};



    while(!Final){

    while(Inicio){
        SDL_RenderClear(render);

        menu.movimento++;
        menu.origem.x=(menu.movimento%8)*96;
        Cavaleiro.ataqueorigem.x=(menu.movimento%10)*80;
        Cavaleiro.bloqorigem.x=(5)*42;

        while(SDL_PollEvent(&evento)){
            switch(evento.type){
            case SDL_QUIT:
                GameOver=false;
                break;

                  case SDL_KEYDOWN:


                      switch (evento.key.keysym.sym) {
                      case SDLK_DOWN:

                          escolha++;

                          break;
                      case SDLK_UP:

                          escolha--;

                          break;

                      case SDLK_RETURN:
                          if(escolha==0){
                              Inicio=false;
                              GameOver=false;
                          }
                          else if(escolha==1){
                              Inicio=false;
                              GameOver=true;
                              Final=true;
                          }

                          break;
                      }




                      break;


            }
        }

       if(escolha>1){
            escolha=0;
        }
        else if(escolha<0){
            escolha=1;
        }


        if (escolha==0){
            menu.Destino.x=680;
            menu.Destino.y=232;
        }
        else if (escolha==1){
            menu.Destino.x=636;
            menu.Destino.y=348;

            }



         SDL_RenderCopy(render,sky,NULL,NULL);
         SDL_RenderCopy(render,chao,&camera,&cameradestino);

         SDL_RenderCopy(render,Cavaleiro.Tatacar,&Cavaleiro.ataqueorigem,&Cavaleiro.destino);
         SDL_RenderCopy(render,menu.imagemenu,NULL,NULL);
         SDL_RenderCopy(render,menu.caveiramenu,&menu.origem,&menu.Destino);
         SDL_RenderCopy(render,menu.X,&menu.origemX,&menu.destinoX);
         SDL_RenderCopy(render,menu.Z,&menu.origemZ,&menu.destinoZ);
         SDL_RenderCopy(render,Cavaleiro.TBloqueio,&Cavaleiro.bloqorigem,&menu.destinobloq);



         SDL_RenderPresent(render);

         SDL_Delay(1000/10);

    }
  x=0;
  enemy=0;
  escolha=0;
  movimento=0;
  pulotempo=0;
  parado=1;
  pulo=true;
  b[0]=0;
  b[1]=0;



    SDL_RenderClear(render);

    while(!GameOver){
        if (inimigo[3].anima.MorteF<1&&inimigo->info.vida==0){
            GameOver=true;
            Inicio=true;
        }
        movimento++;
        if(inimigo[enemy].destino.x-24<0){

            SDL_DestroyTexture(inimigo[enemy].Tmorte );
            SDL_DestroyTexture(inimigo[enemy].Tatacar );
            SDL_DestroyTexture(inimigo[enemy].Tparado );
            SDL_DestroyTexture(inimigo[enemy].Tandando );


            if (enemy<=3){
                enemy++;
                inimigo[enemy].destino.x=1280;
            }


        }
        if (inimigo[enemy].anima.AtaqueF<2){
            inimigo[enemy].anima.AtaqueF=auxanima[enemy].AtaqueF;
            inimigo[enemy].info.ataque=0;
     }


    if(inimigo[enemy].anima.AtaqueF<3){
        if(Cavaleiro.info.defesa==0){
        Cavaleiro.info.vida--;
        cout<<"dano";
        }


     }

     if(Cavaleiro.info.vida<=0){
         if(Cavaleiro.anima.MorteF>1){
             Cavaleiro.anima.MorteF--;
         }
         else{

             Cavaleiro.anima.MorteF=0;
             GameOver=true;
             Inicio=true;
             Final=false;
         }

     }

        SDL_RenderClear (render);





        Movimento(&Cavaleiro,&inimigo[enemy],&camera,movimento);

        while(SDL_PollEvent(&evento)){
            switch(evento.type){
            case SDL_QUIT:
                GameOver=false;
                break;
            case SDL_KEYDOWN:
                switch (evento.key.keysym.sym) {
                case SDLK_RIGHT:

                    inimigo[enemy].paradorigem.x=(movimento%inimigo[enemy].anima.ParadoF)*inimigo[enemy].anima.ParadoP;

                    b[0]=1;
                    parado=0;

                    break;
                case SDLK_x:
                    Cavaleiro.info.defesa=1;
                    break;
                //if(pulo==false){
                case SDLK_UP:
                    if (Cavaleiro.destino.y>500){
                        Cavaleiro.destino.y-=100;
                        pulo=true;}

                    break;
                    // }
                case SDLK_LEFT:
                    b[1]=1;
                    parado=0;

                    break;
                case SDLK_z:
                    parado=0;
                    Cavaleiro.info.ataque=1;
                    break;

                }
                break;
            case SDL_KEYUP:
                switch (evento.key.keysym.sym) {
                case SDLK_RIGHT:
                    b[0]=0;
                    parado=1;
                    break;
                case SDLK_x:
                    Cavaleiro.info.defesa=0;
                    Cavaleiro.anima.BloqF=7;

                    break;
                case SDLK_LEFT:
                    b[1]=0;
                    break;
                case SDLK_z:
                    parado=1;
                    Cavaleiro.info.ataque=0;
                    break;

                }

                break;

            }
        }


        if(pulo==true && pulotempo>=1){
            pulotempo--;
        }
        else if (pulotempo==0){
            Cavaleiro.destino.y=600;
            pulotempo=5;pulo=false;
        }

        if(b[0])
        {
            if(170 <inimigo[enemy].destino.x&&inimigo[enemy].info.vida>0){

                inimigo[enemy].info.ataque=1;
                Paredes(&inimigo[enemy],&camera,x,velocidade);
            }


            else if (inimigo[enemy].info.vida<1){
                Paredes(&inimigo[enemy],&camera,x,velocidade);
            }



            if(camera.x>5108-1277)
                camera.x=0;

        }
        else if (b[1]){
            x-=velocidade;
            camera.x-=velocidade;
            inimigo[enemy].destino.x+=10;
            if(camera.x<=0)
                camera.x=3831;
        }



        animation_principal(render,&inimigo[enemy],&Cavaleiro,sky,chao,&camera,&cameradestino,parado);


        SDL_RenderPresent(render);
        SDL_Delay(1000/24);
    }

    SDL_DestroyTexture(inimigo[enemy].Tmorte );
    SDL_DestroyTexture(inimigo[enemy].Tatacar );
    SDL_DestroyTexture(inimigo[enemy].Tparado );
    SDL_DestroyTexture(inimigo[enemy].Tandando );

    CriaCavaleiro(&Cavaleiro,render);
    Criainimigo(inimigo,render);
    backup_anima(auxanima);

    }

    SDL_DestroyTexture(menu.imagemenu);
    SDL_DestroyTexture(menu.caveiramenu);
    SDL_DestroyTexture(chao);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(janela);
    SDL_Quit();
    return 0;
}
