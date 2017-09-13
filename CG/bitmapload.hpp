#ifndef BITMAPLOAD_HPP_INCLUDED
#define BITMAPLOAD_HPP_INCLUDED
#include <fstream>
unsigned char* readBMP(char* filename)
{
    int i;
    FILE* f = fopen("img1.bmp", "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    int size = 3 * width * height;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
    fclose(f);

    for(i = 0; i < size; i += 3)
    {
            unsigned char tmp = data[i];
            data[i] = data[i+2];
            data[i+2] = tmp;    //converter de rbg para rgb
   }

    return (unsigned char*)data;
}

#endif // BITMAPLOAD_HPP_INCLUDED
