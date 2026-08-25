const devices = {

    light1: false,
    light2: false,
    fan: false,
    appliance: false

};


function controlDevice(device, action) {

    const status =
        document.getElementById(device + "-status");


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


function controlAll(action) {

    for (let device in devices) {

        controlDevice(device, action);

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