######################
# scanner for bluetooth
#####################

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

# # HM-10 UART characteristic UUID (FFE1)
# UART_UUID = "0000ffe1-0000-1000-8000-00805f9b34fb"

# # YOUR HM-10 ADDRESS FROM THE SCAN
# ADDRESS = "E128559E-6F91-E6B3-FD39-BE28507ED666"

# async def main():
#     print(f"Connecting to HM-10 at {ADDRESS} ...")
#     client = BleakClient(ADDRESS)

#     try:
#         await client.connect()
#         print("✅ Connected to HM-10!")

#         # SEND A MESSAGE
#         msg = "Hello from Python HM-10!"
#         print(f"➡️ Sending: {msg}")
#         await client.write_gatt_char(UART_UUID, msg.encode())

#         # RECEIVE NOTIFICATIONS (IF HM10 SENDS BACK)
#         def callback(sender, data):
#             print(f"📨 Notification from HM-10: {data.decode(errors='ignore')}")

#         print("🔔 Subscribing to notifications...")
#         await client.start_notify(UART_UUID, callback)

#         print("📡 Listening... press CTRL+C to exit.")
#         while True:
#             await asyncio.sleep(1)

#     except Exception as e:
#         print("❌ ERROR:", e)

#     finally:
#         await client.disconnect()
#         print("🔌 Disconnected.")

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




#### Code for Pololu


#include <stdio.h>
#include "pico/stdlib.h"
#include "pololu/3pi_plus_2040_robot.h"

# int main() {
#     stdio_init_all();
#     robot_init();

#     // UART1 → HM-10 BLE
#     uart_init(uart1, 9600);
#     gpio_set_function(4, GPIO_FUNC_UART);  // TX
#     gpio_set_function(5, GPIO_FUNC_UART);  // RX

#     robot_display_clear();
#     robot_display_print("BLE Ready");

#     while (1) {
#         // if HM-10 sent a character
#         if (uart_is_readable(uart1)) {
#             char c = uart_getc(uart1);

#             // show it on OLED
#             robot_display_clear();
#             robot_display_printf("RX: %c", c);

#             // send reply back to Mac
#             uart_puts(uart1, "ECHO: ");
#             uart_putc(uart1, c);
#             uart_puts(uart1, "\n");
#         }
#         sleep_ms(10);
#     }
# }

