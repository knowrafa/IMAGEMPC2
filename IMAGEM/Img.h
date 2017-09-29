#ifndef IMG_H
#define IMG_H

#ifdef __cplusplus
extern "C" {
#endif
    
#define troca( a, b, type ) { \
  type __tmp__swap___; \
  __tmp__swap___= (a); \
  (a) = (b); \
  (b) = __tmp__swap___; \
}
#define __abs(a) ( (a)< 0 ? -(a) : (a) ) 


    
    typedef struct _rgb{
        int r, g, b;
    }rgb;
    
    typedef struct {
        
        int width, height;
        
        rgb fundo;
        
        
    }ipc2;
 
    typedef struct {
        int x, y;
    }p2d;
    
    typedef struct _rgbin{
        char r, g, b;
    }rgbin;
    
    void draw_pixel(int x, int y);
    
    int read_ipc2(void);
    
    void  circle ( int xm,  int ym,  int ray);

rgb **RGB;

rgbin **RGBin;
    
rgb cor, cor2;

ipc2 img;


#ifdef __cplusplus
}
#endif

#endif /* IMG_H */

