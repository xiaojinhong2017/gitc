var fs = require("fs");
var util = require("util");

//rethrow()直接返回err函数
function rethrow(){
  return function(err){
    if(err){
      throw err;
    }
  };
}


//maybecallback函数用来判断readFile中最后一个参数是否为函数，如果是返回此函数，如果不是则返回rethow()这个函数
function maybecallback(cb){
  return util.isFunction(cb)? cb : rethow() ;
}

function assertEncoding(encoding){
  if(encoding&&!Buffer.isEncoding(encoding)){
    throw new Error('Unknow encoding:'+encoding);
  }
}

fs.readFile = function(path,options,callback){
  var callback = maybecallback(arguments[arguments.length-1]);//arguments用来获取最后一个参数

//判断第二个参数的情况，第二个参数可以传字符串，对象也可以省略
  if(util.isFUnction(options)||!options){
   options = {encoding:null,flag:'r'};//如果有第二个参数而且第二个参数是一个函数直接加一上这个变量encoding为空.不用担心会覆盖回调函数，回调函数已经赋给了callback（判断是否是省略第二个参数直接传入callback函数参数）
 }else if(until.isString(options)){
   options = {encoding:options,flag:'r'};//如果第二个参数是个字符串的话直接设置为编码格式的属性值
 }
else if(!until.isObject(options)){
  throw new TypeError('Bad arguments');//如果第二个参数不是个对象则抛出错误
}
var encoding = options.encoding;//提取编码格式的属性值
assertEncoding(encoding);//判断编码格式的属性值是否符合标准如utf8

//读文件需要先打开文件
var fd;
var pos = 0;
var buffer;
var buffers;
var flag = options.flag||'r';//不管有还是没有都加上默认权限
fs.open(path,flag,438,function(er,fd_){
if(er) return callback(er);//callback是自己写的是实现readFile功能中地三个函数参数的参数

fd = fd_;//在全局范围内获得句柄
fs.fstat(fd,function(er,st){
  if(er){
   return fs.close(fd,function(){
     callback(er);
   });
  }
  size = st.size;//获得文件的大小
  if(size === 0){//如果文件为空
    buffers = [];
    return read();
  }
  if(size > kMaxLength){
    var err = new RangeError('Eile size is greater than possible Buffer:' +
  '0X3FFFFFFF bytes');
  return fs.close(fd,function(){
    callback(err);
  });
  }
  buffer = new Buffer(size);
  read();

});
});
 function read(){
   if(size === 0){
     buffer = new Buffer(8192);
     fs.read(fd,buffer,0,8192,-1,afterRead);
   }else{
     fs.read(fd,buffer,pos,size-pos,-1,afterRead);
   }
 }
 function afterRead(er,bytesRead){
   if(er){
     return fs.close(fd,function(er){
       return callback(er);
     });
   }
  if(bytesRead === 0 ) {
    return close();
  }
  pos += bytesRead;
  if(size !== 0){
    if(pos === size) close();
    else read();
  }else{
    buffers.push(buffer.slice(0,bytesRead));
    read();
  }
 }
 function close(){
   fs.close(fd,function(er){
     if(size === 0){
       buffer = Buffer.concat(buffers,pos);
     }else if (pos < size) {
       buffer = buffer.slice(0,pos);
     }
     if(encoding)buffer = buffer.toString(encoding);
     return callback(er,buffer);
   });
 }
};
