**Disclaimer**
FoodSaver 1.0 is now an obsolete project and will be completely reworked in FoodSaver 2.0.

----

<h1>FoodSaver</h1>
<p>A CSE201 project - Saving food, one fridge at a time!</p>

<h2>
Introduction:
</h2>
FoodSaver was designed as an app and a server that is meant to connect from one another. The development of the project has been undertaken through several subprojects:
<li><b>App project</b>: This is where the frontend of the project is developed. This includes UI design, as well as connection to logic and functions between the UI and C++.</li>
<li><b>Backend project</b>: This is where the main classes are defined, and serves as a link between the frontend and the server connection. Note: the project folder for this code is contained in the folder <code>test3</code></li>
<li><b>Server project</b>: This is where the server code is developed, as well as database processing functions.</li>
<li><b>Telegram bot project</b>: This project is developed in tandem with the server and sends reminders whenever food items are about to expire.</li>

<p>For your evaluation of our work, we invite you to check each of these projects to get a good picture of the overall spread of our work.</p>
<p>Finally, we would like to preface this with the fact that each module/subproject works independently of the others, but are not linked together due to unforseen issues between compatibility between Cmake and Qmake.</p>

<h2>I. Running the server</h2>
Two step process to run the server:
Firstly, go to server/POCOSocket/Server/CMakeLists.txt, which you should open as: Open Project in QT, under File tab. Then, simply click run. Green arrow.
If you want to test out the clientside, if it were the case that app-release did not function,
then:
<ol>
<li>With a new qt window, head into <code>server/POCOSocket/Server/web-teste/CMakeLists.txt</code> , to open the client-side server section.</li>
<li>Run the server from the above instruction.</li>
<li>Run the client afterwards, after the server is built and you see "running" hopefully in the QT Console for the server project.</li>
<li>You should see testing results in both consoles, after the rpc_client_side.cpp file runs.</li>
</ol>

<h2>II. Running the app</h2>

<p>Currently, we have two project versions in which we are working on the app:</p>

<li>"app-build" (located in <code>/app/app-build</code>), built using the Qt project framework.</li>
<li>"app-release" (located in <code>/app/app-release</code>), a version of app-build using Cmake.</li> <br>

<p>
"app-release" is still under construction, as the app team is not yet experienced with Cmake, while it is needed by the server team in order to connect the two together.
<br> The compilation for "app-release" is broken as we have not had enough time to merge the two separate parts together. 
<br> As "app-release" fails to compile (errors linked to CMake), we invite you to open the "app-build" project which is a stable version of the app, but is not linked to the server and backend subprojects. To do so, open the following project file on Qt Creator: <code>/app/app-build/app-build.pro</code>
</p>

<h3>
1. Signin
</h3>
<p>The Signin page is designed for new users to create an account. They can input their username and create a password. Errors are generated if the username is already used, the password is less than 8 characters long or the password doesn't match the password check. The user can click on 'Already have an account' to access the Login page. Once the user signs in, a new page opens for the user to initiate their information.</p>

<h3>2. Login </h3>

   The Login page enables already existing users to connect to their account. It            generates errors if the username is inexistant or the password is not correct.

<h3>3. Fridge</h3>

<p>The Fridge page allows you to visualize the content of your fridge. Its intended mechanism is to store all the items you purchase in real life (IRL) along with their expiration dates. To add a product, use the "Add a Product" button on the left. In the popup, make sure to fill in all the information. The date format should be dd/mm/yyyy (enter it as follows: 03/02/2024), and the quantity should be an integer. The "Demo Fridge" button adds four preset products.
<br>
   
The three actions on an item work in QML locally. When you put an item up for sale, it appears in the "My Offers" tab, where you can fully manage it in QML locally. You can search in your fridge with the search bar, by category with the menu, and order the ingredients by time left (the first to spoil first). Note that using the search bar and ordering by time both remove all your offers made locally. When you leave the page and go back to it, in the manner mentioned, the offers are reset, and the products are ordered by time left automatically.</p>

<h3>4. Market</h3>

The Market Place page displays a general view of what the database will show for anyone that wants to look at all the offers that every user has registered. It is the main link to identify which items are on sale with the basic information such as category, time left for expiration and of course, the price. Once a user is interested in buying an item, they may click on the "Add to Basket" button corresponding to each item, which will open the "My Basket" popup containing the product that is now currently in the basket. Here, the information of the item is also displayed as well as a "Contact to Buy" button, which works as a link to a chat with the Telegram user that has put out the item for sale. Currently, this link shows the Telegram Bot's chat for demo purposes, however, it is not intended to particularly initiate a conversation with or through the bot, but with the user who is selling the product.

It is important to remark that currently, the Market page shows a manually introduced database, since the main idea is to try out the features coded in order for them to work out visually and properly. The project itself requires a database that should be updated when every user is online and keeps adding items to their personal offers. Connecting this functionalities through a server will ensure an updated database and also, full functionality when adding items to the basket. Both the Market and the Basket pages currently display manual information with the purpose of demonstrating its capabilities through the "demo" itself.


<h3>5. Recipes</h3>
<p>The Recipes page allows students to share their recipes. One can add a new recipe by pressing the "Add A Recipe" button. This then opens a popup which should be filled. In order to submit the ingrdients and instuctions, one must clik the "+" buttton or enter key. All fields are mandatory except fo the time. The title of a recipe must be new, else a message will popup. Recipes can be visualized by clicking the "try it out button".

Once a recipe has been published anyone can rate it (scale of 0-5) which will add on to an average of all ratings. 

One can search for a recipe in the searchbar. The results are only given once a full word has been entered by the user and the results keep updating as the searchbar input is updated. The results are ordered by most relevant, comparing both titles and ingredients of the available recipes with the user search input.

The reset button resets the recipe page to all the available recipes, reseting all sorting or searches input.

<h3>6. Settings and profile</h3>
<p>The settings page and profile pages are popups that open when a button is clicked on any of the Market, Recipes or Fridge pages. Their function is to allow the user to change their personal information, and then save this information to that it can be updated on the server.</p>

<h2>III. Backend code</h2>
<p>Should you wish to pay interest to the backend code connecting the server and the app interface, you may open the project file on a new Qt window at the following directory: <code>/test3/CMakeLists.txt</code></p>
<p>This project contains the code defining the important classes and functions used by both the server side and app side.</p>


<h2>IV. Photo recognition and Telegram bot</h2>
Please check <code>server/CNN/README.txt</code> and <code>telegram-bot/telegram-bot/README.md</code> for instructions.
