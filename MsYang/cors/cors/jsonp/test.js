
var fs = require("fs");
var http = require("http");
var url = require("url");

http.createServer(function(req, res){
	 var queryObj = url.parse(req.url, true).query;
	 /*
	    queryObj = {"callback": "handler"}
	 */

	 console.log(queryObj);

	 fs.readFile("./test.json", function(err, data){
		 //"handler({name:'lisi', age: 10})"
		 res.write(queryObj.callback+ "(" + data  + ")");
		 res.end();
	 });


}).listen(8000);

console.log("监听 127.0.0.1:8000 ...");
