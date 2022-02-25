#include "c_img.h"
#include <stdio.h>
#include <math.h>

void create_img(struct rgb_img **im, size_t height, size_t width){
    *im = (struct rgb_img *)malloc(sizeof(struct rgb_img));
    (*im)->height = height;
    (*im)->width = width;
    (*im)->raster = (uint8_t *)malloc(3 * height * width);
}


int read_2bytes(FILE *fp){
    uint8_t bytes[2];
    fread(bytes, sizeof(uint8_t), 1, fp);
    fread(bytes+1, sizeof(uint8_t), 1, fp);
    return (  ((int)bytes[0]) << 8)  + (int)bytes[1];
}

void write_2bytes(FILE *fp, int num){
    uint8_t bytes[2];
    bytes[0] = (uint8_t)((num & 0XFFFF) >> 8);
    bytes[1] = (uint8_t)(num & 0XFF);
    fwrite(bytes, 1, 1, fp);
    fwrite(bytes+1, 1, 1, fp);
}

void read_in_img(struct rgb_img **im, char *filename){
    FILE *fp = fopen(filename, "rb");
    size_t height = read_2bytes(fp);
    size_t width = read_2bytes(fp);
    create_img(im, height, width);
    fread((*im)->raster, 1, 3*width*height, fp);
    fclose(fp);
}

void write_img(struct rgb_img *im, char *filename){
    FILE *fp = fopen(filename, "wb");
    write_2bytes(fp, im->height);
    write_2bytes(fp, im->width);
    fwrite(im->raster, 1, im->height * im->width * 3, fp);
    fclose(fp);
}

uint8_t get_pixel(struct rgb_img *im, int y, int x, int col){
    return im->raster[3 * (y*(im->width) + x) + col];
}

void set_pixel(struct rgb_img *im, int y, int x, int r, int g, int b){
    im->raster[3 * (y*(im->width) + x) + 0] = r;
    im->raster[3 * (y*(im->width) + x) + 1] = g;
    im->raster[3 * (y*(im->width) + x) + 2] = b;
}

void destroy_image(struct rgb_img *im)
{
    free(im->raster);
    free(im);
}


void print_grad(struct rgb_img *grad){
    int height = grad->height;
    int width = grad->width;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            printf("%d\t", get_pixel(grad, i, j, 0));
        }
    printf("\n");    
    }
}

void image_brightness(struct rgb_img *filename, double brightness){ // is the struct in here the name of the file?
    
    // get the red/green/blue pixel #s
    // multiply them by a constant
    // If consant > 1 -- brighter, might need to round products by multiplying by a larger constant down to 255.

    
    int height = filename->height;
    int width = filename->width;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int r = get_pixel(filename, i, j, 0);
            int g = get_pixel(filename, i, j, 1);
            int b = get_pixel(filename, i, j, 2);

            int br = (int) r * brightness;
            int bg = (int) g * brightness;
            int bb = (int) b * brightness;

            if(br > 255){
                br = 255;}
            if(bg > 255){
                bg = 255;}
            if(bb > 255){
                bb = 255;}

            set_pixel(filename, i, j, br, bg, bb);
        }  
    }
}


int main(){
    struct rgb_img *imag;
    read_in_img(&imag, "pres.bin");
    image_brightness(imag, 0.8);
    write_img(imag, "pres3.bin"); // need to convert this to a png using python code
    destroy_image(imag);
    return 0;

    // pres5 -- 20
    // pres4 -- 0.5
    // pres3 -- 0.8
    // pres2 -- 6
    // pres1 -- 2

}