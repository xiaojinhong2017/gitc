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
    })
  }else if(req.url == "/url"){
    var str1 = '';
    req.on("data",function(str){
      str1 += str;
      var data = "name ="+query.parse(str1).username+"  passwd ="+query.parse(str1).passwd;
      fs.writeFile("./hello.md",data,'utf8',function(err){
        if(err){
          console.log(err);
        }
      })
})
req.on("end",function(){

  res.writeHead(200,{'Content-Type':'text/html'});
  res.end(["<meta charset = 'UTF-8'><h2>数据提交成功</h2><p>name = "+ query.parse(str1).username+"</p><p>age = "+query.parse(str1).passwd+"</p>"].join(" "));
})
}
}).listen(3000);
console.log('server: localhost:3000');
