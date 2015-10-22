Image Processing
=================

Function List
---
### rgb
`Colour rgb(Real r, Real g, Real b)`  
Construct and return the colour with red channel `r`, green channel `g`, and blue channel `b`.
### rgba
`Colour rgba(Real r, Real g, Real b, Real a)`  
Construct and return the colour with red channel `r`, green channel `g`, blue channel `b`, and alpha (transparency) `a`.
### hsv
`Colour hsv(Real h, Real s, Real v)`  
Construct and return the colour with hue `h`, saturation `s`, and value `v`.
### hsva
`Colour hsva(Real h, Real s, Real v, Real a)`  
Construct and return the colour with hue `h`, saturation `s`, value `v`, and alpha (transparency) `a`.
### setPixels
`Void setPixels(Colour c)`  
*Introduces local variables `r`, `g`, `b`, `h`, `s`, `v`, `x`, `y`*  
Set all pixels in the image to `c`.
### transform
`Void transform(Real xPos, Real yPos)`  
*Introduces local variables `r`, `g`, `b`, `h`, `s`, `v`, `x`, `y`*  
Set each pixel to the pixel at position (`xPos`, `yPos`).
### select
`Void select(Selection s)`  
Set the active selection to `s`.
### rectangle
`Selection rectangle(Real x1, Real y1, Real x2, Real y2)`  
Construct and return the rectangular selection from the point (`x1`, `y1`) to (`x2`, `y2`).
### region
`Mask region(Real value)`  
Construct and return the mask with strength `value` at each point.