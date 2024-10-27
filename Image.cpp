//
// Created by lutfi on 10/16/2024.
//

#include "Image.h"



    Image::Image(unsigned char* a)
    {
        this -> imageData = a ;
        this -> width =  imageData[0] ;
        this -> height = imageData[1] ;
    }

unsigned char* Image::getImageData()
    {
        return imageData;
    }

unsigned char* Image::getPixelData()
    {
        return &imageData[2];
    }
unsigned char Image::getWidth()
    {
        return width;
    }
unsigned char Image::getHeight()
    {
        return height;
    }
void Image::setImageData(unsigned char *newData)
    {
        this -> imageData = newData;
        this -> width =  newData[0];
        this -> height = newData[1];
    }



