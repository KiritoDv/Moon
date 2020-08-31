#ifndef MOON_TYPES_H
#define MOON_TYPES_H

#include <iostream>
#include <string>
#include <GL/gl.h>

class Size {
public:
    double x;
    double y;
    Size operator+(const Size& s){
        Size size;
        size.x = this->x + s.x;
        size.y = this->y + s.y;
        return size;
    }
    Size operator-(const Size& s){
        Size size;
        size.x = this->x - s.x;
        size.y = this->y - s.y;
        return size;
    }
    bool operator==(const Size& s){
        return this->x == s.x && this->y == s.y;
    }
};

class Vec2f {
public:
    float x;
    float y;
    Vec2f operator+(const Vec2f& s){
        Vec2f vec;
        vec.x = this->x + s.x;
        vec.y = this->y + s.y;
        return vec;
    }
    Vec2f operator*(const float s){
        Vec2f vec;
        vec.x = this->x * s;
        vec.y = this->y * s;
        return vec;
    }
    Vec2f operator-(const Vec2f& s){
        Vec2f vec;
        vec.x = this->x + s.x;
        vec.y = this->y + s.y;
        return vec;
    }
    Vec2f operator+=(const Vec2f& s){
        this->x += s.x;
        this->y += s.y;
        return *this;
    }
    Vec2f operator-=(const Vec2f& s){
        this->x -= s.x;
        this->y -= s.y;
        return *this;
    }
    bool operator==(const Size& s){
        return this->x == s.x && this->y == s.y;
    }
};

class Color {
public:
    int red = 255;
    int green = 255;
    int blue = 255;
    int alpha = 255;
    void bindColor(){
        glColor4f(this->red / 255.0, this->green / 255.0, this->blue / 255.0, this->alpha / 255.0);
    }

};

#endif
