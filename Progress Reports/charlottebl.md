Weekly Progress Charlotte Begon-Lours
  
Session 1 : 27/11 
We split the roles of everyone in the group. I’ll start by working on the server part with Oscar, Adam, Sixtine and Esma. This session is more an introduction, what do we specifically need to do? How ? During this first session, I looked at Poco's library and learnt more on how to use it. 

Sources: https://pocoproject.org, https://github.com/himynameschris/socket.io-poco/blob/master/README.mdown

Session 2 : 30/11
I was moved to the “ambitious” group. This part focuses on enhancing the FoodSaver app with more features. I am now collaborating with Elizabeth and Anahi. We brainstormed our ideas, what we would like the application to do. 

Our first ideas are : 
- Image/Barcode Recognition: This feature aims to streamline the process of identifying ingredients by allowing users to either capture a picture or scan the barcode on a product's packaging to retrieve comprehensive information.
- Recipe Generator: We envision a dynamic recipe generator that suggests recipes based on the ingredients in a user's fridge that are nearing expiration. Users can filter the selection based on available ingredients, specific dietary preferences (vegetarian, vegan, gluten-free), and time constraints. Additionally, users should have the option to add and store their own recipes in a personalized cookbook.
- Food Marketplace: Introducing a marketplace where users can either sell or give away food items that are approaching their expiration dates.

To efficiently manage these tasks, we have divided responsibilities. Elizabeth and Anahi will be spearheading the barcode functionality, while I will take charge of developing the recipe generator. 

In the latter part of our session, I delved into how we could implement the recipe generator's functionality. Ideally, the goal is for the app to offer recipes that are low-carbon and low-waste. Through my research, it became evident that utilizing an API to source the necessary data, specifically recipes, is a commonly recommended approach.
=> “An API, or application programming interface, is a set of defined rules that enable different applications to communicate with each other. It acts as an intermediary layer that processes data transfers between systems.“
https://www.ibm.com/topics/api

//inspiration : https://github.com/Hannahli6/Zero-Waste-Recipe-App/tree/main, https://devpost.com/software/zero-waste-recipes
>> focuses on the same goals as our FoodSaver app.

Session 3 : 4/12
Following on from the implementation of a food recipe generator and after extensive research, I have a better understanding of how to use the Spoonacular API or Epicurious.( List of the top 10 best recipe APIs : https://rapidapi.com/blog/recipe-apis/ ) 

I'm trying to figure out a way to code and implement this functionality using the Spoonacular API, which is the most popular API.
API links : https://rapidapi.com/search/food%20recipe
- Edanam: https://developer.edamam.com/edamam-recipe-api
- Spoonacular: https://spoonacular.com/food-api
- Tesco recipe finder: https://realfood.tesco.com/what-can-i-make-with.htm
- Dishgen: https://www.dishgen.com/``

Following on from the implementation of a food recipe generator and after extensive research, I have a better understanding of how to use the Spoonacular API or Epicurious. However, I've realized that most of the code to implement this functionality is provided using a configuration for Tailwind CSS in JavaScript using CommonJS syntax.  C++ is not generally used to configure web development tools such as Tailwind CSS. Therefore, I’m looking for another option or try to translate the code into C++ which is not ideal for configuring web development tools.


Session 4 : 7/12

Link used during this session : https://www.youtube.com/watch?v=Ee-2iqMmbaE , https://www.youtube.com/watch?v=Z3hihUtihDk , https://www.youtube.com/results?search_query=recipe+generator+in+c%2B%2B , dm-valdez/food-finder: Search for the recipes of thousands of dishes with the Edamam API.  

Instead of seeking an API for a food generator, I've chosen to initiate the process by compiling a file containing numerous recipes. The goal is to curate recipes that are not only quick and easy to prepare but also contribute to minimal waste and low carbon emissions. These selected recipes will be consolidated into a single file. This file will serve as a basis for generating a list of recipes based on the available ingredients in the refrigerator and their priority for consumption. This can easily be realizable using C++.
Currently deliberating on the file format, I am leaning towards utilizing .CSV files. CSV, being a plain-text format, consists of easily readable characters. In this format, each line signifies a distinct recipe, and the fields within each line are separated by commas, serving as delimiters. This simplicity makes it easy to organize information, and the proposed structure for each line in the file is as follows: Title, Ingredients, Instructions, Diets, Time.


Session 5 : 11/12
Exploring ways to enhance the organization of our recipe file, aiming to optimize code structure and simplify access. During brainstorming sessions, we focused on key considerations for users seeking recipes: determining priority order, deciding on the quantity of displayed recipes, and identifying sources for recipe content. Collaborating with Elisabeth, we reached the conclusion to utilize a .JSON file for categorizing recipes into various groups based on criteria such as dietary preferences (vegetarian, vegan, fish, meat, gluten-free), flavor profiles (sweet or savory), and time requirements. I never used this type of file but according to her .JSON files have a very nice format in order to store information.


Session 6 : 14/12
First steps of coding the parsing of a .JSON file in C++.
Initially, my objective is to devise a method for generating a Json file encompassing all the recipes. The approach involves either locating a pre-existing Json file containing recipes and formulating a function to tailor the file based on our criteria, or constructing one from scratch.

Link of online recipe websites : https://www.tastebeforeyouwaste.org/post/student-low-waste-recipes-quick-easy-cheap , https://www.edamam.com (come back to APIs…), ​​RecipeNLG, 
https://www.kaggle.com/datasets/kaggle/recipe-ingredients-dataset
https://www.reddit.com/r/datasets/comments/9wwv1m/looking_for_a_dataset_about_recipes_ingredient/ 
https://www.youtube.com/results?search_query=access+data+stored+in+Json 

Session 7: 18/12 
Spend the class looking for information, recipes data sets, json files 

Links opened during the session : 
https://www.reddit.com/r/datasets/comments/9wwv1m/looking_for_a_dataset_about_recipes_ingredient/ 
https://github.com/ianprime0509/jsonrecipe-schema/blob/master/README.md 
https://esha.com/resources/additional-databases/ 
https://codereview.stackexchange.com/questions/201617/using-python-to-create-a-json-file-of-recipes-from-mysql 
https://opendata.stackexchange.com/questions/20982/free-downloadable-recipes-database 
https://github.com/dpapathanasiou/recipes/issues 

Session 8: 21/12
During my research, I came across a project on GitHub authored by @dpapathanasiou, accessible at https://github.com/dpapathanasiou/recipebook/blob/master/README.md . This Python application is designed for scraping and parsing food recipe data from the web in hRecipe format, eventually presenting the results in Json. The hRecipe format is a microformat for encoding structured recipe data, facilitating easier data access (http://microformats.org/wiki/hrecipe). The recipes obtained through the web crawler are stored in a parallel repository (refer to README.md for more details). Inspired by this, I aimed to replicate the methodology in C++.

Christmass Break : 
While implementing the C++ functions to generate the Json file with all the recipes, I encountered challenges beyond our current capabilities. This is attributed to the need for installing libraries that I lack, coupled with difficulties in comprehending certain aspects of the code. Considering the time investment required to overcome these challenges, I decided it would be more efficient to create the file from scratch.
However, in the GitHub repository named "recipes" (https://github.com/dpapathanasiou/recipes/tree/master/index), recipes are already available in Json format, organized alphabetically by the first letter of their title. As a workaround, I opted to copy and paste some recipes directly from this repository, and modify their original format.

{
    "directions": [
        "Some directions .... "
    ],
    "ingredients": [
        "Some ingredients..."
    ],
    "language": "en-US",
    "source": "allrecipes.com",
    "tags": [],
    "title": "Vegan Pancakes",
    "url": "http://allrecipes.com/recipe/228413/a-vegan-pancakes/"
}

This aligns with the desired format we aim to adopt. The instructions and ingredients are stored as vector<string>, while other fields are represented as strings, optimizing the parsing process for each recipe. However, for our project, we seek enhanced filters to streamline JSON file parsing, making recipe generation more efficient and aligning with user criteria. Consequently, I've introduced additional tags for each recipe, encompassing ingredients, diets, recipe types, and removed the language field, deemed unnecessary for our context. The template of our JSON file, which spans 6000 lines, is as follows:

{
    "RecipeBook": [
        {
            "title": "Cherry Poke Cake",
            "directions": [
               "some directions ..." 
                ],
            "ingredients": [
                "Some ingredients ..."
                ],
            "source": "allrecipes.com",
            "tags": ["Sweet", "Chocolate", "Cake", "Poke", "Cherry", "Gluten-Free","Pan"],
            "url": "http://allrecipes.com/recipe/235063/1-2-3-cherry-poke-cake/"
        },
        {
            "title": "1-Dish Chicken Parmesan",
            "directions": [
               "some directions ..." 
                ],
            "ingredients": [
                "Some ingredients ..."
                ],
            "source": "allrecipes.com",
            "tags": ["Chicken","Parmesan","Salty", "Lunch", "Dinner","Spaghetti", "Cheese", "Herb", "Flour", "Oven"],
            "url": "http://allrecipes.com/recipe/173295/1-dish-chicken-parmesan/"
        },
…]
}

The JSON file is prepared for use, and I've developed the JsonRecipeReader class to facilitate access to its elements. To interact with JSON files, it's essential to install the nholman library, a C++ library specifically designed for parsing JSON files in a modern environment.
The JsonRecipeReader contains by default the .json file with all the recipes and for each methods, the user need to precise an index that corresponds to the ith recipe of the json file. 
I put the header RecipeBook.hpp and RecipeBook.cpp in the front branch, in the file test3. 

Session 9: 08/01

