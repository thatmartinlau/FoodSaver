Week 1: Nothing whatsoever!

Week 2:
I am Team Leader for the backend-server section of the project, Sixtine runs the backend-frontend connection. Martin runs the full frontend code, with QML.
Figured out the team structure more or less, will be coding with Pocco - figuring out user -> server data sending and receiving, with Oscar. Updates to 
come later this week. Will see, it is only Monday after all. Anything can change, like the sky and sun and clouds above :)

Week 3:
Had a decision to make between coding using rpclib, or pocosocket, using websocket. Xiaxi made a small fuss about it, recommending we do both at the same time.
Made the teams sane and fair again, by acting as veto power to make sure we had one project going on at once, not two. Moved the teams around:
Now, Oscar, Esma, and William are now in the project for back-server work, with the database and all. Oscar is working on client-side data connection, while Esma and I are working
on making sure that files and data types can be received and database-stored on a backend server, to be hosted by Xiaxi later on,.
Aside from that, we have cleared up our file folder structure on Github. We will be running off the server branch for now.
Adios, see you next week!

Week 4:
We've (I've) gotten the team around: we'll all work on the server, and Oscar works on the backend-server, clientside, data type conversions. Leadership, am I right?


Week 5: (I think it was week 5 we did our first big step in organisation. Between week 5 and week 6, we wrote our first Bible).
I hope you're not religious. We wrote a data type bible, for storing all data types in our server, in a database, and back out to a unordered_map to make it dynamically useful again. 
It was a complicated first couple weeks, with no clearest-directive as to what was going on, type-wise, storage-wise. All were winging it, not helped by (sorry, again) a certain someone's
ridiculous interventions at each occasion he could intervene. So, I took control of my group again, got Esma in the second TD slot, asked her about her progress. We found out how much of a mess 
it was, together. Then, we decided to innovate: useing paper, we wrote a short summary from backend's classes, of all the types ever used, and every conversion we'd need, and every function we'd code.
Following this, we found William (who was in the other building, we wade through the cold to get there), discussed it with him, found a couple errors, modified it, and moved on with our lives.


Week 6:
After beginning to use the Bible, everything became clearer. We are non-religious. I swear. And so we went forwards, non-stop coding, aend in one week coded the entire project. Our part, at least.
On my own side, I wrote the functions read/save_to_csv, which actually bring data/to/from the disk .csv files, so when we want to close the server, we don't lose all our data. Stored meticulously, it all 
worked fantastically. Though, there was a slight problem, we had a lot of banned characters. Vague ones, like [] {} ||, and others too. More code to be rewritten later to avoid this issue.

Week 7:
Oh wondor, another massive change! Having gotten near-to-the-end, of this hellish re-coding sprint, User class gets changed, by Sixtine, with very legitimate reasons. So, we have to adapt. And adaptation meant 
rewriting our entire database encoding, our connection-to-clientside functions, from both server-side and client-side files (rcp depends on types used and passed). By type-dependent, I mean to say that
Rpc-lib changes its server-sending functions depending on the type of data it receives. With new types, all our translation functions had to change. So, we began work on that.

Christmas Holidays:
I worked on the code, until deciding I wanted to finish bug-testing it all, from the clients-ide, making sure it all meshed well together, at least on rpc_client_side.cpp. Trying and fixing each bug,
creating a testing-suite, making everything work, until finding a big bug. struct's were needed to pass vector<string> and our hellish  vec<vec<vec<vec<string>>>, so I made a short structure for Oscar to see,
and asked him to do the debugging of this function.

Post-christmas holidays, week 1:
Esma, having not finished debugging, had to be set on the task of repairing her code, writing a new function for Diana, and more. Oscar took over the big bug fix, I struggled a lot with 
him to make him understand the bug in the first place, and moved on with life after making him a testing suite, bare basic,s and asking him to go figure it out himself again. Leadership goals!
Meanwhil,e I recoded my read/write to csv functions, separating them into writing into four files at first, then three at the end of athe day.


Post-christmas, week 2:
I am writing this now, having re-written my storyline for the past six weeks, hoping it's biblically accurate to the Github history of my branch, which is now server(adam) or (adam)server after 
I discovered and initiated fellow team members into the cult of merge-branches with merge-commits. This way, we can all work on the same server-branch, by having different sub-branches with regulr 
merges to server. So, we keep updated, in the loop, while working on our own personal branches too. No mess, cleaner code. Everyone is up to date now, moving into final stages of the project. Today,
I've just finished work on my last read/write to csv functions, it all should be bug-less for now. This coming week is debug week. Make everything work, all together now. Bye for now! See you again, in six weeks:)

Week 3 Post-Apocalypse:
Fixed (I refactored) the server subproject, to include all necessary connections to test3's branch and folders. Fixed that up, then went to finish my read/write functions for database files. Decided to separate into 4 files,
rewrote the entire reading/writing to fit with this. (or rather, finished rewriting, had started Week 1 post-christmas.
Now, all that's left is to clean up some minor details in my work, rewrite some cmake files.
Later in the week: Now Monday, still counting it as last week's work. Either way,
had to re-convert Sixtine''s test3 folder into CMake from qMake, debugged that, got it sorted well. Now, our connections are cleaned up nicely. We can work on combining with app-side for final project build.
This week is the last!

Week 4: Final week!
