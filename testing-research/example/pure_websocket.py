import asyncio
import websockets

async def echo(websocket):
    async for message in websocket:
        message = '''"'''+ message + '''", roger by server'''
        await websocket.send(message)
        print(message)

async def main():
    async with websockets.serve(echo, "0.0.0.0", 3333):
        print("Server started at port 3333")
        await asyncio.Future()

asyncio.run(main())
