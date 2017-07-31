var EventEmitter = require('events').EventEmitter;
var event = new EventEmitter();
event.on('some_event',function(){
  console.log('some event occured 1');
});
event.on('some_ev',function(){
  event.emit("some_event");
});
event.once('some',function(){
  console.log("hello.....");
});
// event.removeListener("some_ev",function(){
//   console.log("remove sussess");
// });
setTimeout(function(){
  event.emit('some_ev');
},1000);
// setInterval(function(){
//   event.emit('some');
// },1000);
// console.log(__filename);
// console.log(__dirname);
