#include "Img.h"
#include<stdio.h>
#include<stdlib.h>
    
void draw_pixel(int x, int y){
        
        RGB[x][y] = cor;
        
        return ;
}
   
void segment(int x0, int y0, int x1, int y1) { 
// = draw vertical line 

  if (x0 == x1) { 
  
    if(y0 > y1) troca(y0, y1, int); 

    for (; y0 <= y1; y0++) draw_pixel(x0, y0); 

    return ; 
  } 
  // = draw horizontal line 
    if (y0 == y1) { 
    
      if (x0 > x1) troca(x0, x1, int);
    
      for (; x0 <= x1; x0++) draw_pixel(x0, y0); 

      return ; 
    } 
// = draw non vertical and non horizontal line 
    int dx = __abs(x1-x0);
    int dy = -__abs(y1-y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy; 
    int e2; // error value e_xy

   for (;;) { // loop
      draw_pixel(x0, y0);
      if (x0 == x1 && y0 == y1)  break ;
      e2 = 2 * err;
      if (e2 >= dy) {
      err += dy;
      x0 += sx;
    } // e_xy+e_x > 0
    if (e2 <= dx) {
      err += dx;
      y0 += sy;
    } // e_xy+e_y < 0
  }
}
    
    int read_ipc2(void){
        int size, ret, i, j, r;
        char ch;
        rgb idx;
        p2d p1, p2;
        
        FILE* f;
        f=fopen("ipc2", "rb");
        
        if(f==0)
        {
            printf("Erro na leitura.\n");
            return 0;
        }
        
        if(fscanf(f, "IPC%c\n", &ch) != 1 || ch != '2'){
            printf("Não é um arquivo válido\n");
            return 0;
        }
        
        ch=fgetc(f);
        while(ch=='#')
        {
            do{
                ch=getc(f);
            }while(ch!='\n');
            ch=getc(f);
        }
        ungetc(ch,f);
    
    
    ret = fscanf(f, "%d %d\n%d %d %d\n", &img.width, &img.height, &idx.r, &idx.g, &idx.b);
    
    for(i=0; i < img.width; i++){}
    
    if(ret<=0)
    {
        printf("Problemas na leitura do arquivo!\n");
        return 0;
    }
    printf("%d %d %d %d %d\n", img.width, img.height, idx.r, idx.g, idx.b);
    
    size=img.width*img.height;
    RGB=(rgb**)calloc(sizeof(rgb*),img.width);
    for(i=0; i< img.width; i++)
    {
       RGB[i]=(rgb*)calloc(sizeof(rgb),img.height);
    }
    cor = idx;
    for(i=0; i < img.height; i++){
        for(j=0; j< img.width; j++){
            draw_pixel(i, j);
        }
    }
    
    while(!feof(f)){
   
        ch = getc(f);
        
        switch(ch)
        {
            case '1':
            {
                fscanf(f, " %d %d %d %d %d\n", &p1.x, &p1.y, &cor.r, &cor.g, &cor.b);
                
                draw_pixel(p1.x,p1.y);
                break;
            }
            case '2':
            {
                fscanf(f, " %d %d %d %d %d %d %d\n", &p1.x, &p1.y, &p2.x, &p2.y, &cor.r, &cor.g, &cor.b);
                segment(p1.x, p1.y, p2.x, p2.y);
                
                break;
            }
            case '3':
            {
                fscanf(f, " %d %d %d %d %d %d %d %d %d %d\n", &p1.x, &p1.y, &p2.x, &p2.y, &cor.r, &cor.g, &cor.b, &cor2.r, &cor2.g, &cor2.b);
                
                /*Borda*/ 
                segment(p1.x, p1.y, p1.x, p2.y);
                segment(p1.x, p1.y, p2.x, p1.y);
                segment(p2.x, p1.y, p2.x, p2.y);
                segment(p1.x, p2.y, p2.x, p2.y);
                
                cor = cor2;
                p1.x++;
                p1.y++;
               
                p2.x--;
                p2.y--;
                
                /*Centro*/
                for(i=p1.x;i<=p2.x;i++)
                {
                    for(j=p1.y;j<=p2.y;j++)
                    {
                        draw_pixel(i,j);
                    }
                }
                break;
            }
            case '4':
            {
                fscanf(f, " %d %d %d %d %d %d %d %d %d\n", &p1.x, &p1.y, &r, &cor.r, &cor.g, &cor.b, &cor2.r, &cor2.g, &cor2.b);
                
                rgb cor3;
                
                cor3 = cor;
              
                cor = cor2;
                
                for(i=r;i>0;i--){
                    fund_circle(p1.x,p1.y, i);
                }
                cor = cor3;
                
                circle(p1.x, p1.x, r);
                 
                break;
            }
        }
        
    }
    
    return 1;
    
    
}
 void  circle ( int xm,  int ym,  int ray) {
  int x = -ray, y = 0, err = 2 - 2 * ray;
  do {
    draw_pixel(xm - x, ym + y);  /* I. Quadrant */
    draw_pixel(xm - y, ym - x);  /* II. Quadrant */
    draw_pixel(xm + x, ym - y);  /* III. Quadrant */
    draw_pixel(xm + y, ym + x);  /* IV. Quadrant */
    ray = err;
    if (ray > x) err += ++x * 2 + 1;  /* e_xy+e_x > 0 */
    if (ray <= y) err += ++y * 2 + 1;  /* e_xy+e_y < 0 */
  } while (x < 0);
}

 void save_ppm(int fl){
     
     int i, j;
     
     FILE *ppm;
     
     ppm = fopen("pc2.ppm", "wb+");
    // printf("!\n");
     if(!fl){
         
         fprintf(ppm, "P3\n%d %d\n255\n", img.width, img.height);
         
         for(i = 0; i < img.height; i++){
             for(j =0; j < img.width; j++){
                 fprintf(ppm, "%d %d %d", RGB[i][j].r, RGB[i][j].g, RGB[i][j].b);
                 if(j==img.width-1) fprintf(ppm, "\n");
                 else fprintf(ppm, " ");
             }
         }
     
     }
     else{
         RGBin=(rgbin**)calloc(sizeof(rgbin*),img.height);
        
         for(i=0; i< img.width; i++)
        {
           RGBin[i]=(rgbin*)calloc(sizeof(rgbin),img.width);
        }
         printf("1!\n");
         
        for(i=0;i<img.height;i++)
        {
            for(j=0;j<img.width;j++)
            {
                RGBin[i][j].r=RGB[i][j].r;
                RGBin[i][j].g=RGB[i][j].g;
                RGBin[i][j].b=RGB[i][j].b;
            }
        }
        
        fprintf(ppm, "P6\n%d %d\n255\n", img.width, img.height);
        for(i=0;i<img.height;i++)
        {
            fwrite(RGBin[i],sizeof(RGBin[i][0]),img.width,ppm);
          //  fprintf(ppm, "\n");
        }
     }
     fflush(ppm);
     fclose(ppm);
 }
 
  void save_pgm(int fl){
     
     int i, j;
     
     FILE *pgm;
     
     pgm = fopen("pc2.pgm", "wb+");
     
     if(!fl){
         
         fprintf(pgm, "P2\n%d %d\n255\n", img.width, img.height);
         
         for(i = 0; i < img.height; i++){
             for(j =0; j < img.width; j++){
                 fprintf(pgm, "%d", (RGB[i][j].r+RGB[i][j].g+RGB[i][j].b)/3);
                 if(j==img.width-1) fprintf(pgm, "\n");
                 else fprintf(pgm, " ");
             }
         }
     
     }
     else{
         RGBin=(rgbin**)calloc(sizeof(rgbin*),img.height);
        
         for(i=0; i< img.width; i++)
        {
           RGBin[i]=(rgbin*)calloc(sizeof(rgbin),img.width);
        }
         printf("1!\n");
         
        for(i=0;i<img.height;i++)
        {
            for(j=0;j<img.width;j++)
            {
                RGBin[i][j].r=(RGB[i][j].r+RGB[i][j].g+RGB[i][j].b)/3;
            }
        }
        
        fprintf(pgm, "P5\n%d %d\n255\n", img.width, img.height);
        
        for(i=0;i<img.height;i++)
        {
            for(j=0; j < img.width; j++){
            fwrite(&RGBin[i][j].r,sizeof(char),1,pgm);
            
            }
        }
     }
     fflush(pgm);
     fclose(pgm);
 }
  
  void  fund_circle ( int xm,  int ym,  int ray) {
  int x = -ray, y = 0, err = 2 - 2 * ray;
  do {
    
    segment(xm - x, ym + y, xm, ym);  /* I. Quadrant */
    segment(xm - x, ym + y, xm - y, ym - x);
 
    segment(xm - y, ym - x, xm, ym);  /* II. Quadrant */
    segment(xm + x, ym - y, xm + y, ym + x);
    
    segment(xm + x, ym - y, xm, ym);  /* III. Quadrant */
    segment(xm + y, ym + x, xm, ym);  /* IV. Quadrant */
    
    segment(xm - x, ym + y, xm + x, ym - y);
    segment(xm - y, ym - x, xm + y, ym + x );
    
    ray = err;
    
    if (ray > x) err += ++x * 2 + 1;  /* e_xy+e_x > 0 */
    if (ray <= y) err += ++y * 2 + 1;  /* e_xy+e_y < 0 */
  } while (x < 0);
}