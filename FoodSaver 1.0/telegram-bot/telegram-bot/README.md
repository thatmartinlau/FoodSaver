To run the tgbot, please use the vcpkg. To correctly implement the CMakeLists, please download the vcpkg based on the 
official guidance on this website: https://vcpkg.io/en/getting-started.html. 
Clone and download the vcpkg under this 

telegram-bot folder, to run this project successfully, you have to download the rpclib and tgbot-cpp in vcpkg using command: 
"./vcpkg/vcpkg install rpclib" and "./vcpkg/vcpkg install tgbot-cpp". 

After that, if you are using a mac, in terminal, cd to this telegram-bot folder, then use the following command to 
firstly build the project: cmake --build build, and use this command to run the project: ./build/TELEGRAM_BOT. 

These operations should enable to run the project. Find the telegram bot in telegram and talk to him based on his API:
"6644281748:AAFh40LQLa5054caEUPt8T_9wf-Yv1hAB-w".

If there are any problem with rpc, remember to check your port number is consistent with the one used by the server.
