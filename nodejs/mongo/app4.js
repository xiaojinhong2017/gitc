var http = require('http');
var MongoClient = require('mongodb').MongoClient;
var assert = require('assert');
var fs = require('fs');
var query = require('querystring');
var url = 'mongodb://localhost:27017/test';
var a = http.createServer(function(req, res){
  if('/success === req.url'){
    var str1 = '';
    req.on("data",function(str){
      str1 += str;
      console.log(str1);
      if(query.parse(str1).username&&query.parse(str1).passwd)
      {

            var mydbInit = function(db,callback){
              db.collection('stunum').insertOne({"name":query.parse(str1).username,"passwd":query.parse(str1).passwd},function(err,result){
              assert.equal(err,null);
              console.log(("Inserted a document into the stunum collection"));
              // var cursor = db.collection('stunum').find();
              // cursor.each(function(err,doc){
              //   assert.equal(err,null);
              //   if(doc){
              //     console.log(doc);
              //   }else{
              //     callback();
              //   }
              // })
            });

            }
            MongoClient.connect(url,function(err,db){
              assert.equal(null,err);
               console.log("connected correctly to server.");
               mydbInit(db,function(){
                 console.log("init ok");
                 db.close();
               })
            })
      req.on("end",function(){
      res.writeHead(200,{'Content-Type':'text/html'});
      res.end(["<meta charset = 'UTF-8'><h1>注册成功</h1>"].join(" "));
    });

      }
    })
  }
  if('/' === req.url){
    //res.writeHead(200, {'Content-Type': 'text/html'});
    fs.readFile('./index.html', function(err, file){
      if(err){
        res.write('Error for 404!');
        res.end('');
      }else{
        res.write(file);

        res.end();
      }
    });

    // req.on("end",function(){
    //
    //   res.writeHead(200,{'Content-Type':'text/html'});
    //   res.end(["<meta charset = 'UTF-8'><h2>数据提交成功</h2><p>name = "+ query.parse(str1).username+"</p><p>age = "+query.parse(str1).passwd+"</p>"].join(" "));
    // });
  }else if(req.url == "/url"){
    var str1 = '';
    req.on("data",function(str){
      str1 += str;
    // req.on("end",function(){
    //
    //   res.writeHead(200,{'Content-Type':'text/html'});
    //   res.end(["<meta charset = 'UTF-8'><h2>数据提交成功</h2><p>name = "+ query.parse(str1).username+"</p><p>age = "+query.parse(str1).passwd+"</p>"].join(" "));
    // });


})
req.on("end",function(){

  res.writeHead(200,{'Content-Type':'text/html'});
  res.end(["<meta charset = 'UTF-8'><h2>数据提交成功</h2><p>name = "+ query.parse(str1).username+"</p><p>age = "+query.parse(str1).passwd+"</p>"].join(" "));
});

}else if(req.url == "/forget.html"&&req.method == "POST"){
  fs.readFile('./forget.html', function(err, file){
  if(err){
    res.write('Error for 404!');
    res.end('');
  }else{
    res.write(file);
    res.end();
  }
});
}
else if(req.url == "/zhuce.html"&&req.method == "POST"){
  fs.readFile('./zhuce.html', function(err, file){
  if(err){
    res.write('Error for 404!');
    res.end('');
  }else{
    res.write(file);
    res.end();
  }
});
}

}).listen(3000);
console.log('server: localhost:3000');
