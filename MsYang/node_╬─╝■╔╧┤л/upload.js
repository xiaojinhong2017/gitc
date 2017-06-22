var mime = require('mime');
var http = require('http');
var util = require('util');
var url = require('url');
var fs = require('fs');
var querystring = require('querystring');
var formidable = require("formidable");


var mines = {
    ".css": "text/css",
    ".js": "application/javascript",
    ".png": "image/png",
    ".jpg": "image/jpeg",
    ".gif": "image/gif"
};


var server = http.createServer(function(request, response) {

    // console.log(request.url);
    var pathname = url.parse(request.url).pathname;
    var ext = pathname.match(/(\.[^.]+|)$/)[0];



    /*
     必须对除了html文件以外的其他文件进行处理，否则这些类型文件都无法被
     浏览器正确的解析。
    */
    switch (ext) {
        case ".css":
        case ".js":
        case ".jpg":
        case ".png":
        case ".gif":

            /*
             读取图片文件时，如果设置"utf-8"就会错误，导致图片无法显示。
            */
            fs.readFile("." + request.url, function(err, data) { //读取内容

                console.log("." + request.url);

                if (err) throw err;

                response.writeHead(200, {
                    "Content-Type": mines[ext]
                });
                response.write(data);
                response.end();
            });
            break;
        default:

            if (pathname == "/") {
                fs.readFile('./upload.html', 'utf-8', function(err, data) { //读取内容
                    if (err) throw err;
                    response.writeHead(200, {
                        "Content-Type": "text/html"
                    });
                    response.write(data);
                    response.end();
                });
            } else if (pathname == "/post") {
                var form = new formidable.IncomingForm();

                form.uploadDir = "./uploadpath/";//上传的目录临时路径

                form.parse(request, function(err, fields, files) {

                    console.log("-----" + fields);

                    //files，包含上传到文件信息, "fileUpload是上传时对应的名字"
                    console.log(files.fileUpload);
                    
                    fs.createReadStream(files.fileUpload.path)
                    .pipe(fs.createWriteStream("./uploadfiles/" + Date.now() + "_" + files.fileUpload.name));
                    
                });

            } else {
                response.write("404 NOT FOUND");
                response.end();
            }

    }

}).listen(8080);


console.log("监听 127.0.0.1:8080/");
