#############################################
# scanner for bluetooth to get the address 
##############################################

import asyncio
from bleak import BleakScanner

async def main():
    print("🔍 Scanning for BLE devices...")
    devices = await BleakScanner.discover()

    if not devices:
        print("❌ No BLE devices found.")
        return

    print("\n📡 Found BLE devices:")
    for d in devices:
        print(f"- Name: {d.name}, Address: {d.address}")

asyncio.run(main())
