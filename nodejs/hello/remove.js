var EventEmitter = require('events').EventEmitter;
var server = new EventEmitter();
var callback = function(stream) {
  console.log('someone connected!');
};
var call = function() {
  console.log('someone call');
};
server.on('connection', callback);
server.on('connection', call);
server.removeListener('connection', callback);

setTimeout(function(){
  server.emit("connection");
},1000);
