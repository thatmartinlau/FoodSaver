Weekly Progress Elisabeth Le Leslé
  
Session 1 : 27/11
   Brainstorm on different functionalities we could implement and add to the core server and app.
   Current ideas: 
    - photo recognition of unscannable items: research on convolutional neural networks and how to access the camera
      (would be using deep learning)
    - barcode scan: research on APIs that could translate photos of the barcode into a binary format
    - priority expirations (green to red): with the information of expiration dates, use a color code to see which foods should be eaten first to avoid waste
    - recipe ideas given the ingredients you have in your fridge: must determine whether we should use a generating AI or implement an ingredients choice option 
    - seeing people’s fridges: sort of like an Instagram for fridges, where one can add comments

Session 2: 
Lots of research done on the different recipe generating websites, like Tesco recipe finder, SuperCook or Dishgen, as well as on the different API options for barcode scanning of ingredients.

Session 3:
    - download XCode on MacOS to download OpenCV 
    - Continued research on the barcode scan, through Youtube tutorials, github projects on a similar topic. The softwares needed still don’t work (XCode, Command Line Tools, Homebrew, OpenCV). I managed to add the PDF.Co API, which supposedly reads 1D and 2D Barcodes, but on QT Creator, I did not know how to use the code sample. 

Session 4:
    - found PDF.co API : analysis of downloaded code that implements the API
    After a talk with the professor in lecture and more research on the topic, the API implementation of a barcode scan and a recipe generator was sadly abandoned. With the implementations team, we discussed the possibility of creating our own Recipe Class from scratch, and create its very own database. We were thinking of a JSON file format for easy access.
    - more research on recipe generating: instead of implementing a hard API, we would make our own Recipe Class, with ingredient selection from fridge, taking expiration priority into account, using dictionaries to store different recipes, 
    - these would be Bachelor recipes, and there would be a functionality to add your own recipe (user string as input, add to recipe dictionary)
    

Session 5:
- more research on the Recipe Class and its different functions:
  Recipe class functions:
  - initialization function: ingredients in user’s fridge their quantity, key ingredient, diet (vegan…), recipe time interval:
    - for ingredients the user already possesses, import them from the Fridge class
    - for other ingredients contained in the recipes: import Ingredient Class
  - open the file in dictionary format (JSON file), that contains the recipe number, its name as string, diet restriction as string, time to cook as int, ingredient list, instructions string, recipe picture URL as a string 
  - for now, define a simple empty list matching_recipes to which we append all recipes with the given ingredients
  - then there should be a sorting for maximum optimization
  => should return recipe ideas (with pictures?) in order of relevance (most fridge and recipe ingredients in common)
ideally, we would want to implement another function that would allow bachelors to add their very own recipes to the data base. However, out of simplicity (and to spare us the difficulty of converting the recipes to JSON format), the website would have spaces to write each recipe characteristic in the format we want (error if not the same format e.g. lowercase, int, list of ingredients separated by commas and no spaces, upload a picture of the recipe and extract its URL?

Session 6:

discussed the add Bachelor recipes implementation with the front end team
as our new class Recipe is based on the previous Ingredient and Fridge classes, i spent time with the server team to understand and use their code

Session 7: 

Currently focusing on the adding recipes part from the Bachelor aspect: code of the json functions to read JSON from a file (to read the data), to write JSON to a file (this will be used to add the Bachelor recipes from the website into the JSON database)
file is temp.json.cpp . 
The plan is to have a file that reads the JSON recipe dataset, one that writes a JSON file out of the strings imputed by the user
then having a JSON merging function to add the newly written JSON in the JSON recipe dataset

Session 8:
finished the recipe class with Charlotte with the adding new recipes part: instead of the previous function ideas and tests, there is now a JSON reader function, and an adding  new recipe function where the strings are taken directly from the user typing bars and then inserted into the JSON recipe dataset : called RecipeBook.cpp and RecipeBook.hpp
currently working on using the recipe class and the recipe json data set to write a code that, given a string (from a search bar from a website) of ingredients, then another with a dietary restriction (not always given but if given, must take into account), then another with an ideal cooking time. the ingredients are the priority, then the diet restriction and then the cooking time. the code should return a list of recipe names with ingredients in common with the given input ingredients string, diet restriction and cooking time. SOrt by order of things in common between the asked recipe and the given one (first put the recipes with the most recipe ingredients in common with the input ingredient string with the right diet and similar cooking time, then the recipes with the most recipe ingredients in common with the input ingredient string with the right diet, then the recipes with the most recipe ingredients in common with the input ingredient string, and then other recipes with common ingredient(s) and diet). 
created a new RecipeSearch.cpp and recipeSearch.hpp that describe a new RecipeSearch class (using the RecipeBook class and the Recipes.json file. With Cyriac : create an interface for users to type the ingredients, the diet restriction  and the cooking time in the recipe search. Basically they would need a space on the page called “Recipe Search” or they would have 3 spaces to Type:
- the first for the ingredients (a string where each ingredient is written with a capital letter and separated by a comma, but you can just write it next to the box so they understand, don't worry about converting the strings)
- the second for dietary restrictions (like Vegetarian…) like a thong in capital letters
- the third for the cooking time in minutes (just an int)
Just like ofr adding recipes, there will be one searchbar in which the user prompt will be of the form : “Vegetarian pasta with…”

Personal cookbook:
cyriac: button to save recipes (QML …)
sixtine (test3 front): give type of recipe: std::map is an ordered associative container that contains key-value pairs.
// Declare a map with string keys and int values std::map<std::string, int> myDictionary; // Insert key-value pairs into the map myDictionary["apple"] = 5;
code a PersonalRecipes class that includes the User class: it should have an addRecipe function that appends a recipe in dictionary format to a list individualised for each user
in the qml button code, say that it gets filled with color when clicked and that the recipe associated to each button gets added to a list
this list in stored in the personal recipe class
the personal cookbook page

Session 9:
left aesthetics button for later: instead of an outlined star or heart that fills its color when clicked on, the button is a LIKE button
onClicked now opens a popup that I called personalCookBook (in PersonalCookBook.qml file)
i want my popup to show all of my stored liked recipes. however, the liked recipes need to be stored in the user class (vectors of recipes) in order for the popup to show each user’s liked recipes.
for that, i need my “LIKE” button to open the popup, but also the Personal Cookbook button to open the popup.
furthermore, for the liked recipes to show on the popup, I need to write an attribute in the User class that saves the recipe names (?)

Session 10:
With Sixtine, helped with the functions like_recipe and unlike_recipe, which I’m going to use to add or take recipes from the Personal Cookbook. The liked_recipes is a vector in the user.h file used to store the recipes in question in the user’s file, in order to individualize the liked recipes. in the OnClicked section of the button, I’m going to have to differentiate when I click to add a recipe, and when I click to remove a recipe from the favorites. I have 2 options: either I find a way to unlike when the recipe is already in liked recipes, and then it’s removed, or if I create a second button “UNLIKE” but that’s only present in the popup of the liked functions. 
in main.cpp of the cyriac-recipes branch, I included the user.h file to be able to link the QML with the functions on the front end.

Session 11: 
Finalized the button








