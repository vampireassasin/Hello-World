#include "pch.h"
#include <iostream>
#pragma pac(1)

struct BITMAPFILEHEADER {
unsigned short bftype; //BM
unsigned int bfsize;//
unsigned int dwReserved;
unsigned int bOffBits;//sizeof(BFH) + sizeof(BIH)
};


struct BITMAPINFOHEADER {
unsigned int biSize;//40
int biWidth;//
int biHeight;//
unsigned short biplanes;//1
unsigned short biBitcount;//24
unsigned char bzeros[16];
};

int main()
{
FILE * f = fopen("morder.bmp", "wb");
BITMAPFILEHEADER bfh = { };
BITMAPINFOHEADER bih = { };

bfh.bftype = 0x4D42;
bfh.bfsize = sizeof(bfh) + sizeof(bih) + 16 * 16 * 3;
bfh.bOffBits = sizeof(bfh) + sizeof(bih);

bih.biSize = sizeof(bih);
bih.biWidth = 16;
bih.biHeight = 16;
bih.biplanes = 1;
bih.biBitcount = 24;

fwrite(&bfh, sizeof(bfh), 1, f);
fwrite(&bih, sizeof(bih), 1, f);

for (int i = 0; i < 16; i++) {
for (int j = 0; j < 16; j++) {
unsigned char R, G, B;
R = G = B = 0;
fwrite(&B, 1, 1, f);
fwrite(&G, 1, 1, f);
fwrite(&R, 1, 1, f);
}
}

fclose(f);

}
