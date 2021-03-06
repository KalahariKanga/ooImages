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
*Introduces local variables `r`, `g`, `b`, `a`, `h`, `s`, `v`, `x`, `y`*  
Set all pixels in the image to `c`.
### transform
`Void transform(Real xPos, Real yPos)`  
*Introduces local variables `r`, `g`, `b`, `a`, `h`, `s`, `v`, `x`, `y`*  
Set each pixel to the colour at position (`xPos`, `yPos`).  
### select
`Void select(Mask s)`  
Set the active mask to `s`.
### rectangle
`Mask rectangle(Real x1, Real y1, Real x2, Real y2)`  
Construct and return the rectangular mask from the point (`x1`, `y1`) to (`x2`, `y2`).
### region
`Mask region(Real value)`  
*Introduces local variables `r`, `g`, `b`, `a`, `h`, `s`, `v`, `x`, `y`*  
Construct and return the mask with strength `value` at each point.
### kernel
`Kernel kernel(Real k1, Real k2, Real k3, Real k4, Real k5, Real k6, Real k7, Real k8, Real k9)`  
Construct and return the 3x3 convolution kernel with elements `k1` ... `k9`
### convolve
`Void convolve(Kernel k)`  
*Introduces local variables `r`, `g`, `b`, `a`, `h`, `s`, `v`, `x`, `y`*  
Convolve the image using the convolution kernel `k`.   
### all
`Mask all(Void)`  
Construct and return a mask with value 1 everywhere.
### getPixel
`Colour getPixel(Real xPos, Real yPos)`  
Returns the colour at position (`xPos`,`yPos`).  
### fuzzy
`Mask fuzzy(Real xPos, Real yPos, Real threshold)`  
Construct and return the mask consisting of the contiguous region based at (`xPos`,`yPos`), with maximum colour difference `threshold` (using Euclidean distance).
### set
`Variable set(String name, Variable data)`  
Create the variable `name` with value `data`, or update it if it already exists, and return it's value.  
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
Construct and return the smallest image containing only the pixels in the active mask.
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
### min
`Real min(Real expr)`  
*Introduces local variables `x`, `y`, `r`, `g`, `b`, `a`, `h`, `s`, `v`*  
Find and return the minimum value of `expr` in the image.
### max
`Real max(Real expr)`  
*Introduces local variables `x`, `y`, `r`, `g`, `b`, `a`, `h`, `s`, `v`*  
Find and return the maximum value of `expr` in the image.
### print
`Void print(Real value)`  
Print `value` to the console.
### random
`Real random(Real a, Real b)`  
Return a random number from the uniform distribution [`a`, `b`].
### createImage  
`Image createImage(Real w, Real h)`  
Construct and return a blank image with size `w` by `h`.
### function
`Function function(String arg1, String arg2, ..., Sequence body)`  
Construct the function with arguments named `arg1`, `arg2`, ..., and with body `body`.  
### saveImage
`Void saveImage(String filename)`  
Save the active image to the file `filename`. File format is inferred by the extension. 
### about  
`Void about(Variable var)`  
Print information about `var` to the console.  
### sin  
`Real sin(Real x)`  
Return the value of `sin(x)`, where `x` is in radians.  
### cos  
`Real cos(Real x)`  
Return the value of `cos(x)`, where `x` is in radians.  
### tan  
`Real tan(Real x)`  
Return the value of `tan(x)`, where `x` is in radians.  
### for
`Void for(Real from, Real to, Real step, Sequence block)`   
*Introduces local variable `c`*   
For each value of `c` from `from` to `to` in steps of size `step`, evaluate `block`.  
### break
`Void break(Void)`  
Break out of the current loop.  
### continue
`Void continue(Void)`  
Jump to the next loop iteration.  
### line  
`Mask line(Real x1, Real y1, Real x2, Real y2)`  
Construct and return the mask with points on the line between (`x1`,`y1`) and (`x2`,`y2`).  
### import
`Void import(String filename)`  
Load and run the script file `filename`.  
### erode
`Void erode(Kernel k)`  
Use greyscale erosion to erode the active mask using the structuring element `k`.  
### dilate
`Void dilate(Kernel k)`  
Use greyscale dilation to dilate the active mask using the structuring element `k`.  
### transformTo  
`Void transformTo(Real x, Real y)`  
*Introduces local variables `r`, `g`, `b`, `a`, `h`, `s`, `v`, `x`, `y`*  
Send each pixel to the position (`x`,`y`).  
### variableExists  
`Real variableExists(String name)`  
Checks if a variable called `name` exists, and if it does, returns 1, otherwise returns 0.  
### invert  
`Void invert(Mask m)`  
Invert the mask `m`  
### mask  
`Mask mask(Void)`  
Return the active mask  
### image
`Image image(Void)`  
Return the active image  
### array
`Array array(Variable e1, ..., Variable en)`  
Construct and return an array with elements `e1` up to `en`  
### flatten  
`Void flatten(Void)`  
Flatten an image with transparency to a opaque image
