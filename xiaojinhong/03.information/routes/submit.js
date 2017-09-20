var express = require('express');
/*引用数据库模块，需要那个引用哪个*/
var users = require('../db/users');


var router = express.Router();



router.post("/",function(req,res,next){
   var data = req.body;
   var user = new users({
    name:data.username,
    age:data.age,
    sex:data.optionsRadios,
    email:data.email,
    birth:data.birth
   })
   user.save(function(err,suc){
     if(suc){
  res.render('submit',{data : data});
     }
   })

})



module.exports = router;
