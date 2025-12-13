


# #############################################
# # scanner for bluetooth to get the address 
# ##############################################

# import asyncio
# from bleak import BleakScanner

# async def main():
#     print("🔍 Scanning for BLE devices...")
#     devices = await BleakScanner.discover()

#     if not devices:
#         print("❌ No BLE devices found.")
#         return

#     print("\n📡 Found BLE devices:")
#     for d in devices:
#         print(f"- Name: {d.name}, Address: {d.address}")

# asyncio.run(main())


# import asyncio
# from bleak import BleakClient

# # HM-10 UART characteristic UUID
# UART_UUID = "0000FFE1-0000-1000-8000-00805F9B34FB"

# # CHANGE THIS TO YOUR HM-10 ADDRESS
# ADDRESS = "E128559E-6F91-E6B3-FD39-BE28507ED666"
            

# async def main():
#     print("Connecting to HM-10...")
#     client = BleakClient(ADDRESS)

#     try:
#         await client.connect()
#         print("✓ Connected!")

#         # receive notifications from the robot
#         def callback(sender, data):
#             print("[Robot]:", data.decode(errors="ignore"))

#         await client.start_notify(UART_UUID, callback)

#         # interactive console
#         while True:
#             msg = input("Send: ")
#             await client.write_gatt_char(UART_UUID, (msg + "\n").encode())

#     except Exception as e:
#         print("Error:", e)

#     finally:
#         await client.disconnect()
#         print("Disconnected.")

# asyncio.run(main())











# Connects to both devices 


import asyncio
from bleak import BleakClient

UUID = "0000ffe1-0000-1000-8000-00805f9b34fb"

HM10_A = "E128559E-6F91-E6B3-FD39-BE28507ED666"
HM10_B = None    


async def main():

    print("Connecting...")

    # Connect to HM10_A
    client1 = BleakClient(HM10_A)
    await client1.connect()
    print("✓ Connected to HM10_A")

    # Connect to HM10_B only if address is provided
    client2 = None
    if HM10_B is not None:
        client2 = BleakClient(HM10_B)
        await client2.connect()
        print("✓ Connected to HM10_B")
    else:
        print("⚠ HM10_B address is None — skipping second device.")

    # Callbacks
    def cb1(sender, data):
        print("[HM10_A]:", data.decode(errors="ignore"))

    if client2:
        def cb2(sender, data):
            print("[HM10_B]:", data.decode(errors="ignore"))

    await client1.start_notify(UUID, cb1)

    if client2:
        await client2.start_notify(UUID, cb2)

    # INPUT LOOP — DIFFERENT MESSAGE FOR EACH DEVICE
    while True:
        msg1 = input("Send to A: ")
        await client1.write_gatt_char(UUID, (msg1 + "\n").encode(), response=False)

        if client2:
            msg2 = input("Send to B: ")
            await client2.write_gatt_char(UUID, (msg2 + "\n").encode(), response=False)


asyncio.run(main())
