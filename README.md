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

<h2>I. Running the server</h2>
Two step process to run the server:
Firstly, go to server/POCOSocket/Server/CMakeLists.txt, which you should open as: Open Project in QT, under File tab. Then, simply click run. Green arrow.
If you want to test out the clientside, if it were the case that app-release did not function,
then:
1. With a new qt window, head into server/POCOSocket/Server/web-teste/CMakeLists.txt , to open the client-side server section.
2. Run the server from the above instruction.
3. Run the client afterwards, after the server is built and you see "running" hopefully in the QT Console for the server project.
4. You should see testing results in both consoles, after the rpc_client_side.cpp file runs.

<h2>II. Running the app</h2>

<p>Currently, we have two project versions in which we are working on the app:</p>

<li>"app-build" (located in <code>/app/app-build</code>), built using the Qt project framework.</li>
<li>"app-release" (located in <code>/app/app-release</code>), a version of app-build using Cmake.</li> <br>

<p>
"app-release" is still under construction, as the app team is not yet experienced with Cmake, while it is needed by the server team in order to connect the two together.
<br> We invite you to first try to compile "app-release" as it is aimed to be more functional to work alongside the rest of the other sub-projects associated with FoodSaver. To do so, open the following project file on Qt Creator: <code>/app/app-release/CMakeLists.txt</code>
<br> Should "app-release" fail to compile, we invite you to open the "app-build" project which is a stable version of the app, but is not linked to the server and backend subprojects. To do so, open the following project file on Qt Creator: <code>/app/app-build/app-build.pro</code>
</p>

<h3>
1. Signin
</h3>
<p>The Signin page is designed for new users to create an account. They can input their username and create a password. Errors are generated if the username is already used, the password is less than 8 characters long or the password doesn't match the password check. The user can click on 'Already have an account' to access the Login page. Once the user signs in, a new page opens for the user to initiate their information.</p>

<h3>2. Login </h3>

   The Login page enables already existing users to connect to their account. It            generates errors if the username is inexistant or the password is not correct.

<h3>3. Fridge</h3>

<h3>4. Market</h3>

<h3>5. Recipes</h3>

<h3>6. Settings and profile</h3>
<p>The settings page and profile pages are popups that open when a button is clicked on any of the Market, Recipes or Fridge pages. Their function is to allow the user to change their personal information, and then save this information to that it can be updated on the server.</p>

<h2>III. Connecting the server to the app</h2>

<h2>IV. Photo recognition</h2>
