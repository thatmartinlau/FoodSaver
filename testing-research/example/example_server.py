from flask import Flask, request, send_from_directory, redirect, send_file, jsonify
from flask_socketio import SocketIO, send, emit

app = Flask(__name__)
app.config['SECRET_KEY'] = 'KEY'
app.config
socketio = SocketIO(app)    
connections = {} #List of all connected clients
user_list = {}  #Simplified user list, contains only username and password
#!!!DO NOT USE USERNAME TO CHECK ANYTHING EXCEPT FOR LOGGING IN WHILE IN PRODUCTION, GENERATE A uid INSTEAD!!!
#SUGGESTIONS: Store encrypted passwords in database, e.g. in database store salt & SHA1(SHA1(password)+salt)
food_list = [] #List of all foods
counter = 1 #Counter for food uid


def print_socket(d): #To print socket logs in green background
    print('\x1b[6;30;42m'+"[WEBSOCKET] "+d+'\x1b[0m')

def print_socket_red(d): #To print socket logs in red background
    print('\x1b[6;30;41m'+"[WEBSOCKET] "+d+'\x1b[0m')

def print_current_connections(): #To print current connections
    print_socket("Current connections:"+str(connections))

#HTTP events
@app.route('/', methods=["GET"])
def testpageindex(): #Serve index.html
    return send_file("include/index.html")


#SocketIO events
@socketio.on("connect")
def handle_connect():
    connections[request.sid] = "*NOT LOGGED IN*"
    print_socket("Connection established, id:"+str(request.sid))
    print_current_connections()
    emit("message", {"data":"Hello from server, your id is:"+str(request.sid)})

@socketio.on("disconnect")
def handle_disconnect():
    connections.pop(request.sid)
    print_socket_red("Connection lost, id:"+str(request.sid))
    print_current_connections()

@socketio.on("register")
def handle_register(data):
    if not (data["username"] and data["password"]):
        emit("alert", {"data":"Please register with a valid json object {username: 'username', password: 'password'}"})
        return
    if data["username"] in user_list:
        emit("alert", {"data":"Username "+str(data["username"])+" already exists"})
        return
    user_list[data["username"]] = data["password"]
    emit("message", {"data":"User "+str(data["username"])+" with password "+str(data["password"])+"registered successfully"})

@socketio.on("login")
def handle_login(data):
    if not (data["username"] and data["password"]):
        emit("alert", {"data":"Please login with a valid json object {username: 'username', password: 'password'}"})
        return
    if data["username"] not in user_list:
        emit("alert", {"data":"Username "+str(data["username"])+" does not exist"})
        return
    if user_list[data["username"]] != data["password"]:
        emit("alert", {"data":"Password incorrect"})
        return
    connections[request.sid] = data["username"]
    emit("message", {"data":"User "+str(data["username"])+" logged in successfully"})
    emit("login", {"username": data["username"]})
    print_socket("User "+str(data["username"])+" logged in successfully")
    print_current_connections()

@socketio.on("add_food")
def handle_add_food(data):
    global counter
    if not (data['name'] and data['bestbefore']):
        emit("alert", {"data":"Please add food with a valid json object {name: 'name', bestbefore: 'YYYY-MM-DD'}"})
        return
    food_list.append({"uid": counter,"owner": connections[request.sid],"name": data['name'], "bestbefore": data['bestbefore']})
    counter = counter + 1
    emit("message", {"data":"Food "+str(data["name"])+" added successfully"})
    print_socket("Food "+str(data["name"])+" added successfully") 
    handle_get_foods(request.sid)

@socketio.on("get_foods")
def handle_get_foods(sid=None):
    if sid:
        emit("update_foods", list(filter(lambda x: x["owner"] == connections[request.sid], food_list)))
        return
    if connections[request.sid] == "*NOT LOGGED IN*":
        emit("alert", {"data":"Please login first"})
        return
    emit("update_foods", list(filter(lambda x: x["owner"] == connections[request.sid], food_list)))

@socketio.on("delete_food")   
def handle_delete_food(data):
    if not (data['uid']):
        emit("alert", {"data":"Please delete food with a valid json object {uid: 'uid'}"})
        return
    food_list1 = list(filter(lambda x: x["uid"] == data['uid'], food_list))
    if len(food_list1) == 0:
        emit("alert", {"data":"Food with uid "+str(data["uid"])+" does not exist"})
        return
    if food_list1[0]["owner"] != connections[request.sid]:
        emit("alert", {"data":"You do not own food with uid "+str(data["uid"])})
        return
    food_list.remove(food_list1[0])
    emit("message", {"data":"Food with uid "+str(data["uid"])+" deleted successfully"})
    print_socket("Food with uid "+str(data["uid"])+" deleted successfully") 
    handle_get_foods(request.sid) 

@socketio.on("test")
def handle_test(data):
    print_socket("Received test socket request, data:"+str(data))


#Entry point
if __name__ == "__main__":
    socketio.run(app, port=3333, host="0.0.0.0")
