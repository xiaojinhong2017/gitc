var mongoose = require("./mongoose");

var Schema = mongoose.Schema;
var userSchema = new Schema({
    name:String,
    age:Number,
    sex:String,
    email:String,
    birth:String

});
var users =  mongoose.model("users",userSchema);


module.exports = users;
