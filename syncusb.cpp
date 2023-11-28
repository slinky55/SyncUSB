//
// Created by slinky on 11/27/23.
//

#include "syncusb.h"

#include <vector>
#include <iostream>
#include <string>
#include <map>

namespace susb {

    libusb_context* ctx;

    std::vector<libusb_device_handle*> openDevices;

    const std::map<int, std::string_view> speeds = {
            {LIBUSB_SPEED_UNKNOWN, "Unknown"},
            {LIBUSB_SPEED_LOW, "Low"},
            {LIBUSB_SPEED_FULL, "Full"},
            {LIBUSB_SPEED_HIGH, "High"},
            {LIBUSB_SPEED_SUPER, "Super"},
            {LIBUSB_SPEED_SUPER_PLUS, "Super Plus"}
    };

    int start() {
      libusb_init(&ctx);

      libusb_device** deviceList;

      size_t numDevices = libusb_get_device_list(ctx, &deviceList);

      std::cout << "USB Devices Found: " << numDevices << "\n";
      std::cout << "-------------------------\n\n";

      for (int i = 0; i < numDevices; i++) {
        libusb_device* device = deviceList[i];
        uint8_t port = libusb_get_port_number(device);
        int speed = libusb_get_device_speed(device);

        std::cout << "Device " << i + 1 << "\n";
        std::cout << "Port: " << static_cast<int>(port) << "\n";
        std::cout << "Speed: " << speeds.at(speed) << "\n\n\n";
      }

      libusb_free_device_list(deviceList, 0);

      libusb_exit(ctx);
      return 0;
    }
}