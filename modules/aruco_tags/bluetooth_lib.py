


#############################################
# scanner for bluetooth to get the address 
##############################################

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


import asyncio
from bleak import BleakClient

# HM-10 UART characteristic UUID
UART_UUID = "0000FFE1-0000-1000-8000-00805F9B34FB"

# CHANGE THIS TO YOUR HM-10 ADDRESS
ADDRESS = "E128559E-6F91-E6B3-FD39-BE28507ED666"
            

async def main():
    print("Connecting to HM-10...")
    client = BleakClient(ADDRESS)

    try:
        await client.connect()
        print("✓ Connected!")

        # receive notifications from the robot
        def callback(sender, data):
            print("[Robot]:", data.decode(errors="ignore"))

        await client.start_notify(UART_UUID, callback)

        # interactive console
        while True:
            msg = input("Send: ")
            await client.write_gatt_char(UART_UUID, (msg + "\n").encode())

    except Exception as e:
        print("Error:", e)

    finally:
        await client.disconnect()
        print("Disconnected.")

asyncio.run(main())
