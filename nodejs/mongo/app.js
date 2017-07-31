var MongoClient = require('mongodb').MongoClient;
var assert = require('assert');

var url = 'mongodb://127.0.0.1:27017/test';
var findDB = function(db,callback){
  var cursor = db.collection('stunum').find({"name":"zhangsan"});
  cursor.each(function(err,doc){
    assert.equal(err,null);
    if(doc){
      console.log(doc);
    }else{
      callback();
    }
  });
}
MongoClient.connect(url,function(err,db){
  assert.equal(null,err);
  console.log('connected correctly to server.');
  findDB(db,function(){
    db.close();
  })
})
