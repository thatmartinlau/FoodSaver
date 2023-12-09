# !!! Due to "match" is used, Python 3.10+ is required !!! Or you can change match-status to if-elif on your own

import asyncio
import websockets
import msgpack

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
