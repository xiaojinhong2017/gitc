var http = require("http");
var express = require("express");
var bodyParser = require("body-parser");
var cookieParser = require("cookie-parser");

var app = express();
app.use(express.static(__dirname + "/public"));
app.use(cookieParser());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));


app.post("/data", function(req, res, next){
	console.log("------receive from client -----");
	console.log(req.body);
	res.status(200);
	res.json({'name': 'lisi', 'age':10});
});


var server = http.createServer(app);
server.listen(8888, function(){
	console.log("listen 127.0.0.1:8888 ....");
});
