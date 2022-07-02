const express = require("express");
const path = require("path");
var state = "on";
const app = express();
const cors = require("cors");
const python = require("child_process").spawn("python", ["serial_com5.py"]);
//Lis les sorties :
python.stdout.on("data", (data) => {
    console.log("Python Message (in node): ", data.toString());
});

python.on("close", () => {
    console.log("Python program closed");
});

function create_view_path(fileName) {
    return path.join(__dirname, "views", fileName);
}

function sendMessageToArduino(message) {
    python.stdin.write(message + "\n");
    //python.stdin.end();
}

app.use(express.static(create_view_path("")));
app.use(cors());

app.get("/", (req, res) => {
    res.sendFile(create_view_path("switch.html"));
});
app.get("switch.js", (req, res) => {
    res.sendFile(__dirname + "/views/switch.js");
});
app.get("switch.css", (req, res) => {
    res.render(__dirname + "/views/switch.css");
});
app.get("/command", (req, res) => {
    if (req.query.state) {
        if (req.query.state == "on") state = "on";
        else state = "off";
        sendMessageToArduino(state);
        res.send("success");
    } else res.send("failure");
});

app.get("/state", cors(), (req, res) => {
    res.send(state);
});

module.exports = app;
