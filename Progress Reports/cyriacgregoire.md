Progress Report#

Week 1 :
- understanding how to set up a new project file (namely test3)
- setting up the front.hpp and front.cpp file. These are the basic constuructors and functions of the classes we will use in the fron-end part of the project

Week 2:
- I had a problem with the WebAssembly part of Qt, it was installing but never running, even though I seemed to have followed the same instructions as everyone else.
- Tried to solve the problem but I kept getting the same error which was difficult to interpret as I was not yet familiar with WebAssembly, Emscripten and how they work
- Finally decided to set up a virtual machine, that runs Ubuntu on my Laptop, which was a time-consuming solution, but it worked in the end!

Week 3:
- Working on a transition between two pages using the Qt Design Studios, trying to understand how the Design Studio interface allows us to transition and connect diffrent "Flowitems". This has proven more difficult than it sounds as not many tutorials are available online. (This is not a very used way to create websites)

Week 4:
- Working on the recepie  page, starting to set up the buttons and different user inputs that are needed for this page.

Holidays:
- Working on the recipe page, setting up the pop-up windows, the different elements of the page, which include design of the buttons and text, a scrollbar, implementing all this in a pop-up, which allows users to publish recipes.
- Working on the searchbar (for recipes) of the page. A first working version was implemented, it only dealt with strings of recipe names, and not yet with actual recipe objects. It did sort the results given, by order of most relevant title and would change for every character typed by the user.

Week 5:
  - Making sure that, the popup for a recipe publication would create (and store in a for now local vector<string>) an object of type recipe, that is, fetching all the input information in the correct order. 
  - Improving the searchbar wiht recipe objects, now the searching algorithm also checks if a recipe may be interesting for what was typed in, if it has a relevant ingredient (exampple someone searches something related to carrots, then recipes that contain carrots will appear) - still in order of most relevant

Week 6:
  - Working on the popup that allows users to read the recipes. Liking this button with the vector of recepies in the cpp file.
  - Start to implement the rating system of the recipes

Week 7:
  - Final additions on the recipe page. The popup which allows users to read the recipes was fiinalized (there was a bug when creating multiple recipes at once).
  - The search bar now also takes the dietary restriction of the recipe in account in order to get more accurate results.
  - The rating system is now functional (one can rate a recipe, which counts towards an avereage grade)
  - A UI update was made, the colors and style was changed in order to be more consistent with the other pages of the project.



