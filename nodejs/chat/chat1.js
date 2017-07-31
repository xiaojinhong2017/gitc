var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
app.get('/',function(req,res){
  res.sendFile(__dirname + '/chat1.html');
})
io.on('connection',function(socket){
  socket.broadcast.emit('broadcast');
  socket.on("chat message",function(msg1,msg2){
    console.log(msg2);
    io.emit('chat message',msg1,msg2);
  })
})
http.listen(3000,function(){
  console.log("listening on *:3000");
})
