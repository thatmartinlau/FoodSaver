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

