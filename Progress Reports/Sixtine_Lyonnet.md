27/11/2023
I discussed what the visual and main features of the website with the front-end/app group.
I wrote the hpp file of the main classes with Cyriac: user, fridge, offer and ingredient.

30/11/2023
I tried to set up my laptop by downloading all necessary extensions and different software to be able to create a website/app on QtCreator.

04/12/2023
I wrote the User class in front.cpp. I also modified the hpp file accordingly. Finally, I corrected all bugs in those two files and reached out to my colleagues about what they need and expect of my team during the TD.

07/12/2023
I corrected the bug in the pop_elt function of the Fridge class. I modified the front.hpp and front.cpp files accordingly. I also changed the hierarchy of the classes in the file to make it easier to code the cpp of the Offer class. This also makes the overall project more coherent. I discussed those changes with the different teams. I added the hpp declaration of the sort_ingredients function I want to add to the Fridge class.

11/12/2023
I had an issue with Qt creator. I asked for help and was told I should delete it and download it again. This took a long time as there is terrible WiFi in the amphi.

12/12/2023
I finished downloading all necessary things for Qt.

13/12/2023
I added a Date class to the front.hpp file and defined the necessary classes in the cpp file.
I tested the functions and classes I created.
The TA told me defining things on the heap is considered bad practice so I put everything on the stack instead.

18/12/2023
I asked my collegues what I needed to implement to make the project work in the future and to make their work easier.
I kept working on my code and worked out a few major bugs in some functions.
I started to try and implement a function that compares a date with the current date in order to check if the ingredient is expired and/or expiring soon.

21/12/2023
I finished implementing the Date class.
I also added a method requested by my collegues.
I was told by my TA that the classes should be impplemented in separate cpp and h files, so I split the code from front.cpp and front.hpp in 5 different files.

24/12/2023
I added a get_ingredient_list method in Offer.
I merged the front branch with the front_merge branch.

02/01/2024
I discussed different problems in our class implementation with other group members.
I realised the Offer function had a mistake and was badly implemented.

04/01/2024
I implemented two sorting functions in the Fridge class with Martin's help.
I made all necessary modifications to the User class to align my definition with Martin's one on the app.
I corrected the Offer class which was badly implemented and discussed what was expected of me with Antoine.

07/01/2024
I changed the Offer and User classes.
I also got rid of the quantity variable in Offer.
I also changed to hierarchy of the classes accordingly.

08/01/2024
I discussed with each member of the app to better adapt my back-end code to their needs.
- Fanny: I made some necessary arrangements on the User class to help implement the logic behind her login page.
- Cyriac, Charlotte and Elisabeth: talked about adding a recipe class.
- Antoine: showed him the functions on my code such as add_ingredient and the sorting functions of the Fridge class.
- Diana: discussed the problem she was facing and told her Esma would be better equipped to answer her.

11/01/2024
I coded the new Recipe class and added the necessary functions.
I added a is_username function to the User class as Fanny has asked me and discusses with Adam what he had to do to allow me to implement it.

15/01/2024
I tried to implement a version of is_username without Adam's help by asking Esma. However this did was unsuccessful. I discussed with Elisabeth what she needed me to code for the recipe class and made a not on Trello to add functions to like and unlike things on the User class.

18/01/2024
I adapted and added the functions Anahi wrote on the front.cpp file to the different class files. 
I changed the enum per Fanny's request and informed Oscar of the changes he had to implement for the server as a result.
I added the functions like and unlike recipe in the User class. To do so, I also had to implement an equality operator function in the recipe class.
I also started working on the presentation.

22/01/2024
I debugged a problem resulting from the update of the server with help from the TA.
