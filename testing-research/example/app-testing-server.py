# !!! Due to "match" is used, Python 3.10+ is required !!! Or you can change match-status to if-elif on your own

import asyncio
import websockets
import msgpack

TEST_FRIDGE = [[0, 333, 'Apple', 1702105229, 1702710029, 604800, 0],
 [1, 333, 'Banana', 1702105229, 1702710029, 604800, 0],
 [2, 333, 'Pear', 1702105229, 1702710029, 604800, 0],
 [3, 333, 'Grape', 1702105229, 1702710029, 604800, 0],
 [4, 333, 'Orange', 1702105229, 1702710029, 604800, 0],
 [5, 333, 'Peach', 1702105229, 1702710029, 604800, 0],
 [6, 333, 'Cherry', 1702105229, 1702710029, 604800, 0],
 [7, 333, 'Mango', 1702105229, 1702710029, 604800, 0],
 [8, 333, 'Watermelon', 1702105229, 1702710029, 604800, 0],
 [9, 333, 'Blueberry', 1702105229, 1702710029, 604800, 0],
 [10, 333, 'Strawberry', 1702105229, 1702710029, 604800, 0],
 [11, 333, 'Kiwi', 1702105229, 1702710029, 604800, 0],
 [12, 333, 'Pineapple', 1702105229, 1702710029, 604800, 0],
 [13, 333, 'Papaya', 1702105229, 1702710029, 604800, 0],
 [14, 333, 'Coconut', 1702105229, 1702710029, 604800, 0],
 [15, 333, 'Avocado', 1702105229, 1702710029, 604800, 0]]

def print_socket(d): #To print socket logs in green background
    print('\x1b[6;30;42m'+"[WEBSOCKET] "+d+'\x1b[0m')

def print_socket_red(d): #To print socket logs in red background
    print('\x1b[6;30;41m'+"[WEBSOCKET] "+d+'\x1b[0m')

async def echo(websocket):
    async for message in websocket:
        try:
            print_socket("New message received: "+str(message))
            message = msgpack.unpackb(message)
            print_socket("Requested function: "+str(message["func"]))
            match message["func"]:
                case "userLogin":
                    await handleLogin(websocket, message["payload"])
                case "ping":
                    await websocket.send(msgpack.packb({"func": "ping", "payload": {"message": "pong"}}))
                case "updateFridge":
                    await websocket.send(msgpack.packb({"func": "updateFridge", "payload": TEST_FRIDGE}))
                case _:
                    await websocket.send(msgpack.packb({"func": "error", "payload": {"message": "Unknown function"}}))
        except BaseException as err:
            print_socket_red("Error in unpacking message: "+str(err))
            await websocket.send(msgpack.packb({"func": "error", "payload": {"message": "Server-side error, check server terminal for more information"}}))
            
async def handleLogin(websocket, payload):
    print_socket("UserLogin request received")
    if payload["username"] == "test" and payload["password"] == "test":
        print_socket("Login success")
        await websocket.send(msgpack.packb({"func": "userLoginSuccess", "payload": {"username": str(payload["username"])}}))
    else:
        print_socket_red("Login failed")
        await websocket.send(msgpack.packb({"func": "userLoginFail", "payload": {"message": "Wrong username or password"}}))

async def main():
    async with websockets.serve(echo, "0.0.0.0", 3333):
        print("Server started at port 3333")
        await asyncio.Future()

asyncio.run(main())
