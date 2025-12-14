# Connects to both devices 


import asyncio
from bleak import BleakClient

UUID = "0000ffe1-0000-1000-8000-00805f9b34fb"

HM10_A = "77F101C0-5D65-0C2D-23CC-728BCD3C06F4"
HM10_B = None # "E128559E-6F91-E6B3-FD39-BE28507ED666"


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
