var fs = require('fs');
// fs.access('./hello.md',fs.constants.F_OK,function(err){
//   console.log(err? 'no access' : 'can rvw');
// })
//
//
// fs.mkdir("hello1.md",function(err){
//   console.log(err);
// }
// )
// fs.rmdir("hello1.md",function(err){
//   console.log(err? 'yes': 'no');
//
// })
// //stat 文件
// fs.stat("hello.md",function(err,stats){
//   console.log(stats);
// })
// //stat 目录
// fs.stat("../hello",(err,stats) => {
//   if(err) console.log(err);
//   console.log("目录",stats);
// })


//
fs.open("hello.md",'w',(err,fd) =>{
  if(err) console.log(err);
  // console.log(fd);
// var buf = new Buffer(5);
// fs.read(fd,buf,0,10,0,(err,bytesRead,buffer) =>{
//   if(err) console.log(err);
//   console.log('bytesRead'+bytesRead);
//   JSON.parse(buffer);
//   console.log(buffer);
// })
  var buf = '1233e4';
fs.write(fd,buf,0,5,0,(err,bytesWritten,buffer) =>{
  if(err){
    console.log(err);
  }

 console.log('bytesWritten'+bytesWritten);
 console.log(buffer);
})
fs.close(fd,(err)=>{
  if(err) console.log("close" ,err);
  console.log("close success");
})
})
