const mongoose = require('mongoose');
const url = 'mongodb://mydb:asdfgh@ds151702.mlab.com:51702/mydb';

mongoose.connect(url);
let db = mongoose.connection;
db.once('open',function(){
  console.log('connect db ok !');
})
let Schema = mongoose.Schema;
let userSchema = Schema({
  name:{type:String},
  password:{type:String}
});
module.exports.use = mongoose.model('login',userShema);
