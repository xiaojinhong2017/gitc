var http = require('http');
var query = require('querystring');
var serv = http.createServer(function(req,res){
  // console.log(req.method);
  if(req.url == '/'){
  res.writeHead(200,{'Content-Type':'text/html'});
  res.end(['<h1>Welcome to Node.js!</h1>',
'<form method="POST" action="/url">',
'<fieldset>',
'<label> Personal information </label>',
'<p>Name</p>',
'<input type="text" name="name">',
'<p>Age</p>',
'<input type="text" name="age">',
'<p><button>Submit</button></p>',
'</form>'
].join(' '));
}else if('/url' == req.url&&req.method == 'POST'){
  var str = '';
  req.on('data',function(chunk){
    str += chunk;
    // console.log(chunk);
    console.log(typeof(chunk));//object
    // console.log(typeof(str));
    // console.log(str);
    var st = query.parse(str);
    console.log(st);
    name= st.name;
    age= st.age;

  })
  req.on('end',function(){
  res.writeHead(200,{'Content-Type':'text/html'});
  res.end(['You sent a <em>'+req.method  +'<em> request','<p> data:'+name+'</p>','<p> data:'+age+'</p>'].join(' '));

  })
}else{
  res.writeHead(404);
  res.end('Not found');
}
}).listen(3000);
