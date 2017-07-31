var fs = require('fs');
var data = fs.readFileSync('hello.md','utf8')
console.log(data);
console.log("read file end");
