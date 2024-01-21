REPORT

Session 1:
This week we figured out the formats for the database (server team and frontend) and csv structure.
We split the work and decided that William and I would be working on the database and Adam and Oscar on integrating POCO.
We decided to have a basic server running until the end of the week, however we later figured out that using POCO would not be ideal,
which is why we tried experimenting with rpc and websocket and tried to learn the syntax.

Session 2:
We had a bit of trouble since apparently there was a misunderstanding while assigning the work. William thought of just hashing the data 
in order to make the database which is a pretty straightforward and easy task, and hence would not be a two person job. This is why two of us thought
that making the basic server running was our task and we started doing that. However, Oscar and Adam thought this was their job (along with figuring out POCO, an idea
which we later abandoned) so we had two teams working on the same thing and hence our code was pretty much redundant (I believe Adam was the fastest in finishing and posting this part so we built on his and Williams code)
While doing this, we finally managed to integrate rpclib.

Session 3:
We started writing the database but in the end we decided to change it because we found a better way to do it. Namely, we had issues with the frontends ideas and our own 
initial predictions so we obviously had to cater to their requests. This included choosing the right formats for data like fridge, offer lists and database in general.
We agreed on which function to implement, which is my part to code.
To sum up, we finalised the server structure and efficiently split the work. 

Session 4: 
I wrote the functions we agreed on last week, I havent optimised them yet but only wrote them so they work, although I made sure to at least check if the users and passwords are
valid before actually completing the task.

Session 5:
This week I optimized the functions I wrote last week. Namely, with professor's suggestion, I passed all vector variables as references so it would be faster.
I also used functions such as "move" in order to reduce unnecessary data copying and improve performance ( apparently it is especially good to do
with complex and large data structures like nested vectors).
I also added some lines to clean the memory (suggested by my TA since he wasn't sure if c++ has garbage collectors or something along these lines)
and release it later to further improve the performance. 

Session 6:
For this session I made a function for Diana which returns all offers and their users. For this function it was important to ensure the file inclusion wont be looping. In other words, since I used server.cpp and client hpp and cpp file to make it, and these files include some backend files as well, we wouldn't want to have a situation where she might include a file which is already including her own in the first place. We also figured out that the offers are no longer going to be made up of different packages of ingrediants but instead ingrediants sold seperately (which I initially suggested in the beggining of the project anyways), so I had to change some offer formats as well. 

Session 7:
In fixing the rpc bug, we had to change formats of the inputs/outputs for functions which include more complex structures than <vector<string>>. We did that by making functions that serialize and deserialize our data. To sum up, these functions take/return the complex format and put the data in the correct one so it can be transfered by rpc and since there are several different types of the complex structures such as <vector<vector<vector<string>>>> or unordered maps, they all needed a specific function. However I did not have to write everything from scratch since some of them could call upon the others after being reduced to the right format. 

