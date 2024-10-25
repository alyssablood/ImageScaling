

//
// Created by lutfi on 10/16/2024.
//


#ifndef IMAGE_H
#define IMAGE_H






class Image {
private:
    unsigned char* imageData;
    unsigned int width, height;




public:
    Image();


    Image(unsigned char* imageData);


    unsigned char *getImageData();


    unsigned char *getPixelData();


    unsigned char getWidth();


    unsigned char getHeight();


    void setImageData(unsigned char *newData);


};






#endif //IMAGE_H
