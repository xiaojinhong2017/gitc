/**
 * Created by 007 on 2017/4/5.
 */


var express = require('express');
var bodyParser = require('body-parser');
var handlebars = require('express3-handlebars');


var app = express();
app.use(express.static(__dirname + "/public"));

app.use(bodyParser.urlencoded({extended: false}));

app.get("/login", function(req, res, next){

    res.status(200);
    // res.send(req.query);
    res.send("Hello I am server ...");
});


app.use(function (req, res, next) {
    res.status(404);
    res.send("Not Found...");
});


app.listen(8000, function () {
    console.log("listen 127.0.0.1:8000 ... "); 
});
