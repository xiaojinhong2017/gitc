var http = require('http');
var serv = http.createServer(function(req,res){
  res.writeHead(200,{'Content-Type':'text/html'});
  res.end('<h1>welcome to node.js!!</h1>');
}).listen(3000);
