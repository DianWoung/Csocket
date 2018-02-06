<?php
$server = new swoole_websocket_server("0.0.0.0", 88);

$server->on('open', function (swoole_websocket_server $server, $request) {
    echo "server: handshake success with fd{$request->fd}\n";
});

$server->on('message', function (swoole_websocket_server $server, $frame) {
	foreach($server->connection_list() as $fd) {
		$server->push($fd, $frame->data,true);
	}
});

$server->on('close', function ($ser, $fd) {
    echo "client {$fd} closed\n";
});

$server->start();