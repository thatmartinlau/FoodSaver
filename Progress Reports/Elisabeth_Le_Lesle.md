Weekly Progress Elisabeth Le Leslé
  
Session 1 :
Brainstorm on different functionalities we could implement and add to the core server and app.
Current ideas: 
    - Photo recognition of unscannable items: research on convolutional neural networks and how to access the camera (would be using deep learning)
    - Barcode scan: research on APIs that could translate photos of the barcode into a binary format
    - Priority expirations (green to red): with the information of expiration dates, use a color code to see which foods should be eaten first to avoid waste
    - Recipe ideas given the ingredients you have in your fridge: must determine whether we should use a generating AI or implement an ingredients choice option 
    - Seeing people’s fridges: sort of like an Instagram for fridges, where one can add comments

Session 2: 
Lots of research done on the different recipe generating websites, like the Tesco recipe finder, SuperCook or Dishgen, as well as on the different API options for barcode scanning of ingredients.

Session 3:
    - Downloaded XCode on MacOS to download OpenCV 
    - Continued research on the barcode scan, through Youtube tutorials, Github projects on similar topics. The softwares needed still don’t work (XCode, Command Line Tools, Homebrew, OpenCV). I managed to add the PDF.Co API, which supposedly reads 1D and 2D Barcodes, but on QT Creator, I did not know how to use the code sample. 

Session 4:
    - Found PDF.co API and thoroughly analyzed the downloaded code that implements the API
After a talk with the professor in lecture and more research on the topic, the API implementation of a barcode scan and a recipe generator was sadly abandoned. With the implementations team, we discussed the possibility of creating our own Recipe Class from scratch, and create its very own database. We were thinking of a JSON file format for easy access.
    - More research on recipe generating: instead of implementing a complex API, we would make our own Recipe Class, with ingredient selection from fridge, taking expiration priority into account, using dictionaries to store different recipes.
    - These would be Bachelor recipes, and there would be a functionality to add your own recipe (user string as input, add to recipe dictionary).

Session 5:
More research on the Recipe Class and its different functions, including:
  - An initialization function: ingredients in user’s fridge, their quantity, key ingredient, diet (vegan…), recipe time interval:
    - for ingredients the user already possesses, import them from the Fridge class
    - for other ingredients contained in the recipes: import the Ingredient Class
  - Function to open the file in dictionary format (JSON file), that contains the recipe number, its name as string, diet restriction as string, time to cook as int, ingredient list, instructions string, recipe picture URL as a string 
  - For now, define a simple empty list matching_recipes to which we append all recipes with the given ingredients
  - Then there should be a sorting for maximum optimization
  => It should return recipe ideas (with pictures?) by order of relevance (those with the most fridge and recipe ingredients in common). Ideally, we would want to implement another function that would allow bachelors to add their very own recipes to the data base. However, out of simplicity (and to spare us the difficulty of converting the recipes to JSON format), the website would have spaces to write each recipe characteristic in the format we want (error if not the same format e.g. lowercase, int, list of ingredients separated by commas and no spaces, upload a picture of the recipe and extract its URL?). 

Session 6:
Discussed the add Bachelor recipes implementation with the front end team (mostly Cyriac).
As our new class Recipe is based on the previous Ingredient and Fridge classes, I spent time with the backend (Sixtine) to understand and use their code, and discussed on implementing new Recipe functions. 
This corresponds to the recipe.h and recipe.cpp files in the test3 folder, with functions to get or set the title, directions, ingredients, source (URL), and tags of a recipe. 

Session 7: 
Currently focusing on the adding recipes part by the users: code of the JSON functions to read JSON from a file (to read the data), to write JSON to a file (this will be used to add the Bachelor recipes from the website into the JSON database) in the file temp.json.cpp in test3 (finally not implemented). 
The plan is to have a file that reads the JSON recipe dataset, one that writes a JSON file out of the strings imputed by the user, then having a JSON merging function to add the newly written JSON in the JSON recipe dataset. 

Session 8:
- Finished the recipe class with Charlotte with the adding new recipes part: instead of the previous function ideas and tests, there is now a JsonRecipeReader class, with a reading and an adding  new recipe function where the strings are taken directly from the user typing bars and then inserted into the JSON recipe dataset : called RecipeBook.cpp and RecipeBook.hpp in test3. 
- Currently working on using the Recipe class and the recipe JSON data set to write a code that, given a string (from a search bar from the Recipe page) of ingredients, then another with a dietary restriction (not always given but if given, must take into account), then another with an ideal cooking time.
    - Priority: ingredients in common, then the diet restriction and then the cooking time.
    - The code should return a list of recipe names with ingredients in common with the given input ingredients string, diet restriction and cooking time.
    - Sort by order of things in common between the asked recipe and the given one (first put the recipes with the most recipe ingredients in common with the input ingredient string with the right diet and similar cooking time, then the recipes with the most recipe ingredients in common with the input ingredient string with the right diet, then the recipes with the most recipe ingredients in common with the input ingredient string, and then other recipes with common ingredient(s) and diet). 
- Created a new RecipeSearch.cpp and RecipeSearch.hpp (abandoned as Cyriac already implemented a similar code in his recipecontroller.h and cpp files (in app.build)) that describe a new RecipeSearch class (using the RecipeBook class and the Recipes.json file.
- With Cyriac : created an interface for users to type the ingredients, the diet restriction  and the cooking time in the recipe search. Basically they would need a space on the Recipe page called “Search” or they would have 3 spaces to Type:
- the first for the ingredients (a string where each ingredient is written with a capital letter and separated by a comma, but you can just write it next to the box so they understand, don't worry about converting the strings)
- the second for dietary restrictions (like Vegetarian…) like a thong in capital letters
- the third for the cooking time in minutes (just an int)
Just like for adding recipes, there will be one searchbar in which the user prompt will be of the form : “Vegetarian pasta with…”. (In the end, the search just takes the recipe name in the search bar, but you can sort with tags like "Vegetarian", "Vegan", etc.)

Session 9:
- Worked on the elaboration of a Personal cookbook:
  - With Cyriac: button to save recipes (in Recipes.qml in QML folder)
  - With Sixtine (test3 front): the type of a recipe: std::vector<string> so that the server can introduce the liked recipes per user. 
  - The idea is to code a PersonalRecipes class that includes the User class: it should have an addRecipe function that appends a recipe in dictionary format to a list individualised for each user
  - in the QML button code, it should say that the star-shaped button gets filled with color when clicked on and that the recipe associated to each button gets added to a list stored in the PersonalRecipes class.
  - Also want to implement the personal cookbook popup on the Recipes page

Session 10:
- Left the aesthetics of the button for later: instead of an outlined star/heart that fills with color when clicked on, the button is a LIKE button with typical format.
- onClicked now opens a popup that I called personalCookBook (in PersonalCookBook.qml file).
- The popup should show all of my stored liked recipes. However, the liked recipes need to be stored in the user class (as vectors of recipes) in order for the popup to show each user’s liked recipes. For that, I need my “LIKE” button to open the popup, but also the Personal Cookbook button to open the popup., and when a recipe gets liked, the recipe vector should be stored in the individual user's profile dictionary in the server. Then, when the popup opens, it calls the user'd page and returns the list of liked recipes.

Session 11:
- I helped Sixtine with the functions like_recipe and unlike_recipe in the recipe.h and recipe.cpp, files, which I’m going to use to add or take recipes from the Personal Cookbook.
- The liked_recipes is a vector in the user.h file used to store the recipes in question in the user’s file, in order to individualize the liked recipes.
- In the OnClicked section of the button, I’m going to have to differentiate when I click to add a recipe, and when I click to remove a recipe from the favorites. I have 2 options: either I find a way to unlike when the recipe is already in liked recipes, and then remove it, or I create a second button “UNLIKE” but that’s only for the already liked functions. 
- in main.cpp of the cyriac-recipes branch, I included the user.h file to be able to link the QML with the functions on the front end.

Session 12: 
- Finalized the button: it opens the popup, but I've encountered some bugs with the backend functions and how to use them for the button directly. Cyriac used his own defined functions, so I'm going to try to define my functions inspired by the backend ones.

Session 13:
- Created personalcookbook.h and personalcookbook.cpp files: converts the like_recipe and unlike_recipe functions from the backend to the QML
- modified the PersonalCookbook.qml popup so that it looks just like the searchbar with the recipes that you can like (and unlike if you press the like button again when the recipe is already in the liked functions), and it still opens the "Try it out popup" for each liked recipe.
- After many trials, I still haven't been able to get rid of the bugs, so the personal cookbook popup still doesn't look like how I imagined it.

Overall, this experience was challenging, and although I didn't manage to reach my initial goals, I still learned a lot with the kind help of the other members of the group. Thank you for this opportunity!









