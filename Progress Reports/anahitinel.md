Progress report 1:
1. Identifying Items with Pictures:


    Research: Explored different ways to teach the app to recognize items in photos, like how our brains learn to identify things.
    Next Steps: Planning to use a smart technology called a "Convolutional Neural Network" to help the app learn what items look like by showing it lots of pictures. Although this seems quite complicated to implement at our level, we will keep it as a "bonus" and work on other things for now.

2. Barcode Scanning Capability:

    Research: Explored different tools that can help the app read barcodes from pictures or numbers.
    Next Steps: Thinking of using a specific barcode scanning "API" (kind of like a barcode reader) to allow the app to understand what products are by scanning their barcodes.
   We are thinking of using the following websites connected to the API:
   - API: https://app.pdf.co/
   - Converts image of barcode and outputs a .txt with the numerical barcode: https://products.groupdocs.app/parser/image
   - Input numercial barcode, output product name, description: https://www.barcodelookup.com/


3. Highlighting Expiring Items:

    Research: Looked into how to tell the app to recognize which items are getting close to their expiration dates and show this with colors. We've decided to implement certain classes which will determine it's conservation period (like dairy, fruits...etc). 
    Next Steps: Planning to to compare dates and make items change colors (from green to red) when they are closer to expiring.

4. Notifying Users about Expiring Items Exchange:

    Research: Notify people when their items are about to expire and offer them to others who might want them.
    Next Steps: Considering using a system where users can list what they want and get notified when those items are about to expire in someone else's fridge. Then, if the owner agrees, they can exchange these items.

5. Recipe Ideas from Fridge Ingredients:

    Research: Checked out ways to suggest recipes based on what ingredients people have in their fridges.
    Next Steps: Considering building a feature that suggests recipes using available ingredients, like a friend who suggests meals with what's in your fridge. Detect amount of items and match to best fitting recipe.

6. Sharing Fridges and Comments (Social Feature):

    Research: Explored how people could share their fridge pictures and chat about them, creating a kind of community.
    Next Steps: Thinking of creating a place where users can share fridge photos and have discussions about them, sort of like a fridge insta :)

Future Plans:

    Integration: Integrate the researched tools and APIs into the app's existing structure.
    Testing: Test these features thoroughly to make sure they work smoothly and without issues.



Progress report 2:
we attempted to go forward with the barcode scanner and research on API applications. Unfortunately my pc was unable to install various libraries, and we found that we were not well prepared to work on the barcode scanning feature yet. Over the course of the week, we turned to the actual structure of the code:
We will implement a recipe finding algorithm. The user will input the ingredients in their fridge that they wish to use, and the algorithm will match them with recipes from the bachelor. This will be directly coded on c++.

Progress report 3:
Started writing the reciped matching code. I implemented the "countdown" function for the ingredients class (meant to count down till the expiration date comparing expiry_date with the local time), the recipe matcher which given and ingredient will print the recipes that require this ingredient. Also started working on the base classes for fridge, recipe and ingredients. Next session I'll work on bettering the "recipe matching" function to include multiple ingredients and quantities / preferences. Also plan to discuss with the webpage team to check out the design of our website :)
