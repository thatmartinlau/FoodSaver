WEEK1:
Collecting training data for CNN model, approximately 1000 images per item (but i will distort/rotate/blur some images to obtain more training data). Finally, I successfully collect 800 images for each type of fruits, totally 131 types of fruits, starting cnn coding in libtorch. 

WEEK2:
Get familiar with POCO libraries, we were trying to use POCO to set up server, but finally turn to rpc implementation, struggling with setting up the environment. Also completed cnn model, waiting for training.

WEEK3:
complete the first version of framework of rpc_server_side, confirm the format of the database, communicate with frontend guys to ensure the functions that need to be implemented and the format of transfer information. We finally decide not to use SQL to store data and instead use csv to store the data from previous seesions in local computer, and everytime run the server we read from that csv. The specific coding part is completed by Adam and Esma. Debug the cnn model, it can run but there are some small problems with the accuracy. The model often recognize golden apple as apricot for example. 

WEEK4:
Finally completed the cnn model, we decide to put this function in the server, since the model can only take jpg file as input, we are trying to find a easier way to transfer image from front end to server (currently we use binary form of image). I went back to the server construction. Since Adam is in charge of the debug part of server, I now go to do the telegram bot, they want to make a bot for the marketplace barter/reade in telegram.

WEEK5:
There are some small issues in setting up the environment, I choose to use a c++ library called tgbot-cpp, easy access to telegram. There are some conflicts between the std::thread and Tgbot, it seems had to make them run together, but i finally find out.

WEEK6 - End:
Completed the telegram bot, currently the bot has: 1. login - connect telegram account with fridge account 2. Register - register a new fridge account 3. Check fridge - check the whole fridge 4. bot automatically sends remind messages every 30 mins (If the expiration date less than one day). So basically it enables users to link their telegram account to our fridge account so that they can receive messages/send commands on telegram as long as the server is running. The framework has completed and after testing it works well. Now I'm waiting for other people, I think we could implement a marketplace function, but the base function has to be in server, but the server teammates meet some problems with debugging the current functions, so maybe we can implement that later. 

Conclusion:
I participated in the design of the framework of server, and completed the basic functions for server. After that I went to write the CNN model, which is used to identify different types of fruits by inputting an image, the training dataset is the public dataset called Fruit360 on Kaggle. After that, I went to implement the telegram bot. After all these weeks, all these features work very well. I will keep improve those functions make them easier to read and run faster. 
