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
*Introduces local variables `r`, `g`, `b`, `h`, `s`, `v`, `x`, `y`*  
Construct and return the mask with strength `value` at each point.
### kernel
`Kernel kernel(Real k1, Real k2, Real k3, Real k4, Real k5, Real k6, Real k7, Real k8, Real k9)`  
Construct and return the 3x3 convolution kernel with elements `k1` ... `k9`
### convolve
`Void convolve(Kernel k)`  
*Introduces local variables `r`, `g`, `b`, `h`, `s`, `v`, `x`, `y`*  
Convolve the image using the kernel `k`.
### mask
`Void mask(Mask m)`  
Set the active mask the `m`.
### all
`Mask all(Void)`  
Construct and return a mask with value 1 everywhere.
### getPixel
`Colour getPixel(Real xPos, Real yPos)`  
Returns the pixel at position (`xPos`,`yPos`).  
### fuzzy
`Selection fuzzy(Real xPos, Real yPos, Real threshold)`  
Construct and return the selection consisting of the contiguous region based at (`xPos`,`yPos`), with maximum colour distance `threshold`.
### set
`Void set(String name, Variable data)`  
Create the variable `name` with value `data`, or update it if it already exists.
### if
`Void if(Real condition, Sequence block)`  
If `condition` is true, evaluate `block`.
### repeat
`Void repeat(Real loops, Sequence block)`  
Evaluate `block`, `loops` times.
### while
`Void while(Real condition, Sequence block)`  
While `condition` is true, evaluate `block`
### loadImage
`Image loadImage(String filename)`
Load the image file `filename` and return it.  
Supported file types: `bmp, png, tga, jpg, gif, psd, hdr and pic `
### using
`Void using(Image i)`  
Set the active image to `i`. All consequent operations will be performed on `i`.
### crop
`Image crop(Void)`  
Contruct and return the smallest image containing only the pixels in the active mask.
### blend
`Void blend(Image i, Colour c)`  
*Introduces local variables `r1`, `g1`, `b1`, `a1`, `h1`, `s1`, `v1`, `r2`, `g2`, `b2`, `a2`, `h2`, `s2`, `v2`, `x`, `y`*  
Set all pixels in the image to `c`.
### combine
`Mask combine(Mask a, Mask b, Real newValue)`  
*Introduces local variables `v1`, `v2`*  
Construct and return the mask with value at each pixel `newValue`.
### gauss
`Kernel gauss(Real size, Real sigma)`  
Construct and return the Gaussian kernel with size `size` and sigma `sigma`.