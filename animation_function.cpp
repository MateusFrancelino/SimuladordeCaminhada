#include "Functions.h"
#include <SDL2/SDL.h>
///////Separado por ação do Jogador////


void animation_Ataque(SDL_Renderer *render,Player* inimigo,Player* Cavaleiro){

    if(Cavaleiro->info.vida<=0){
        SDL_RenderCopy(render,Cavaleiro->Tmorte,&Cavaleiro->morte,&Cavaleiro->destino);
    }

    else{
        SDL_RenderCopy(render,Cavaleiro->Tatacar,&Cavaleiro->ataqueorigem,Cavaleiro->ataquedestino);
    }

    if(inimigo->destino.x<=220&&inimigo->info.ataque==1&&inimigo->info.vida>0){
        SDL_RenderCopy(render,inimigo->Tatacar,&inimigo->ataqueorigem,inimigo->ataquedestino);
        if(inimigo->anima.AtaqueF>1)
            inimigo->anima.AtaqueF--;
    }
    else if (inimigo->destino.x<=180&&inimigo->info.vida>0){
        SDL_RenderCopy(render,inimigo->TDano,&inimigo->danorigem,inimigo->danodestino);
        if (Cavaleiro->ataqueorigem.x==0){
            inimigo->info.vida--;
            inimigo->info.ataque=1;
        }

    }
    else if (inimigo->info.vida==0||(inimigo->destino.x<=180&&inimigo->info.vida==0)){

        SDL_RenderCopy(render,inimigo->Tmorte,&inimigo->morte,&inimigo->destino);
        if (inimigo->anima.MorteF>0)
            inimigo->anima.MorteF--;
    }

    else{
        SDL_RenderCopy(render,inimigo->Tparado,&inimigo->paradorigem,inimigo->paradodestino);
    }

}



void animation_Parado (SDL_Renderer *render,Player* inimigo,Player* Cavaleiro){

    if(inimigo->destino.x<=220&&inimigo->info.ataque==1&&Cavaleiro->info.vida>0){
        SDL_RenderCopy(render,inimigo->Tatacar,&inimigo->ataqueorigem,inimigo->ataquedestino);
        if(inimigo->anima.AtaqueF>1)
            inimigo->anima.AtaqueF--;


    }

    else if (inimigo->info.vida==0||(inimigo->destino.x<=180&&inimigo->info.vida==0)){

        SDL_RenderCopy(render,inimigo->Tmorte,&inimigo->morte,&inimigo->destino);
        if (inimigo->anima.MorteF>0)
            inimigo->anima.MorteF--;
    }
    else{
        SDL_RenderCopy(render,inimigo->Tparado,&inimigo->paradorigem,inimigo->paradodestino);
    }

    if(Cavaleiro->info.vida<=0){
        SDL_RenderCopy(render,Cavaleiro->Tmorte,&Cavaleiro->morte,&Cavaleiro->destino);
    }

    else{
        if(Cavaleiro->info.defesa==1){

            SDL_RenderCopy(render,Cavaleiro->TBloqueio,&Cavaleiro->bloqorigem,&Cavaleiro->destino);

        }
        else{
            SDL_RenderCopy(render,Cavaleiro->Tparado,&Cavaleiro->paradorigem,Cavaleiro->paradodestino);
        }
    }


}



void animation_andando(SDL_Renderer *render,Player* inimigo,Player* Cavaleiro){

    if (inimigo->info.vida==0||(inimigo->destino.x<=180&&inimigo->info.vida==0)){

        SDL_RenderCopy(render,inimigo->Tmorte,&inimigo->morte,&inimigo->destino);
        if (inimigo->anima.MorteF>0)
            inimigo->anima.MorteF--;
    }
    else{
        SDL_RenderCopy(render,inimigo->Tparado,&inimigo->paradorigem,inimigo->paradodestino);
    }
    if(Cavaleiro->info.vida<=0){
        SDL_RenderCopy(render,Cavaleiro->Tmorte,&Cavaleiro->morte,&Cavaleiro->destino);
    }

    else{
        if(Cavaleiro->info.defesa==1){
            SDL_RenderCopy(render,Cavaleiro->TBloqueio,&Cavaleiro->bloqorigem,&Cavaleiro->destino);

        }
        else{
            SDL_RenderCopy(render,Cavaleiro->Tandando,&Cavaleiro->paradorigem,Cavaleiro->paradodestino);
        }
    }

}

























void animation_principal(SDL_Renderer *render,Player* inimigo,Player* Cavaleiro,SDL_Texture* sky, SDL_Texture* chao,SDL_Rect *camera,SDL_Rect *cameradestino,bool parado){

    SDL_RenderCopy(render,sky,NULL,NULL);
    SDL_RenderCopy(render,chao,camera,cameradestino);
    if (Cavaleiro->info.ataque==1){

        animation_Ataque (render,inimigo,Cavaleiro);

    }



    else if (parado==1){

        animation_Parado(render,inimigo,Cavaleiro);

    }





    else{

        animation_andando(render,inimigo,Cavaleiro);


    }
    }
