var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
app.get('/',function(req,res){
  res.sendFile(__dirname + '/ferret.html');
})
io.on('connection',function(socket){
  socket.broadcast.emit('broadcast');
  socket.on("chat message",function(msg,cb){
    if(msg){
      cb();
    }
    io.emit('chat message',msg);
  })
})
http.listen(3000,function(){
  console.log("listening on *:3000");
})
