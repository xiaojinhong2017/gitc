var app = require('express')();
var server = require('http').Server(app);
var io = require("socket.io")(server);
server.listen(3000);
app.get('/',function(req,res){
  res.sendFile(__dirname +'/index.html');
});
io.on('connection',function(socket){
  console.log("a user connected!");
  socket.emit('news',{hello:"world"});
  socket.on("other",function(data){
    console.log(data);
  })
})
