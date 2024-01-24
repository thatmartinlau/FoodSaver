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



