//
// Created by alex on 30/08/20.
//

#ifndef MOON_TEXTURE_H
#define MOON_TEXTURE_H

#include <iostream>


class Texture {
public:
    Texture(std::string path);
    int width;
    int height;
    void bindTexture();
private:
    unsigned int textureId;
};


#endif //MOON_TEXTURE_H
