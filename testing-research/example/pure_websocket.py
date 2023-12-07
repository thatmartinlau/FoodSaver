import asyncio
import websockets

async def echo(websocket):
    async for message in websocket:
        await websocket.send(message)
        print(message)

async def main():
    async with websockets.serve(echo, "localhost", 3333):
        print("Server started at port 3333")
        await asyncio.Future()

asyncio.run(main())
