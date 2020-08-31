#include <data/types.h>
#include <GL/gl.h>
#include <cmath>
#include "DrawUtil.h"

void drawRect(float x, float y, float w, float h, Color c) {
    glBegin(GL_QUADS);
    c.bindColor();
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
    glEnd();
}

void drawLine(float x, float y, float x1, float y1, float width, Color color) {
    glEnable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);

    glPushMatrix();
    color.bindColor();
    glLineWidth(width);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x, y);
    glVertex2f(x1, y1);
    glEnd();
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
    glDisable(GL_LINE_SMOOTH);
}

double toRadians(double angle){
    return angle * M_PI / 180.0;
}


void drawRoundedRect(float x0, float y0, float x1, float y1, float radiusTopLeft, float radiusTopRight, float radiusBottomLeft, float radiusBottomRight, Color color) {
    int numberOfArcs = 18;

    float angleIncrement = 90.0F / numberOfArcs;

    glDisable(2884);
    glDisable(3553);

    glEnable(3042);
    glBlendFunc(770, 771);

    color.bindColor();

    glBegin(5);
    glVertex2f(x0 + radiusTopLeft, y0);
    glVertex2f(x0 + radiusBottomLeft, y1);
    glVertex2f(x1 - radiusTopRight, y0);
    glVertex2f(x1 - radiusBottomRight, y1);
    glEnd();

    glBegin(5);
    glVertex2f(x0, y0 + radiusTopLeft);
    glVertex2f(x0 + radiusTopLeft, y0 + radiusTopLeft);
    glVertex2f(x0, y1 - radiusBottomLeft);
    glVertex2f(x0 + radiusBottomLeft, y1 - radiusBottomLeft);
    glEnd();

    glBegin(5);
    glVertex2f(x1, y0 + radiusTopRight);
    glVertex2f(x1 - radiusTopRight, y0 + radiusTopRight);
    glVertex2f(x1, y1 - radiusBottomRight);
    glVertex2f(x1 - radiusBottomRight, y1 - radiusBottomRight);
    glEnd();

    glBegin(6);
    float centerX = x1 - radiusTopRight;
    float centerY = y0 + radiusTopRight;
    glVertex2f(centerX, centerY);
    for (int i = 0; i <= numberOfArcs; i++) {
        float angle = i * angleIncrement;
        glVertex2f((float)(centerX + radiusTopRight * cos(toRadians(angle))), (float)(centerY - radiusTopRight * sin(toRadians(angle))));
    }
    glEnd();

    glBegin(6);
    centerX = x0 + radiusTopLeft;
    centerY = y0 + radiusTopLeft;
    glVertex2f(centerX, centerY);
    for (int i = 0; i <= numberOfArcs; i++) {
        float angle = i * angleIncrement;
        glVertex2f((float)(centerX - radiusTopLeft * cos(toRadians(angle))), (float)(centerY - radiusTopLeft * sin(toRadians(angle))));
    }
    glEnd();

    glBegin(6);
    centerX = x0 + radiusBottomLeft;
    centerY = y1 - radiusBottomLeft;
    glVertex2f(centerX, centerY);
    for (int i = 0; i <= numberOfArcs; i++) {
        float angle = i * angleIncrement;
        glVertex2f((float)(centerX - radiusBottomLeft * cos(toRadians(angle))), (float)(centerY + radiusBottomLeft * sin(toRadians(angle))));
    }
    glEnd();

    glBegin(6);
    centerX = x1 - radiusBottomRight;
    centerY = y1 - radiusBottomRight;
    glVertex2f(centerX, centerY);
    for (int i = 0; i <= numberOfArcs; i++) {
        float angle = i * angleIncrement;
        glVertex2f((float)(centerX + radiusBottomRight * cos(toRadians(angle))), (float)(centerY + radiusBottomRight * sin(toRadians(angle))));
    }
    glEnd();

    glEnable(3553);
    glEnable(2884);
    glDisable(3042);
}

void drawRoundedRect(float x, float y, float w, float h, float radius, Color color){
    glPushMatrix();
    glTranslatef(x, y,0);
    drawRoundedRect(0,0,w, h, radius, radius, radius, radius, color);
    glPopMatrix();
}

void drawTexture(int x, int y, float u, float v, int width, int height, float textureWidth, float textureHeight) {

    float f = 1.0 / textureWidth;
    float f1 = 1.0 / textureHeight;

    glEnable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
    glTexCoord2f(u * f, (v + (float)height) * f1);
    glVertex2f(x, y + height);
    glTexCoord2f((u + (float)width) * f, (v + (float)height) * f1);
    glVertex2f(x + width, y + height);
    glTexCoord2f((u + (float)width) * f, v * f1);
    glVertex2f(x + width, y);
    glTexCoord2f(u * f, v * f1);
    glVertex2f(x, y);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
}