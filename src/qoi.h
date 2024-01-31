#ifndef TEST_QOI_H
#define TEST_QOI_H

#include <fstream>

#define u32 unsigned
#define u8 unsigned char

namespace QOI {
    namespace flag {
        const char rgb = 0b11111110;
        const char rgba = 0b11111111;
    }

    namespace tag {
        const char index = 0b00000000;
        const char diff = 0b01000000;
        const char luma = 0b10000000;
        const char run = 0b11000000;
    }



    struct Header {
        char magic[4] ; // octets de magie "qoif".
        u32 width ; // largeur de l'image en pixels (BE)
        u32 height ; // hauteur de l'image en pixels (BE)
        u8 channels ; // 3 = RGB, 4 = RGBA
        u8 colorspace ; // 0 = sRGB avec alpha linéaire
                        // 1 = tous les canaux sont linéaires

        void Read(std::ifstream file);
        void Write(std::ofstream file);
    };


    void Write(char* path, Header& header, char** chain);
}

#endif