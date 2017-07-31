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
 var animalSchema = new Schema({name:String,type:String});
 animalSchema.methods.findSimilarTypes = function(cb){
   return this.model('Animal').find({type:this.type},cb);
 }







 // var Animal = mongoose.model('Animal',animalSchema);
 //var dog = new Animal({name:'Fido',type:'dog'});
 // dog.save(function(){
 //   dog.findSimilarTypes(function(err,dogs){
 //     console.log(dogs);
 //   })
 // });

 animalSchema.statics.findByName = function(name,cb){
   return this.find({name:new RegExp(name,'i')},cb);
 }

 var Animal = mongoose.model('Animal',animalSchema);
 // var dog = new Animal({name:'Fido',type:'dog'});
 Animal.findByName('Fido',function(err,animal){
   console.log(animal);
 })

 // dog.findByName('Fido',function(err,animal){
 //   console.log(animals);
 // })
