#ifndef WEB_PAGE_H
#define WEB_PAGE_H

const char error_response[] = "HTTP/1.1 404 Not Found\nConnection: close\n\n";

const char event_response[] = "HTTP/1.1 200 OK\nContent-Type: text/event-stream;charset=UTF-8\nTransfer-Encoding: identity\n\ndata: ";

const char page_data[] = "HTTP/1.1 200 OK\nContent-type: text/html\nConnection: close\n\n<html><head><title>ESP32 Solar Manager</title><style>body {background-color: rgb(151,234,255);}h1 {font-size: 250%;}button {border-radius: 10px;}input.text {border-radius: 2px;}table {background-color: silver;}th {font-size: 30px;}tr {font-size: 30px;}td {font-size: 30px;}</style></head><body><center><h1>ESP32 Solar Manager</h1><table border=\"1px\"><tr><th>Raw</th><td id=\"raw_value\">0</td></tr><tr><th>Voltage</th><td id=\"voltage_value\">0</td></tr></table></center></body><script>function conn(){var event_connection = new EventSource(\"/\");console.log(\"SET!\");event_connection.onmessage = function(event){var val=Number.parseInt(event.data);var raw_value=document.getElementById(\"raw_value\");var voltage_value=document.getElementById(\"voltage_value\");raw_value.innerText = val;voltage_value.innerText = val / 1000;};};window.setTimeout(conn, 1000);</script></html>";

#endif
