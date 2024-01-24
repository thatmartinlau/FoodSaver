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



