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
    std::string filename;
};

//Function displays information about the image
void print_img_info(MyImg* img){
    cout << "width = " << img->width << "\n" << "height = " << img->height << "\n" << "channels = " << img->channels << endl;
}

int main(){
    MyImg img; 
    img.data = stbi_load("apple.jpg", &img.width, &img.height, &img.channels, 0);
    if (img.data == 0) {
        cout << "Loading image file failed" << endl;
        return -1;
    }

    cout << "Image details" << endl;
    print_img_info(&img);
    srand(time(NULL));

    //setting pixels to black
    for(unsigned char* p = img.data; p != img.data + img.height*img.width*img.channels; p += img.channels){
        if(rand()%100 > 80.0){
            *p = (uint8_t) 0; //red
            *(p+1) = (uint8_t) 0; //green
            *(p+2) = (uint8_t) 0; //blue
        }
    }
    stbi_write_jpg("apple-copy.jpg", img.width, img.height, img.channels, img.data, 100);    

    stbi_image_free(img.data);
    return 0;
}
