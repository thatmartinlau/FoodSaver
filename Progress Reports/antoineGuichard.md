# Computer Sciences Project Progress Report

## Introduction

Greetings everyone,

I am pleased to share the progress updates on my C++ and QML project. Each session is documented below, highlighting the tasks undertaken and challenges faced.

## 1st Session: Thursday 30th November from 8 to 11

I am an active member of the Design/User Interface team, utilizing Web Assembly and Qt Designer. Currently, I am in the process of downloading the necessary tools and resolving compatibility issues. The download of Xcode is underway.

## 2nd Session: Monday 4th December from 1 to 3

Despite challenging Wi-Fi conditions, I persisted in downloading Qt Creator, Qt Design Studio, and their prerequisites.

## 3rd Session: Thursday 7th December from 8 to 10

Having successfully downloaded the required components at home, I commenced exploring the applications. A collaborative effort with Martin led to discovering how to link a button to a C++ function using the connections view.

## 4th Session: Thursday 14th December from 8 to 10

My attempt to create new HPP and CPP files for initial classes faced setbacks. A new branch was created with the teacher's guidance, but an issue with WebAssembly arose. The restoration of a previous version was necessary, followed by addressing the WebAssembly problem.

## 5th Session: Monday 18th of December - Lec

Focused on Figma.

## 6th Session: Thursday 19th - TD

Tasks were assigned, and despite initial doubts, progress was made. I tackled the Fridge, successfully implementing the "add to fridge" functionality.

## 7th Session (Christmas Break): 26th of December

I completed the interface based on Figma's plan, achieving the desired functionalities, such as adding items to the fridge and implementing scroll functionality for an excess of items.

## 8th Session: 31th of December

Continued working on the QML fridge page, addressing listModel and scroll functionalities. Began drafting code for the selling aspect.

## 9th Session (First session back on campus)

The focus shifted to connecting CPP functions to QML, requiring adjustments to the Fridge QML part.

## 10th Session: Thursday 11th of January - TD

Modified the Fridge with two tabs, "My Fridge" and "My Offers," and attempted to connect CPP and QML.

## 11th Session: Thursday 18th of January & Full day - TD 

After extensive struggles and guidance from Martin, progress was made in connecting QML and CPP, particularly in adding ingredients to the fridge.

## 12th Session: Monday 22th of Jan - Lec

Made small changes to enhance the aesthetics of the application, including improvements to the product scroll and repeater.

## 13th Session: Thursday 26th of January - TD

Implemented functionality for ordering the fridge by date and category. Also, worked on a search bar with a different logic compared to previous implementations.

## 14th Session: 27th/28th of January - TD

Focused on aesthetic improvements, incorporating small icons and subtle changes across various app pages. Introduced a "demo fridge" button for quick ingredient addition.

In preparation for the demo, I plan to evaluate functionalities exclusive to QML, CPP, and those compatible with both.

This summarizes the progress made so far, and I look forward to further advancements in the upcoming sessions.



# Old weekly reports (not formated, not formal, but way more detailed)

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
