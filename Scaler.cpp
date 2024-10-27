//
// Created by lutfi on 10/16/2024.
//


#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "ConsoleGfx.cpp"

#include "string"
using namespace std;

#include "Image.h"




unsigned char *scaledImage(unsigned char *imageData, int orders)
{
    int width = imageData[0];
    int height = imageData[1];
    int scale = std::pow(2,orders);
    int scaledWidth, scaledHeight;

    if (orders == 0)
    {
        return imageData;
    }
    if (orders > 0)
    {
        scaledWidth = std::min( width * scale, 256);
        scaledHeight = std::min(height * scale, 256);

    }
    if (orders > 0)
    {
        scaledWidth = std::max(width / scale,1);
        scaledHeight = std::max(height / scale, 1);
    }


    //created 2D array of image data
    std::vector real(height, std::vector<unsigned char>(width));
    //created 2D array of new image data
    std::vector scaled(scaledHeight, std::vector<unsigned char>(scaledWidth));




}







int main()
{

    ConsoleGfx *consoleGfx = ConsoleGfx::getInstance();
    bool game = true;
    bool loaded = false;
    int choice = 0;
    Image *image = new Image(consoleGfx->testRainbow);






    std :: cout << "Welcome to the Image Scalar!" << std :: endl;
    std :: cout << "Displaying Spectrum Image:" << std :: endl;
    //unsigned char *rainbowimage = consoleGfx->loadFile(consoleGfx.testRainbow);


    consoleGfx->displayImage(consoleGfx->testRainbow);



    while (game)
    {
        std :: cout << "Scaler Menu" << std :: endl;
        std :: cout << "-----------" << std :: endl;
        std :: cout << "0. Exit" << std :: endl;
        std :: cout << "1. Load File" << std :: endl;
        std :: cout << "2. Load Test Image" << std :: endl;
        std :: cout << "3. Display Image" << std :: endl;
        std :: cout << "4. Enlarge Image" << std :: endl;
        std :: cout << "5. Shrink Image" << std :: endl;
        std :: cout << "6. Show Image Properties" << std :: endl;

        std :: cout << "Select a Menu Option: ";
        cin >> choice;

        if (choice == 0)
        {
            game = false;
        }
        else if (choice == 1)
        {
            std :: cout << "Enter name of file to load: ";
            std :: string imageName;
            cin >> imageName;

            if ((consoleGfx->loadFile(imageName)) != nullptr)
            {
                image->setImageData((consoleGfx->loadFile(imageName)));
                loaded = true;

            } else
            {
                std :: cout << "Error: could not load file." << std :: endl;
            }

        }
        else if (choice == 2)
        {
            std :: cout << "Test image data loaded. " << std :: endl;
            image->setImageData((consoleGfx->testImage));
            loaded = true;

        }
        else if (choice == 3)
        {
            if (loaded == true)
            {
                consoleGfx->displayImage(image->getImageData());
            } else
            {
                std :: cout << "Error: no image loaded." << std :: endl;
            }

        }
        else if (choice == 4)
        {
            if (loaded == true)
            {
                std :: cout << "Enter orders of magnitude for reduction: ";
                int  big;
                std:: cin >> big;


            } else
            {
                std :: cout << "Error: no image loaded." << std :: endl;
            }


        }
        else if (choice == 5)
        {
            if (loaded == true)
            {
                std :: cout << "Enter orders of magnitude for enlargement: ";
                int  shrink;
                std:: cin >> shrink;


            } else
            {
                std :: cout << "Error: no image loaded." << std :: endl;
            }
        }
        else if (choice == 6)
        {
            std :: cout << "Image Dimensions: (" << static_cast<int>(image->getWidth()) << "," << static_cast<int>(image->getHeight())<< ")"<< std :: endl;
        }
        else
        {
            std :: cout << "Error: invalid choice." << std :: endl;
        }


    }
}
