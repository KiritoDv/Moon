//
// Created by alex on 30/08/20.
//

#ifndef MOON_DRAWUTIL_H
#define MOON_DRAWUTIL_H

void drawRect(float x, float y, float w, float h, Color c);
void drawLine(float x, float y, float x1, float y1, float width, Color color);
void drawRoundedRect(float x0, float y0, float x1, float y1, float radiusTopLeft, float radiusTopRight, float radiusBottomLeft, float radiusBottomRight, Color color);
void drawRoundedRect(float x, float y, float w, float h, float radius, Color color);
void drawTexture(int x, int y, float u, float v, int width, int height, float textureWidth, float textureHeight);
#endif
