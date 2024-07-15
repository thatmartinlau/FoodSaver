Pre-trained Convolutional neural network (Actually it is a resnet), able to recognize 131 types of fruits
To use it:
1. you have to firstly train it in model.py file, after a approximately 15 mins training, 
you will get a saved model file end with .pth. 
2. After you obtain the saved model, link libraries and use predict_in_c.cpp to make prediction.

To run files in cpp and py, You have to download two libraries: OpenCV and Libtorch. Please follow the instruction on official website: https://opencv.org/ and https://pytorch.org/cppdocs/installing.html.
