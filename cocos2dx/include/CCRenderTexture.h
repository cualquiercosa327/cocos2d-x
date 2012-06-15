/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org
Copyright (c) 2009      Jason Booth

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef __CCRENDER_TEXTURE_H__
#define __CCRENDER_TEXTURE_H__

#include "CCData.h"
#include "CCNode.h"
#include "CCSprite.h"
#include "CCDrawingPrimitives.h"

namespace cocos2d {

typedef enum eImageFormat
{
	kCCImageFormatJPG       = 0,
	kCCImageFormatPNG       = 1,
    kCCImageFormatRawData   = 2
} tImageFormat;
/**
@brief CCRenderTexture is a generic rendering target. To render things into it,
simply construct a render target, call begin on it, call visit on any cocos
scenes or objects to render them, and call end. For convienience, render texture
adds a sprite as it's display child with the results, so you can simply add
the render texture to your scene and treat it like any other CocosNode.
There are also functions for saving the render texture to disk in PNG or JPG format.

@since v0.8.1
*/
class CC_DLL CCRenderTexture : public CCNode 
{
    /** The CCSprite being used.
    The sprite, by default, will use the following blending function: GL_ONE, GL_ONE_MINUS_SRC_ALPHA.
    The blending function can be changed in runtime by calling:
    - [[renderTexture sprite] setBlendFunc:(ccBlendFunc){GL_ONE, GL_ONE_MINUS_SRC_ALPHA}];
    */
	CC_PROPERTY(CCSprite*, m_pSprite, Sprite)
public:
	CCRenderTexture();
	virtual ~CCRenderTexture();
    /** creates a RenderTexture object with width and height in Points and a pixel format, only RGB and RGBA formats are valid */
    static CCRenderTexture * renderTextureWithWidthAndHeight(int w, int h, CCTexture2DPixelFormat eFormat);

    /** creates a RenderTexture object with width and height in Points, pixel format is RGBA8888 */
    static CCRenderTexture * renderTextureWithWidthAndHeight(int w, int h);

    /** initializes a RenderTexture object with width and height in Points and a pixel format, only RGB and RGBA formats are valid */
    bool initWithWidthAndHeight(int w, int h, CCTexture2DPixelFormat eFormat);

    /** starts grabbing */
	void begin();

    /** starts rendering to the texture while clearing the texture first.
    This is more efficient then calling -clear first and then -begin */
    void beginWithClear(float r, float g, float b, float a);

    
    /** end is key word of lua, use other name to export to lua. */
	inline void finish() { end(); }

	/** ends grabbing*/
	// para bIsTOCacheTexture       the parameter is only used for android to cache the texture
	void end(bool bIsTOCacheTexture = false);

    /** clears the texture with a color */
    void clear(float r, float g, float b, float a);

	/** saves the texture into a file */
	// para szFilePath      the absolute path to save
	// para x,y         the lower left corner coordinates of the buffer to save
	// pare nWidth,nHeight    the size of the buffer to save
	//                        when nWidth = 0 and nHeight = 0, the image size to save equals to buffer texture size
	bool saveBuffer(const char *szFilePath, int x = 0, int y = 0, int nWidth = 0, int nHeight = 0);

	/** saves the texture into a file. put format at the first argument, or ti will be overloaded with
	 * saveBuffer(const char *szFilePath, int x = 0, int y = 0, int nWidth = 0, int nHeight = 0) */
	// para name        the file name to save
	// para format      the image format to save, here it supports kCCImageFormatPNG and kCCImageFormatJPG */
	// para x,y         the lower left corner coordinates of the buffer to save
	// pare nWidth,nHeight    the size of the buffer to save
	//                        when nWidth = 0 and nHeight = 0, the image size to save equals to buffer texture size
	bool saveBuffer(int format, const char *name, int x = 0, int y = 0, int nWidth = 0, int nHeight = 0);

    /* get buffer as UIImage, can only save a render buffer which has a RGBA8888 pixel format */
    CCData *getUIImageAsDataFromBuffer(int format);

	/** save the buffer data to a CCImage */
	// para pImage      the CCImage to save
	// para x,y         the lower left corner coordinates of the buffer to save
	// pare nWidth,nHeight    the size of the buffer to save
	//                        when nWidth = 0 and nHeight = 0, the image size to save equals to buffer texture size
	bool getUIImageFromBuffer(CCImage *pImage, int x = 0, int y = 0, int nWidth = 0, int nHeight = 0);

	// Drawing primitives
    void setPointSize(float size);	
    void setColor(float r, float g, float b, float a);
    void setLineWidth(float width);
    void drawPoint(float x, float y, float r, float g, float b, float a);
    void drawLine(float x0, float y0, float x1, float y1);
    void drawCircle(float x, float y, float radius, int segments, float angle, bool fill);
    void drawQuadBezier(float x0, float y0, float x1, float y1, float x2, float y2, int segments);
    void drawCubicBezier(float x0, float y0, float x1, float y1, float x2, float y2,  float x3, float y3, int segments);
    void drawTriangle(float x0, float y0, float x1, float y1, float x2, float y2, bool fill);
    void drawRectangle(float x, float y, float width, float height, bool fill);

protected:
	GLuint				m_uFBO;
	GLint				m_nOldFBO;
	CCTexture2D			*m_pTexture;
	CCImage				*m_pUITextureImage;
    GLenum				m_ePixelFormat;
};

inline void CCRenderTexture::setPointSize(float size)
{
	glPointSize(size);
}

inline void CCRenderTexture::setColor(float r, float g, float b, float a)
{
	glColor4f(r, g, b, a);
}

inline void CCRenderTexture::drawPoint(float x, float y, float r, float g, float b, float a)
{
	glColor4f(r, g, b, a);
	ccDrawPoint(CCPointMake(x, y));
}

inline void CCRenderTexture::drawLine(float x0, float y0, float x1, float y1)
{
    ccDrawLine(CCPointMake(x0, y0), CCPointMake(x1, y1));
}

inline void CCRenderTexture::drawCircle(float x, float y, float radius, int segments, float angle, bool fill)
{
    ccDrawCircle(CCPointMake(x, y), radius, angle, segments, false, fill);
}

inline void CCRenderTexture::drawQuadBezier(float x0, float y0, float x1, float y1, float x2, float y2, int segments)
{
    ccDrawQuadBezier(CCPointMake(x0, y0), CCPointMake(x1, y1), CCPointMake(x2, y2), segments);
}

inline void CCRenderTexture::drawCubicBezier(float x0, float y0, float x1, float y1, float x2, float y2,  float x3, float y3, int segments)
{
    ccDrawCubicBezier(CCPointMake(x0, y0), CCPointMake(x1, y1), CCPointMake(x2, y2), CCPointMake(x3, y3), segments);
}

inline void CCRenderTexture::drawTriangle(float x0, float y0, float x1, float y1, float x2, float y2, bool fill)
{
	CCPoint vertices[] = { CCPointMake(x0, y0), CCPointMake(x1, y1), CCPointMake(x2, y2) };
	ccDrawPoly(vertices, 3, true, fill);
}

inline void CCRenderTexture::drawRectangle(float x, float y, float width, float height, bool fill)
{
	CCPoint vertices[] = { CCPointMake(x, y), CCPointMake(x+width, y), CCPointMake(x+width, y+height), CCPointMake(x, y+height) };
	ccDrawPoly(vertices, 4, true, fill);
}

} // namespace cocos2d

#endif //__CCRENDER_TEXTURE_H__
