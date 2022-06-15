#include <iostream>
#include <fstream>
#include <random>
#include <time.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb/stb_image.h"
#include "stb/stb_image_resize.h"
#include "stb/stb_image_write.h"

using namespace std;


//Image structure
struct MyImg{
    unsigned char* data;
    int width;
    int channels;
    int height;
    const char* filename;
};

//Function displays information about the image
void print_img_info(MyImg img){
    cout << "file Name = " << img.filename << "\n" << "width = " << img.width << "\n" << "height = " << img.height << "\n" << "channels = " << img.channels << endl;
}

//Selects a section to crop the image
MyImg get_subregion(MyImg img, int top, int left, int bottom, int right){
    MyImg img2 = img;
    img2.width = (right-left);
    img2.height = (bottom-top);
    img2.channels = img.channels;
//    unsigned char* data = malloc((img2.width)*(img2.height)*(img2.channels));
    int r = 0;
    int c = 0;
    for(int i = 0; i != img.height*img.width*img.channels; i += img.channels){
        if(r > top && r < bottom){
            if(c > left && c < right){
                img2.data[i] = img.data[i];
                img2.data[i+1] = img.data[i+1];
                img2.data[i+2] = img.data[i+2];
            }
        }
        else if(c == img.width){
            r++;
            c = 0;
        }
        else{
            c++;
        }
    }
    return img2;
}

int main(){
    MyImg img;
    img.filename = "apple.jpg";
    img.data = stbi_load(img.filename, &img.width, &img.height, &img.channels, 0);
    if (img.data == 0) {
        cout << "Loading image file failed" << endl;
        return -1;
    }
    cout << "img.height*img.width*img.channels" << img.height*img.width*img.channels << endl;

    cout << "Image details" << endl;
    print_img_info(img);
    srand(time(NULL));

    
// Dont think i can use this as i need to make this function    
//    stbir_resize_uint8(img.data, img.width, img.height, 0, );

    MyImg img2 = get_subregion(img, 50, 5, 250, 200);
    img2.filename = "apple-resized.jpg";

    stbi_write_jpg(img2.filename, img2.width, img2.height, img2.channels, img2.data, 100);    

    cout << "Image details" << endl;
    print_img_info(img2);

    stbi_image_free(img.data);
    return 0;
}