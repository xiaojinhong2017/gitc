var MongoClient = require('mongodb').MongoClient;
var assert = require('assert');
var url = 'mongodb://127.0.0.1:27017/test';

var mydbInit = function(db,callback){
  db.collection('stunum').insertOne({"address":{"street":"2 Avenue",
"zipcode":"10075","building":"1480","coord":[-73.9558749,40.9890]},
"borough":"Manhattan","cuisine":"Italian","name":"Vella"},function(err,result){
  assert.equal(err,null);
  console.log(("Inserted a document into the stunum collection"));
  var cursor = db.collection('stunum').find();
  cursor.each(function(err,doc){
    assert.equal(err,null);
    if(doc){
      console.log(doc);
    }else{
      callback();
    }
  })
});

}
MongoClient.connect(url,function(err,db){
  assert.equal(null,err);
   console.log("connected correctly to server.");
   mydbInit(db,function(){
     console.log("init ok");
     db.close();
   })
})
