var express = require('express');
/*引用数据库模块，需要那个引用哪个*/
var users = require('../db/users');


var router = express.Router();



router.get("/",function(req,res,next){
  res.render('index',{name:'messages' ,data:''});

})



module.exports = router;
