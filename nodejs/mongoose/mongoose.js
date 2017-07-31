var mongoose = require('mongoose');
var url = 'mongodb://mydb:1234@ds153412.mlab.com:53412/xiaojinhong';
mongoose.connect(url);
var db = mongoose.connection;
db.on('error',function(){
  console.log("Connect error");
})
db.once('open',function(){
 console.log("mongoose working!!!");
})
var Schema = mongoose.Schema;
var userSchema = new Schema({
  name:String,
  age:Number,
  DOB:Date,
  isAlive:Boolean
});
var User = mongoose.model('Pass',userSchema);
var arvind = new User({
  name: 'David',
  age:23,
  DOB:'01/01/1999',
  isAlive:true
});
arvind.save(function(err,data){

})
