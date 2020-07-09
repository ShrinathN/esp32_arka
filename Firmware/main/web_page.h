#ifndef WEB_PAGE_H
#define WEB_PAGE_H

const char error_response[] = "HTTP/1.1 404 Not Found\nConnection: close\n\n";

const char event_response[] = "HTTP/1.1 200 OK\nContent-Type: text/event-stream;charset=UTF-8\nTransfer-Encoding: identity\n\ndata: ";

const char page_data[] = "<html>\n\n<head>\n<title>ESP32 Solar Manager</title>\n<style>\nbody {\nbackground-color: rgb(151, 234, 255);\n}\n\nh1 {\nfont-size: 250%;\n}\n\nbutton {\nborder-radius: 10px;\n}\n\ninput.text {\nborder-radius: 2px;\n}\n\ntable {\nbackground-color: silver;\n}\n\nth {\nfont-size: 30px;\n}\n\ntr {\nfont-size: 30px;\n}\n\ntd {\nfont-size: 30px;\n}\n</style>\n</head>\n\n<body>\n<center>\n<h1>ESP32 Solar Manager</h1>\n<table border=\"1px\">\n<tr>\n<th>Raw</th>\n<td id=\"raw_value\">0</td>\n</tr>\n<tr>\n<th>Volts</th>\n<td id=\"voltage_value\">0</td>\n</tr>\n</table><br><br>\n<button onclick=\"adjust_multiplier()\"><b>Adjust Multiplier</b></button>\n</center>\n</body>\n<script>\nvar multiplier = 0.001;\nfunction adjust_multiplier() {\nmultiplier = Number.parseFloat(prompt(\"New Multiplier\"));\n}\nfunction conn() {\nvar event_connection = new EventSource(\"/\");\nconsole.log(\"SET!\");\nevent_connection.onmessage = function (event) {\nvar val = Number.parseFloat(event.data);\nvar raw_value = document.getElementById(\"raw_value\");\nvar voltage_value = document.getElementById(\"voltage_value\");\nraw_value.innerText = val;\nvoltage_value.innerText = val * multiplier;\n};\n}\nwindow.setTimeout(conn, 1000);\n</script>\n\n</html>";

#endif
