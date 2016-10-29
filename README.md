# LicensePlateLocate
# Function
1)A simple software to load, manage your car picture and locate the license plate.
2)Provide a Listview of index, image name, image type, image size, license location and image file location.
3)Can recognize a single license plate if the picture is clear enough:)
4)Probably with some bugs so your feedback/help is important to me!

#Language
C++/CLR

#log 20161029
Still in a very beginning stage,so:
1) can only locate 1 license plate;
2) sometimes can't locate properly.

Method is:
Step1: Convert to gray image
Step2: Vertical image edge detection (with Sobel operator)
Step3: Adaptive binarization processing
Step4: Morphological manipulation
Step5: Contour detection
