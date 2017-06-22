
importScripts("./fun.js");
sayHello();

// console.log(this);

//不能进行DOM操作，

var start ;
//接收主线程的数据
this.onmessage = function (event) {
  console.log("接收来自主线程的任务 :", event.data);
  start = event.data;
}


//给主线程发送数据
setInterval(function() {

  //postMessage是发送方法，参数只有一个，是任何类型
  postMessage({
    num: ++start
  });
}, 1000);
