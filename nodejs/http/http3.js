var http = require('http');
var fs = require('fs');
var query = require('querystring');
var a = http.createServer(function(req, res){
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
  }else if(req.url == "/url"){
    var str1 = '';
    req.on("data",function(str){
      str1 += str;

//       if(/button2/.test(str1)){
//       fs.readFile('./zhuce.html', function(err, file){
//       if(err){
//         res.write('Error for 404!');
//         res.end('');
//       }else{
//         res.write(file);
//         res.end();
//       }
//     });
// } else{
    //   fs.readFile('./denglu.html', function(err, file){
    //   if(err){
    //     res.write('Error for 404!');
    //     res.end('');
    //   }else{
    //     res.write(file);
    //     res.end();
    //   }
    // });

    req.on("end",function(){

      res.writeHead(200,{'Content-Type':'text/html'});
      res.end(["<meta charset = 'UTF-8'><h2>数据提交成功</h2><p>name = "+ query.parse(str1).username+"</p><p>age = "+query.parse(str1).passwd+"</p>"].join(" "));
    });
  })
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
