
// A.L. Khizha, 2016-10-22
//
#ifndef _GRAPHICS_
#define _GRAPHICS_

#include <objidl.h>
#include <gdiplus.h>
#pragma once
#pragma comment(lib,"gdiplus.lib")

namespace Grfx
{

class Graphics
{
   HWND hWnd;
   HDC hDC;
   Gdiplus::Color color;
   Gdiplus::Graphics * gr;
   ULONG_PTR           gdiplusToken;
public:

   Graphics();
   ~Graphics();
   void setcolor(int c);
   void line(int x, int y, int x2, int y2);
   void circle(int x, int y, int r);
   void rectangle(int x, int y, int x2, int y2);
}; // class Graphics

}; // namespace Grfx

#endif
