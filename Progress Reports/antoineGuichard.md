Hello everyone, 

Good to see you there, I gonna detailled what I work on at each session. 

##1st session: Thursday 30th November from 8 to 11

I am in the design/User Interface team. What we need to do this is Web Assembly, Qt Designer. 
Right now, I am trying my best to download everything, and make everything work. 
Downloading Xcode rn. 

##2nd session: Monday 4th December from 1 to 3

I continue trying to download Qt creator, Qt design Studio and all the requierements to make it work and run. 
With the awefull WiFi it was really complicated

##3rd session: Thursday 7th December from 8 to 10

At home, I managed to download everything, so this morning I was able to get starting discovering the apps. 
First quest: in parrallel with Martin, find how to link a button to launch a function written in a cpp file. 
I find a path for solutions. It's the connections view where we can link user behavior to function calls. 

##4th session; Thursday 14th December from 8 to 10

So this monring, I wanted to create new files (hpp and cpp) to make the first classes and make the buttons connect to functions some people have coded. 
With the teacher, I created a new branch with a new project cause the first version were not so advanced anyways. but basically, what I created doesn't contains the QML files I wanted, so it was quite useless, still it took me 1h30. I restore Cyriac version, all this to realize my QT creator tthink i don't have Webassembly anymore. So I'll first fix this issue...

##5th session Monday 18th
Figma

##6th session Thursday 19th
We finally have something to work on!! To be fair i completely lost all hopes at this point but I go with the flow. 
We attributed tasks to everyone to what they have to do over the break. I took Fridge.
I try to make sure to have something to code in cpp... we will see
Finally managed to make the pop up to 'add to fridge' an item

##7th session xmas sess sheesh the 26 of dec
I manage to amke the whole interface of my page, the one we planed on figma. So it looks a bit funny. 
I also manage to make two of the most challenging elements of my part. 
First is the add to fridge. When you click add to fridge you input the info asked and when you validate it is added to your fridge and therefore it appears on the page. 
Second is that when there are too many items, a scroll appreas so that you can scroll through the items in your fridge. 
I'm very happy with that I was able to produce, we really have a nice base to work on also I think the rest of the page can be derived from this first page. 

Next thing to do is to make the filtering of the ingredient, find how to remove smth from the fridge and from that on it would be really really nice. 

##8th session: 
I continued working on the QML fridge page. I figured out all the stuff from the listModel, the way to have scroll over the ingredient of the fridge. And now you can also remove them from your fridge. I started to darft (with code) the selling part i.e. how to make a product of your fridge into an offer. 

##9th first session back on campus: 
We all discussed together, the main focus now should be to connect the cpp functions to qml and that's a big cpp and hpp part. It is actually my contributions to this project in cpp (the focus of this class). But in order to do so I need to make some last change to my Fridge QML part. 

##10th session (TD 11th of Jan):
Modified the fridge and created in the fridge two tabs: the one My Fridge and the one My Offers. You add element to your fridge and then you can put them on sale when in your fridge and then they will appear on the offers tab and you can manage them over there. That being done (with the creation of new pop-up and remove offer individually from the product if your fridge and being able to modify the chratacteristic of a product and all) I started to try to connect cpp and QML, was unsucessful, better luck next time hopefully. 

##11th session (TD of 18th of jan & full day on):

After HOURSS - I mean it - of struggle and with the help of Martin, I finally managed to make the first porgress in connecting qml and cpp. i actually requiered me writing a lot of cpp (did not expected it) but i guess it's nice for my grade cause I'm finaly writing in cpp (the focus of this class let us remind here). Today I manage that when a ingredient is added to your fridge (with the pop up window I coded earlier). 

##12th session (TD of 22th of Jan): 
What I did today consists of a lot of small changes: repairing the scroll over the product in your fridge and make it looks good. Modifying the repeater of the ingredient to make it looks better and indicate when the product is on sell or not, the price etc. 

##13th session (26th of jan):

for the fridge by date completed by getting inspired of what cyriac did and using the functions of the sixtine, i coded in fridgemanager.cpp the needed functions to convert the objects, int and strings from QObejct to std (standard) object, like for the date with the date class and the Food_class. 

order fridge by category: show the element that has the category selected or not 


##13th session (27th of jan):
search bar: different logic that the one of Cyriac, I send to cpp the request, then it goes through every name of item in the fridge vector, if the sequence of letters (can be in the middle .i.e "il" for "milk") is in the name of the ingredient it is added to the list of visible item if not the item would be hidden. 

##14th session (28/9th of jan):
Work on the aethetic of the application, I coded the button with small icons and deploy it on the whole app (the page of Recipes and Market and login page). There is also some more subtiles changes (would need to go to every commit to see one and one lines changed) they all added up to a significant amount to be mentionned and they contribute greatly to the overall user experience. 

In sight of the demo there is the "demo fridge" button that automatically add 4 ingredients (presetted) to the fride cause adding ingredient one by one is time conssuming

I'll try later to make a list of what work only in qml, in both or just in cpp and therefore what functionnality are not compatible together cause some breaks what others do. 
