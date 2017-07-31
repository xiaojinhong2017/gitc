var MongoClient = require('mongodb').MongoClient;
var assert = require('assert');
var url = 'mongodb://localhost:27017/test';
var removetDB = function(db,callback){
  db.collection('stunum').deleteMany({"name":"Vella"},function(err,results){
    console.log(results);
    callback();
  })
}
MongoClient.connect(url,function(err,db){
  assert.equal(null,err);
  console.log("connected correctly to server");
  removetDB(db,function(){
    db.close();
  });
});
