var express = require("express");
var bodyParser = require('body-parser');
var app = express();
// var routes = require('./routes/route.js')(app);
app.set("views",__dirname + "/views");
app.set("view engine","ejs");
app.use(bodyParser.json({limit: '1mb'}));  //body-parser 解析json格式数据
app.use(bodyParser.urlencoded({            //此项必须在 bodyParser.json 下面,为参数编码
  extended: true
}));
var info = [{name:"zhangsan",age:23,sex:"man"},{name:"lisi",age:34,sex:"feman"},{name:"zhaosi",age:32,sex:"man"}];
app.get("/",function(req,res){
  res.render('index.ejs',{name:"lisi",info:info});
})
app.get("/submit",function(req,res){
  console.log(req.query);
  res.send(req.query);
})
app.post('/submit',function(req,res){
  console.log(req.body.name);
  res.send(req.body.name);
})
// app.use(express.static(__dirname + '/public'));
// app.get(/.*fly$/,function(req,res){
//   // res.send('/.*fly$/');
//   res.redirect("/");
// })
app.listen(3000);
