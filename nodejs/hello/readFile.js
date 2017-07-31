 var fs = require('fs');
 fs.readFile('./hello.md' ,'utf8',function(err,data){
   if(err){
     console.log(err);
   }else{
     console.log("read:",data);
   }
 });
 console.log("read file end");
 var data = "This is write file1.";
 fs.writeFile("./hello.md",data,'utf8',function(err){
   if(err){
     console.log(err);
   }
 });

 var data1 = "This is write file2.";
 fs.writeFile("./hello.md",data1,'utf8',function(err){
   if(err){
     console.log(err);
   }
 });
