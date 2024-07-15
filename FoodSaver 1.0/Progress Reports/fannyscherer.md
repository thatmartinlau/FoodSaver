Progress Report

Week 1:

During the monday session we spent an hour splitting the group into smaller working groups. I decided to join the frontend group. The rest of the session was spent deciding on the general layout of the app and figuring out how to install Qt Designer. The thursday session along with 4 hours at home were spent struggling to install the software.

Week 2:

Watched and followed many online tutorials to figure out the way Qt designer works. Nothing really worked and we could not figure out how to make a basic buttons work. It was hard because all tutorials were mostly outdated, some buttons or functions don't  exist anymore, so even very basic things didn't really work.

Week 3:

Tried out Qt design studio to see if that would be better but it ended up being just as complex as Qt designer. I played around with the different options and watched tutorials  trying to code along but nothing went through. We are questioning what we should use for the interface as we can't make it work for now and the connection to C++ code still seems very far from where we are.

Week 4:

We moved on to using Figma to make the visual design after finding a tutorial that used this method. Spent the monday session debriefing how we would make the layouts and started working on the design. Spent the thursday session working on the design, and kept working on it over the weekend.


Week 5:

We finalized a basic draft of the Figma design but realized it wouod take too much time before getting to C++ code by using Figma. So we decided to stop where we were with basic layouts of each page of the website. We decided to move away from Figma and simply work with qml and c++, it would give a less developed look to our website but would still look good and be more efficient for us. To make our work more efficiten, we divided the different pages of the website (Market, Fridge, Recipes...) amongst ourselves. I will be in charge of the Sign in and Login pages. During the thursday session I started working on it.

Holidays:

Over the break, I worked on the "Fanny - signin" branch. Martin helped me make a basic qml page for the sign in and log in page. I added in some things to avoid some bugs and to make the page more estetic. I then worked on trying to link buttons to simple c++ logic. After some trial and error, I managed to make a very basic signin logic work but for some reason with the exact same code for the login page,the code did not compile. I worked on the "Fanny - testing" branch to try to code the login page seperatly but still did not manage to make it function, Martin (and chat gpt) tried to look at the bugs but we did not find a solution yet.

Week 6:

During the Monday session we had a whole team meeting during which each person presented what they had accomplished over the break. Although we are still far from done, it was very encouraging to see that everything was coming along. We set our new objectives: linking up everyone's work (front end and back end, and backend and back-back end (server)), and starting work on the telegram bot. 
I started coding the actual logic for the signin page and login page (although the login page still does not compile) and worked with Sixtine to define the final functions that she will be coding in the user class to connect my code to the server for users to be able to register and connect to the website.
During the Thursday session, I started coding a new page, which opens right after a new user signs in to ask them their dietary restrictions, bachelor promotion, gender, telegram username... I finished coding this over the weekend but the logic can not fully be implemented yet as I do not have a way of accessing the username and password of the current user using this page yet. 

Week 7:

During the Monday session, I spoke with Sixtine again to make sure all the function on the user.cpp file that I was using were ok. I then worked on figuring out a way to store a global variable "currentUser" accessible for all front end files to keep track of which user is currently using the website. This still need to be connected  to the server end but it compiles and runs!
During the thursday session I worked on debugging my qml files, I successfully debugged Signin and Login but I am still getting some errors on SigninInfo. I also implemented the logic for initializing and updating dietary restrictions.

Week 8:

During the Monday session I worked on debugging the SigninInformation.qml page  but it still emits errors during the execution, however it compiles so hopefully 
it won't cause too many issues when joined to other pages.

Final 2 weeks:

Once I had finished implementing everything we started the merging process. I had several issues leading me to lose my code and rewrite the newer bits of it or copy and pasting it but in the end I got all my code to main. I added some logic to the Profile page.

Martin got very sick so I took over the coordination of everything for the presentation.
