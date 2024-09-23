#include "TXLib.h"

struct Button {

    int x;
    int y;
    int w;
    int h;
    const char* text;

    void draw(){

        txSetColor (TX_BLACK);
        txSetFillColor (TX_BLACK);
        Win32::RoundRect (txDC(), x+5, y+5, x+w+5, y+h+5, 70, 70);

        txSetColor (TX_YELLOW);
        txSetFillColor (TX_YELLOW);
        Win32::RoundRect (txDC(), x, y, x+w, y+h, 70, 70);
        txSetColor (TX_BLACK);
        txSelectFont("asinastra", h/2,  h/4);
        txDrawText(x, y, x+w, y+h,text);

    }

    bool click() {

        return(txMouseButtons() == 1 && txMouseX()>x && txMouseX()<x+w &&
               txMouseY()>y && txMouseY()<y+h);

    }

};

void workSpace() {

    txSetColor (TX_GREY);
    txSetFillColor (TX_GREY);
    txRectangle (0, 0, 1200, 900);

    txSetColor (TX_WHITE);
    txSetFillColor (TX_YELLOW);
    txRectangle (200, 100, 1200, 900);

}

int main() {
    txCreateWindow (1200, 900);

    Button komp = {10, 10, 190, 80, "Комп"};
    Button kovr = {250, 10, 190, 80, "Коврик"};
    Button mish = {490, 10, 190, 80, "Мышь"};
    Button klava = {730, 10, 190, 80, "Клава"};
    Button mon = {970, 10, 190, 80, "Моник"};

    HDC komp1 = txLoadImage("foto/komp/whiteComp.bmp");
    HDC komp2 = txLoadImage("foto/komp/aquaComp.bmp");
    HDC komp3 = txLoadImage("foto/komp/neonComp.bmp");
    HDC komp4 = txLoadImage("foto/komp/blackKomp.bmp");
    HDC komp5 = txLoadImage("foto/komp/megaComp.bmp");

    bool vidKomp = false;

    while (!GetAsyncKeyState(VK_ESCAPE)){

        txBegin();
        workSpace();

        komp.draw();
        kovr.draw();
        mish.draw();
        klava.draw();
        mon.draw();

        if (komp.click()){

            vidKomp = true;

        }

        if (vidKomp) {

            Win32::TransparentBlt(txDC(),25, 100, 150, 150, komp1, 0, 0, 750, 750, RGB(0,255,0));
            Win32::TransparentBlt(txDC(),25, 260, 150, 150, komp2, 0, 0, 700, 700, RGB(0,255,0));
            Win32::TransparentBlt(txDC(),25, 420, 150, 150, komp3, 0, 0, 1000, 1000, RGB(0,255,0));
            Win32::TransparentBlt(txDC(),25, 580, 150, 150, komp4, 0, 0, 245, 245, RGB(0,255,0));
            Win32::TransparentBlt(txDC(),25, 740, 150, 150, komp5, 0, 0, 600, 600, RGB(0,255,0));

        }

        txEnd();
        txSleep(10);
    }

    txDisableAutoPause();
    return 0;
}

