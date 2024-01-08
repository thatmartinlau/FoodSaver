Weekly Progress Charlotte Begon-Lours
  
Session 1 : 27/11
   Learn about Poco's library and how to use it. 
   Try to understand how we could implement an image recongnition code, 
   to identify the ingredients from picture instead of listing them one by one. 

Session 2 : 30/11
  With the idea that the app could generate recipes based on the different ingredients we have in our fridge, I've been trying    to find a way to implement this functionality using an API. 
  After extensive research, I have a better understanding of how to use the Spoonacular API. 

Session 3 : 4/12
  Following on from the implementation of a food recipe generator. I'm trying to code and implement this functionality using      the Spooncular API, which is the most popular API. 
  However, I've realised that most of the code to implement this functionality is provided using a configuration for Tailwind     CSS in JavaScript using CommonJS syntax. However, C++ is not generally used to configure web development tools such as          Tailwind CSS. Therefore, we should try another option or try to translate the code into C++ which is not ideal for              configuring web development tools.

Session 4 : 7/12
  Instead of looking for an API food generator, for now we can create a file with tons of recipes that are most used within the   Bachelo, or the most common recipes in general given the Bachelor's international culture. The bonus would be to select only    recipes that are quick and easy to make. These recipes will be put together in a single file so that, from the list of          ingredients in the fridge and their priority for consumption, we can generate a list of recipes. 
  Then, we just have to implement a code that open and look through a file. 

Session 5 : 11/12
Delving into how  we could organise the file of recipes so that we optimize the structure of the code and simplify its access. Brainstorming on what are the main things someone will be looking at when looking for a recipe, which one should come first, how many recipes should the app show,where can we find recipes.
Came to a conclusion to use an .CSV file so that we can categorized the recipes into differents categories depending for instance on their type : vegetarian, vegan, fish, meat, gluten free... if they are sweat or salty recipes , the time consumming etc.. 
Therfore the easiest is to store these recipes in a table hence .CSV file.

Session 6 : 14/12
Coding the parsing of a .CSV file in C++.
