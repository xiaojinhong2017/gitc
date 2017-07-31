importScripts("./fun.js");//可以引入外部文件
sayHello();//外部文件中的函数
console.log(this);
//不能进行dom操作
var start;
this.onmessage = function(event){
  console.log("接收来自主线程的任务：",event.data);
  start = event.data;
}
setInterval(function(){
  //postMessage是发送方法，参数只有一个，是任何类型
  postMessage({
    num:++start
  });
},1000);
