//
// Urho3D Engine
// Copyright (c) 2008-2011 Lasse ��rni
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef UI_BUTTON_H
#define UI_BUTTON_H

#include "BorderImage.h"

//! Button UI element states
enum ButtonState
{
    BUTTON_INACTIVE = 0,
    BUTTON_HOVER,
    BUTTON_PRESSED
};

//! An image that reacts to mouse presses
class Button : public BorderImage
{
public:
    //! Construct with name
    Button(const std::string& name = std::string());
    //! Destruct
    virtual ~Button();
    
    //! Load parameters from an XML file
    virtual XMLElement loadParameters(XMLFile* file, const std::string& elementName, ResourceCache* cache);
    //! Perform UI element update
    virtual void update(float timeStep);
    //! Return UI rendering batches
    virtual void getBatches(std::vector<UIBatch>& batches, std::vector<UIQuad>& quads, const IntRect& currentScissor);
    //! React to mouse hover
    virtual void onHover(const IntVector2& position, const IntVector2& screenPosition, unsigned buttons);
    //! React to mouse click
    virtual void onClick(const IntVector2& position, const IntVector2& screenPosition, unsigned buttons);
    
    //! Set inactive image rectangle
    void setInactiveRect(const IntRect& rect);
    //! Set inactive image rectangle
    void setInactiveRect(int left, int top, int right, int bottom);
    //! Set hovering image rectangle
    void setHoverRect(const IntRect& rect);
    //! Set hovering image rectangle
    void setHoverRect(int left, int top, int right, int bottom);
    //! Set pressed image rectangle
    void setPressedRect(const IntRect& rect);
    //! Set pressed image rectangle
    void setPressedRect(int left, int top, int right, int bottom);
    //! Set optional label UI element
    void setLabel(UIElement* label);
    //! Set label offset on press
    void setLabelOffset(const IntVector2& offset);
    //! Set label offset on press
    void setLabelOffset(int x, int y);
    
    //! Return inactive image rectangle
    const IntRect& getInactiveRect() const { return mInactiveRect; }
    //! Return hovering image rectangle
    const IntRect& getHoverRect() const { return mHoverRect; }
    //! Return pressed image rectangle
    const IntRect& getPressedRect() const { return mPressedRect; }
    //! Return label UI element
    UIElement* getLabel() const { return mLabel; }
    //! Return label offset on press
    const IntVector2& getLabelOffset() const { return mLabelOffset; }
    
protected:
    //! Set new state
    void setState(ButtonState state);
    //! Set offset of label depending on button press state
    void updateLabelOffset();
    
    //! Label UI element
    SharedPtr<UIElement> mLabel;
    //! Inactive image rectangle
    IntRect mInactiveRect;
    //! Hovering image rectangle
    IntRect mHoverRect;
    //! Pressed image rectangle
    IntRect mPressedRect;
    //! Label offset on press
    IntVector2 mLabelOffset;
    //! Current state
    ButtonState mState;
    //! Hovering flag
    bool mHoveringThisFrame;
};

#endif // UI_BUTTON_H
