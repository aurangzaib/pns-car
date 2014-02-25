var serialport = require('serialport'),
	app = require('express')(),
	server = require('http').createServer(app),
	serial = new serialport.SerialPort('/dev/ttyACM0', {
		baudrate: 9600,
	}),
	value = 0x00,
	port = 8080;
server.listen(port);
//
// SELF INVOKING FUNCTION
//
(function () {
	console.log('\n\npns server running\n\n');
})();
app.get('/', function (request, response) {
	response.sendfile(__dirname + '/pns-car.html');
});
//
// FORWARD
//
app.get('/forward', function (request, response) {
	serial.write(new Buffer([0x00]));
	console.log('forward');
	response.end();
});
//
// REVERSE
//
app.get('/reverse', function (request, response) {
	serial.write(new Buffer([0x11]));
	response.end();
});
//
// STOP
//
app.get('/stop', function (request, response) {
	serial.write(new Buffer([0x01]));
	console.log('stop');
	response.end();
});
//
// FORWARD RIGHT
//
app.get('/right-forward-down', function (request, response) {
	console.log('right-forward-down');
	serial.write(new Buffer([0x02]));
	response.end();
});
app.get('/right-forward-up', function (request, response) {
	console.log('right-forward-up');
	serial.write(new Buffer([0x03]));
	response.end();
});
//
// FORWARD LEFT
//
app.get('/left-forward-down', function (request, response) {
	console.log('left-forward-down');
	serial.write(new Buffer([0x04]));
	response.end();
});
app.get('/left-forward-up', function (request, response) {
	console.log('left-forward-up');
	serial.write(new Buffer([0x05]));
	response.end();
});
//
// REVERSE RIGHT
//
app.get('/right-reverse-down', function (request, response) {
	console.log('right-reverse-down');
	serial.write(new Buffer([0x06]));
	response.end();
});
app.get('/right-reverse-up', function (request, response) {
	console.log('right-reverse-up');
	serial.write(new Buffer([0x07]));
	response.end();
});
//
// REVERSE LEFT
//
app.get('/left-reverse-down', function (request, response) {
	serial.write(new Buffer([0x08]));
	console.log('left-reverse-down');
	response.end();
});
app.get('/left-reverse-up', function (request, response) {
	serial.write(new Buffer([0x09]));
	console.log('left-reverse-up');
	response.end();
});
