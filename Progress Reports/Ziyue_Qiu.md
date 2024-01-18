WEEK1:
Collecting training data for CNN model, approximately 1000 images per item (but i will distort/rotate/blur some images to obtain more training data). Successfully collect 800 images for each type of fruits, totally 131 types of fruits, starting cnn coding in libtorch.

WEEK2:
Get familiar with POCO libraries. Finally turn to rpc implementation, struggling with including library in qt creater. Completed cnn model, waiting for training.

WEEK3:
complete the first version of framework of rpc_server_side, communicate with frontend guys to ensure the functions that need to be implemented and the format of transfer information. We finally decide not to use SQL to store data and instead use csv to store the data from previous seesions in local computer, and everytime run the server we read from that csv. The specific coding part is completed by Adam and Esma. Debug the cnn model, it can run but there are some small problems with the accuracy. The model often recognize golden apple as apricot for example. 

WEEK4:
Finally completed the cnn model, we decide to put this function in the server, since the model can only take jpg file as input, we are trying to find a easier way to transfer image from front end to server (currently we use binary form of image). I went back to the server construction. Since Adam is in charge of the debug part of server, I now go to do the telegram bot, they want to make a bot for the marketplace barter/reade in telegram.
