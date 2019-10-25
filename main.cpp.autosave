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

    //SDL_Texture* cavparado=Carrega("cavaleiroparado.bmp",render);
    //SDL_Texture* atacar=Carrega("cavaleiroataque.bmp",render);
    //SDL_Texture* cavaleiroanda= Carrega("cavaleiroandando.bmp",render);

    SDL_Texture* chao=Carrega("chao.bmp",render);
    SDL_Texture* sky=Carrega("sky.bmp",render);


    //SDL_Texture* esqparado=Carrega("magicoparado.bmp",render);
    //SDL_Texture* esqandando =Carrega("esqandando.bmp",render);
    //SDL_Texture* esqhit= Carrega("esqhit.bmp",render);
    //SDL_Texture* esqmorto=Carrega("esqmorto.bmp",render);



    int movimento=0;
    int pulotempo=0;
    const int velocidade = 10;
    val_anim auxanima[4];
    backup_anima(auxanima);
    Player Cavaleiro;
    CriaCavaleiro(&Cavaleiro,render);
    Player inimigo[4];
    Criainimigo(inimigo,render);

    int enemy=0;


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
    bool Inicio=true;
    bool Final=false;
    bool parado=1;
    bool pulo=true;





    while(!GameOver){
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

            if (enemy==4){
                GameOver=true;
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
             GameOver=true;
             Cavaleiro.anima.MorteF=0;
         }

     }

        SDL_RenderClear (render);


        SDL_Event evento;
        int x=0;

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
                            Cavaleiro.destino.y-=50;
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
            cout<<"pulando";
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


    //SDL_DestroyTexture(atacar);
    //SDL_DestroyTexture(cavparado);
    SDL_DestroyTexture(chao);
    //SDL_DestroyTexture(cavaleiroanda);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(janela);
    SDL_Quit();
    return 0;
}
