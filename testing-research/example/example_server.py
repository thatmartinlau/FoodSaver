from flask import Flask, request, send_from_directory, redirect, send_file, jsonify
from flask_socketio import SocketIO, send, emit

app = Flask(__name__)
app.config['SECRET_KEY'] = 'KEY'
app.config
socketio = SocketIO(app)    
connection_ids = [] #List of all connected clients
user_list = {}  #Simplified user list, contains only username and password
#!!!DO NOT USE USERNAME TO CHECK ANYTHING EXCEPT FOR LOGGING IN WHILE IN PRODUCTION, GENERATE A uid INSTEAD!!!
#SUGGESTIONS: Store encrypted passwords in database, e.g. in database store salt & SHA1(SHA1(password)+salt)

def print_socket(d): #To print socket logs in green background
    print('\x1b[6;30;42m'+"[WEBSOCKET] "+d+'\x1b[0m')

def print_socket_red(d): #To print socket logs in red background
    print('\x1b[6;30;41m'+"[WEBSOCKET] "+d+'\x1b[0m')


#HTTP events
@app.route('/', methods=["GET"])
def testpageindex(): #Serve index.html
    return send_file("include/index.html")


#SocketIO events
@socketio.on("connect")
def handle_connect():
    connection_ids.append(request.sid)
    print_socket("Connection established, id:"+str(request.sid))
    print_socket("Current connections:"+str(connection_ids))
    emit("message", {"data":"Hello from server, your id is:"+str(request.sid)})

@socketio.on("disconnect")
def handle_disconnect():
    connection_ids.remove(request.sid)
    print_socket_red("Connection lost, id:"+str(request.sid))
    print_socket_red("Current connections:"+str(connection_ids))

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
    emit("message", {"data":"User "+str(data["username"])+" logged in successfully"})

@socketio.on("test")
def handle_test(data):
    print_socket("Received test socket request, data:"+str(data))


#Entry point
if __name__ == "__main__":
    socketio.run(app, port=3333, host="0.0.0.0")
