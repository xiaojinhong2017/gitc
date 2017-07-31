// node.js的优缺点
//
// 优点：
//
// 　　　1. 采用事件驱动，异步编程，为网络服务而设计。
//
// 　　　2. node.js非阻塞模式的IO处理给node.js带来在相对较低的资源耗用下的高性能与出众的负载能力。
//
// 　　　3. node.js轻量高效，可以认为是数据密集型实时应用系统的完美解决方案。
//
// 　　　4. js语言适合前端工程师上手。
//
// 　　　5. 社区活跃发展速度快。
//
// 缺点：
//
// 　　　1. 单线程，单进程，只支持单核CPU，不能充分的利用多核CPU服务器。
//
// 　　　2. 对程序员要求高一旦进程崩溃，那么整个web服务器就崩溃了。
//
// 　　　3. 不适合做复杂性很高的计算。
var http = require('http');
var serv = http.createServer(function(req, res){
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end('<h1>Hello nihao??</h1>');
});
    // console.error("error");
    // console.log("nihao");
    // console.error(new Error('错误信息'));
    // console.warn('警告${name}');
    const out = getStreamSomehow();
    const err = getStreamSomehow();
    const myConsole = new console.Console(out,err);
    myConsole.log('你好世界');
    myConsole.log('你好%s','世界');
    // myConsole.error(new Error('错误信息'));
    const name = '描述';
    console.warn(`警告${name}`);
serv.listen(3000);
