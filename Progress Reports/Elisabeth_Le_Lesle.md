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

Session 2: Lots of research done on the different recipe generating websites, like Tesco recipe finder, SuperCook or Dishgen, as well as on the different API options for barcode scanning of ingredients.

Session 3: 
Continued research on the barcode scan, through Youtube tutorials, github projects on a similar topic. The softwares needed still don’t work (XCode, Command Line Tools, Homebrew, OpenCV). I managed to add the PDF.Co API, which supposedly reads 1D and 2D Barcodes, but on QT Creator, I did not know how to use the code sample. 


Session 4:
After a talk witht the professor in lecture and more research on the topic, the API implementation of a barcode scan and a recipe generator was sadly abandoned. With the implementations team, we discussed the possibility of creating our own Recipe Class from scratch, and create its very own database. We were thinking of a JSON file format for easy access.

Session 5:

Continued research on the Recipe Class and its different functions: 
Recipe class functions:
initialization function: ingredients in user’s fridge, their quantity and expiration date, key ingredient, diet (vegan…), recipe time interval:
for ingredients the user already possesses, import them from the Fridge class
for other ingredients contained in the recipes: import Ingredient Class
open the file in dictionary format (JSON file), that contains the recipe number, its name as string, diet restriction as string, time to cook as int, ingredient list, instructions string, recipe picture URL as a string 
for now, define a simple empty list matching_recipes to which we append all recipes with the given ingredients
then there should be a sorting for maximum optimization: the user should be able to choose whether or not he prioritizes to use the ingredient witht the closest expiration date (there already exists a Priority function in the Ingredient class, which we will use), or if if wishes to use an ingredient of his choice
should return recipe ideas (with pictures?) in order of relevance (most fridge and recipe ingredients in common)
ideally, we would want to implement another function that would allow bachelors to add their very own recipes to the data base. However, out of simplicity (and to spare us the difficulty of converting the recipes to JSON format), the website would have spaces to write each recipe characteristic in the format we want (error if not the same format e.g. lowercase, int, list of ingredients separated by commas and no spaces, upload a picture of the recipe and extract its URL?

