var express = require('express');
/*引用数据库模块，需要那个引用哪个*/
var users = require('../db/users');


var router = express.Router();



router.post("/",function(req,res,next){
   var data = req.body;
  users.findOne({name:data.username},function(err ,data){
    if(data){
  console.log("------",data);
  res.render('index',{name:'messages',data:data});
}else{

  res.render('index',{name:'messages',data:''});
}
  })

})



module.exports = router;
