import torch
import torchvision.models as models
import torchvision.transforms as transforms
from PIL import Image
import matplotlib.pyplot as plt
import numpy as np

fruit = ["Apple Braeburn", "Apple Crimson Snow", "Apple Golden 1", "Apple Golden 2", "Apple Golden 3", "Apple Granny Smith", 
"Apple Pink Lady", "Apple Red 1", "Apple Red 2", "Apple Red 3", "Apple Red Delicious", "Apple Red Yellow 1", "Apple Red Yellow 2", 
"Apricot", "Avocado", "Avocado ripe", "Banana", "Banana Lady Finger", "Banana Red", "Beetroot", "Blueberry", "Cactus fruit", 
"Cantaloupe 1", "Cantaloupe 2", "Carambula", "Cauliflower", "Cherry 1", "Cherry 2", "Cherry Rainier", "Cherry Wax Black", 
"Cherry Wax Red", "Cherry Wax Yellow", "Chestnut", "Clementine", "Cocos", "Corn", "Corn Husk", "Cucumber Ripe", "Cucumber Ripe 2", 
"Dates", "Eggplant", "Fig", "Ginger Root", "Granadilla", "Grape Blue", "Grape Pink", "Grape White", "Grape White 2", "Grape White 3", 
"Grape White 4", "Grapefruit Pink", "Grapefruit White", "Guava", "Hazelnut", "Huckleberry", "Kaki", "Kiwi", "Kohlrabi", "Kumquats", 
"Lemon", "Lemon Meyer", "Limes", "Lychee", "Mandarine", "Mango", "Mango Red", "Mangostan", "Maracuja", "Melon Piel de Sapo", 
"Mulberry", "Nectarine", "Nectarine Flat", "Nut Forest", "Nut Pecan", "Onion Red", "Onion Red Peeled", "Onion White", "Orange", 
"Papaya", "Passion Fruit", "Peach", "Peach 2", "Peach Flat", "Pear", "Pear 2", "Pear Abate", "Pear Forelle", "Pear Kaiser", 
"Pear Monster", "Pear Red", "Pear Stone", "Pear Williams", "Pepino", "Pepper Green", "Pepper Orange", "Pepper Red", "Pepper Yellow", 
"Physalis", "Physalis with Husk", "Pineapple", "Pineapple Mini", "Pitahaya Red", "Plum", "Plum 2", "Plum 3", "Pomegranate", 
"Pomelo Sweetie", "Potato Red", "Potato Red Washed", "Potato Sweet", "Potato White", "Quince", "Rambutan", "Raspberry", "Redcurrant", 
"Salak", "Strawberry", "Strawberry Wedge", "Tamarillo", "Tangelo", "Tomato 1", "Tomato 2", "Tomato 3", "Tomato 4", "Tomato Cherry Red", 
"Tomato Heart", "Tomato Maroon", "Tomato Yellow", "Tomato not Ripened", "Walnut", "Watermelon"]

# Set device
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# Load the pre-trained model
model = models.resnet18(pretrained=True)
num_ftrs = model.fc.in_features
num_classes = 131  # Replace with the number of classes in your dataset
model.fc = torch.nn.Linear(num_ftrs, num_classes)
model.load_state_dict(torch.load('resnet18_fruits360.pth'), map_location=torch.device('cpu'))  # Load your trained model
model = model.to(device)
model.eval()

# Function to process and display an image
def process_and_display_image(image_path):
    # Transform the image
    transform = transforms.Compose([
        transforms.Resize((128, 128)),
        transforms.ToTensor(),
        transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])
    ])

    # Load and transform the image
    image = Image.open(image_path).convert('RGB')
    image_tensor = transform(image).unsqueeze(0).to(device)

    # Predict the class
    with torch.no_grad():
        outputs = model(image_tensor)
        _, predicted = torch.max(outputs, 1)
        predicted_class = predicted.item()

    # Display the image and prediction
    imshow(image_tensor.cpu().squeeze(), title=f'Predicted class: {fruit[predicted_class]}')

def imshow(inp, title=None):
    """Imshow for Tensor."""
    inp = inp.numpy().transpose((1, 2, 0))
    mean = np.array([0.485, 0.456, 0.406])
    std = np.array([0.229, 0.224, 0.225])
    inp = std * inp + mean
    inp = np.clip(inp, 0, 1)
    plt.imshow(inp)
    if title is not None:
        plt.title(title)
    plt.show()

# Test, change 'test1.jpg' to your path to image
process_and_display_image('test.jpg')

