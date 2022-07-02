let body = document.querySelector("body");
let button_div = document.createElement("div");
button_div.innerHTML = "on";
button_div.setAttribute("id", "button");
button_div.classList.add("green");
body.append(button_div);

function switch_state(new_state) {
    if (new_state !== button_div.innerHTML) {
        if (new_state == "off") {
            button_div.innerHTML = "off";
            button_div.classList.remove("green");
            if (!button_div.classList.contains("red"))
                button_div.classList.add("red");
        } else {
            button_div.innerHTML = "on";
            button_div.classList.remove("red");
            if (!button_div.classList.contains("green"))
                button_div.classList.add("green");
        }
    }
}

function refresh() {
    fetch("http://192.168.1.7:3000/state")
        .then((res) => res.text())
        .then((text) => switch_state(text))
        .catch((err) => {});
}
refresh();

button_div.addEventListener("click", () => {
    let new_state = button_div.innerHTML == "on" ? "off" : "on";
    console.log(new_state);
    fetch("http://192.168.1.7:3000/command?state=" + new_state)
        .then((res) => res.text())
        .then((text) => {
            if (text === "success") switch_state(new_state);
        });
});
setInterval(refresh, 2000);
