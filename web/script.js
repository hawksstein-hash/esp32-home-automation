const devices = {

    light1: false,
    light2: false,
    fan: false,
    appliance: false

};


// ESP32 IP address
const ESP32_IP = "192.168.15.128";


// Map website devices to ESP32 routes
const deviceRoutes = {

    light1: "light1",
    light2: "relay"

};


async function controlDevice(device, action) {

    const status =
        document.getElementById(device + "-status");

    try {

        // Check whether this device is connected to ESP32
        if (!deviceRoutes[device]) {

            alert(device + " is not connected to ESP32 yet.");

            return;

        }


        // Get the correct ESP32 route
        const espDevice = deviceRoutes[device];


        // Send command to ESP32
        const response = await fetch(
            `http://${ESP32_IP}/${espDevice}/${action}`
        );


        if (!response.ok) {

            throw new Error("ESP32 did not respond");

        }


        // Get response from ESP32
        const message = await response.text();

        console.log("ESP32:", message);


        // Update webpage after ESP32 responds
        if (action === "on") {

            devices[device] = true;

            status.textContent = "ON";

            status.classList.add("status-on");

            status.classList.remove("status-off");

        }

        else {

            devices[device] = false;

            status.textContent = "OFF";

            status.classList.add("status-off");

            status.classList.remove("status-on");

        }


        updateDeviceCount();

    }


    catch (error) {

        console.error("ESP32 connection failed:", error);

        alert("Could not connect to ESP32.");

    }

}


function controlAll(action) {

    for (let device in devices) {

        // Only control devices that are actually connected
        if (deviceRoutes[device]) {

            controlDevice(device, action);

        }

    }

}


function updateDeviceCount() {

    let count = 0;


    for (let device in devices) {

        if (devices[device] === true) {

            count++;

        }

    }


    document.getElementById("devices-on").textContent = count;

}