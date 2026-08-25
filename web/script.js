function controlDevice(device, action) {

    const status = document.getElementById(device + "-status");

    if (action === "on") {

        status.textContent = "ON";

    } else {

        status.textContent = "OFF";

    }

}