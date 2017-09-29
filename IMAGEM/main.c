#include <stdio.h>
#include <stdlib.h>
#include"Img.h"

int main(int argc, char** argv) {
    int i, j;
    
    char fl=0;
    int op=0;
    
    if(!read_ipc2()){
         printf("Error\n");
         return 0;
    }
        do{
        printf("Modo Atual: ");
        
        if(!fl) printf("Textual\n");
        else  printf("Binario\n");
        
        printf("OPÇÕES:\n0 - Sair\n1 - Alterar Modo (bin ou text)\n2 - Salvar em PPM\n3 - Salvar em PGM\n");
        
        scanf("%d", &op);
        
        switch(op){
            case 0: break;
            case 1: if(!fl) fl = 1; else fl = 0; break;
            case 2: save_ppm(fl); break;
            case 3: save_pgm(fl); break;
            
        }
        
    }while(op != 0);
    
    for(i=0;i<img.height;i++)
    {   free(RGB[i]);
        
    if(fl)
        free(RGBin[i]);
    }
    
    if(fl)
    free(RGBin);
    
    free(RGB);
    return 0;
}

