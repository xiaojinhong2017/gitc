module.exports = function(app){
  app.get('/',function(req,res){
    res.send("hello world");
  })

  app.get('/doc',function(req,res){
    res.send("doc world");
  })
  app.get('/admin',function(req,res){
    res.send("admin page");
  })
}
