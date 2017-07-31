var fs = require('fs');
var data = 'writeFileSync';
var retu = fs.writeFileSync("nihao.md",data,"utf8");//当文件名没有时会新建一个
console.log(retu);//undefined

try{
  fs.writeFileSync("./aaa.md",data,'utf8')
}catch(err){
  console.log(err);
}
